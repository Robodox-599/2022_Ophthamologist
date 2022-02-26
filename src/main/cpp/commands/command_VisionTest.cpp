// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_VisionTest.h"

command_VisionTest::command_VisionTest(subsystem_Vision *vision, subsystem_Drive *drive) : m_vision(vision), m_drive(drive)
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_vision);
  AddRequirements(m_drive);
}

// Called when the command is initially scheduled.
void command_VisionTest::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void command_VisionTest::Execute() {
  if(m_vision->isVisionOnline() && m_vision->getBlocks(0.7, 1.3, subsystem_Vision::sigs::red).size() > 0){
    m_vision->getDesiredBlock(getBlocks(0.7, 1.3, subsystem_Vision::sigs::red)); 
    double turn = kT * atan(m_vision->getBlocks(0.7, 1.3, subsystem_Vision::sigs::red)[0].getX() / m_vision->getBlocks(0.7, 1.3, subsystem_Vision::sigs::red)[0].getY()); 
    double power = (-1 * pMax / wMax) * m_vision->getBlocks(0.7, 1.3, subsystem_Vision::sigs::red)[0].getW() + pMax;

    m_drive->DriveByPower(turn, power);

   frc::SmartDashboard::PutNumber("Width: ", m_vision->getBlocks(0.7, 1.3, subsystem_Vision::sigs::red)[0].getW());
   frc::SmartDashboard::PutNumber("X: ", m_vision->getBlocks(0.7, 1.3, subsystem_Vision::sigs::red)[0].getX());
   frc::SmartDashboard::PutNumber("Y: ", m_vision->getBlocks(0.7, 1.3, subsystem_Vision::sigs::red)[0].getY());
   frc::SmartDashboard::PutNumber("Turn: ", turn);
   frc::SmartDashboard::PutNumber("Powa: ", power);
  }
}

// Called once the command ends or is interrupted.
void command_VisionTest::End(bool interrupted) {}

// Returns true when the command should end.
bool command_VisionTest::IsFinished() {
  return false;
}

