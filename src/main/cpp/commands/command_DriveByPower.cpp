// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_DriveByPower.h"

command_DriveByPower::command_DriveByPower(subsystem_Drive* Drive, std::function<double()> X, std::function<double()> Y):
m_Drive{Drive},
m_X{X},
m_Y{Y} 
{
  AddRequirements({Drive});
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void command_DriveByPower::Initialize() {
  m_Drive->JoystickDrive(m_X(), m_Y());
}

// Called repeatedly when this Command is scheduled to run
void command_DriveByPower::Execute() {}

// Called once the command ends or is interrupted.
void command_DriveByPower::End(bool interrupted) {}

// Returns true when the command should end.
bool command_DriveByPower::IsFinished() {
  return false;
}
