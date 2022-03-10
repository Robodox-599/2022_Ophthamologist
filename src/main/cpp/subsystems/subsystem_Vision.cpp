// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/subsystem_Vision.h"

subsystem_Vision::subsystem_Vision() : m_data_ready(false), m_print_data(false), m_validSerialPort(false), m_uart(9600)
{
  m_proc_buffer.reserve(BUFFER_SIZE); // Preallocate what we think the maximum size of the string needs to be
                                      // C++ standard allows the string to grow beyond this if needed up to std::string.max_size()
  printf("Opening Serial Port...\n");

  // checks each serial port to see which one is connected
  frc::SerialPort::Port ports[3];
  ports[0] = frc::SerialPort::kUSB;
  ports[1] = frc::SerialPort::kUSB1;
  ports[2] = frc::SerialPort::kUSB2;

  for (int i = 0; i < 3; ++i)
  {
    try
    {
      // m_uart = frc::SerialPort(115200, frc::SerialPort::kUSB2, 8, frc::SerialPort::kParity_None, frc::SerialPort::kStopBits_One);
      m_uart = frc::SerialPort(115200, ports[i], 8, frc::SerialPort::kParity_None, frc::SerialPort::kStopBits_One);
      m_uart.Reset();

      m_validSerialPort = true;
      printf("SUCCESS port# %d\n", i);
      break;
    }
    catch (const std::exception &e)
    {
      printf("FAIL port# %d\n", i);
    }
  }

  memset(m_raw_buffer, 0, BUFFER_SIZE);
  m_proc_buffer.clear();
  if (m_validSerialPort)
  {
    m_uart.Reset();
  }
}

// returns true if vision is online
bool subsystem_Vision::isVisionOnline()
{
  return m_validSerialPort;
}

// turns string of serial data into an array of PixyBlock objects
void subsystem_Vision::makePixyBlockArray(string s)
{
  pixyBlocks.clear();
  string delim = "\n";
  s = s.erase(0, 1);
  int count = 0;
  for (unsigned int i = 0; i < s.length(); ++i)
  {
    if (s.substr(i, 1) == "\n")
    {
      count++;
    }
  }

  string arr[count];

  auto start = 0U;
  auto end = s.find(delim);
  int x = 0;
  while (end != string::npos)
  {
    arr[x] = s.substr(start, end - start);
    start = end + delim.length();
    end = s.find(delim, start);
    x++;
  }

  for (int j = 0; j < count; j++)
  {
    int i = 0;
    string inner[6];
    stringstream check(arr[j]);
    while (check.good() && i < 6)
    {
      check >> inner[i];
      i++;
    }
    PixyBlock thisPixy;
    thisPixy.setSig(inner[0]);
    thisPixy.setX(inner[1]);
    thisPixy.setY(inner[2]);
    thisPixy.setW(inner[3]);
    thisPixy.setH(inner[4]);
    thisPixy.setAge(inner[5]);
    pixyBlocks.push_back(thisPixy);
  }
}

// gets blocks with aspect ratio and signature restrictions
vector<PixyBlock> subsystem_Vision::getBlocks(float lowerAspect, float higherAspect, int sig)
{
  vector<PixyBlock> filteredBlocks;
  for (unsigned int i = 0; i < pixyBlocks.size(); i++)
  {
    if (((pixyBlocks[i].getW() / pixyBlocks[i].getH()) > lowerAspect && (pixyBlocks[i].getW() / pixyBlocks[i].getH()) < higherAspect) && (pixyBlocks[i].getSig() == sig))
    {
      filteredBlocks.push_back(pixyBlocks[i]);
    }
  }
  return filteredBlocks;
}

// gets blocks with aspect ratio restrictions
vector<PixyBlock> subsystem_Vision::getBlocks(float lowerAspect, float higherAspect)
{
  vector<PixyBlock> filteredBlocks;
  for (unsigned int i = 0; i < pixyBlocks.size(); i++)
  {
    if ((pixyBlocks[i].getW() / pixyBlocks[i].getH()) > lowerAspect && (pixyBlocks[i].getW() / pixyBlocks[i].getH()) < higherAspect)
    {
      filteredBlocks.push_back(pixyBlocks[i]);
    }
  }
  return filteredBlocks;
}

// gets blocks with signature restrictions
vector<PixyBlock> subsystem_Vision::getBlocks(int sig)
{
  vector<PixyBlock> filteredBlocks;
  for (unsigned int i = 0; i < pixyBlocks.size(); i++)
  {
    if (pixyBlocks[i].getSig() == sig)
    {
      filteredBlocks.push_back(pixyBlocks[i]);
    }
  }
  return filteredBlocks;
}

vector<PixyBlock> subsystem_Vision::getBlocks()
{
  return pixyBlocks;
}

string subsystem_Vision::getProcBuffer()
{
  return m_proc_buffer;
}

PixyBlock subsystem_Vision::getDesiredBlock(vector<PixyBlock> blocks){
  PixyBlock desiredBlock = blocks[0];
  for(unsigned int i = 1; i < blocks.size(); i++)
  {
    if(blocks[i].getW() > blocks[i-1].getW()){
      desiredBlock = blocks[i];
    }
  }
  return desiredBlock;
}

// This method will be called once per scheduler run
void subsystem_Vision::Periodic()
{
  int bytes_available = m_uart.GetBytesReceived();

  if (bytes_available > BUFFER_SIZE)
  {
    // Flag an error here, if this happens you'll probably want to either increase BUFFER_SIZE or limit what's coming across the UART
  }
  else if (bytes_available > 0)
  {
    int bytes_read = m_uart.Read(m_raw_buffer, bytes_available);

    if (bytes_read != bytes_available)
    {
      // NOTE: Probably a good idea to flag an error here
    }

    for (int i = 0; i < bytes_read; ++i)
    {
      switch (m_raw_buffer[i])
      {
      case START_CHAR:
        m_data_ready = false;
        m_proc_buffer.clear();
        break;
      case STOP_CHAR:
        makePixyBlockArray(m_proc_buffer);
        m_data_ready = true;
        m_print_data = true;
        break;
      }

      m_proc_buffer.push_back(m_raw_buffer[i]);
    }

    memset(m_raw_buffer, 0, BUFFER_SIZE); // Clear buffer for next time we read data
  }

  if (m_print_data)
  {
    m_print_data = false;
    //printf("Data: %s\r\n", m_proc_buffer.c_str());
  }
}