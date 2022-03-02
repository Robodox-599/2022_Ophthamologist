// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <vector>
#include <frc/SerialPort.h>
#include <frc2/command/SubsystemBase.h>
#include "PixyBlock.h"
#include "frc/smartdashboard/SmartDashboard.h"

using namespace std;

class subsystem_Vision : public frc2::SubsystemBase
{
public:
  enum sigs
  {
    blue = 1,
    red = 2
  };

  subsystem_Vision();

  bool isVisionOnline();

  void makePixyBlockArray(string s);

  string getProcBuffer(); 

  vector<PixyBlock> getBlocks(float lowerAspect, float higherAspect, int sig);
  vector<PixyBlock> getBlocks(float lowerAspect, float higherAspect);
  vector<PixyBlock> getBlocks(int sig);
  vector<PixyBlock> getBlocks();
  PixyBlock getDesiredBlock(vector<PixyBlock> blocks);
  // PixyBlock getDesiredBlock(vector<PixyBlock> blocks); 


  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

private:
  static const char START_CHAR = '*';
  static const char STOP_CHAR = '^';

  static const int BUFFER_SIZE = 256; // NOTE: You'll need to set this to something sane based on how much data you actually expect to get per frame,
                                      //       plus maybe some extra in case of delays or frame overruns


  char m_raw_buffer[BUFFER_SIZE]; // buffer for data as it comes from the UART
  std::string m_proc_buffer;      // buffer for data after it's been processed into delimited format
  bool m_data_ready;              // when true, a complete frame has been read from the UART
  bool m_print_data;
  bool m_validSerialPort;

  frc::SerialPort m_uart;

  vector<PixyBlock> pixyBlocks;
};
