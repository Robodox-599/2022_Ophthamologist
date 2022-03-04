// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_SetClimbByPower.h"

command_SetClimbByPower::command_SetClimbByPower(subsystem_Climb* Climb, std::function<double()> Power): m_Climb{Climb}, m_Power{Power} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({Climb});
}

// Called when the command is initially scheduled.
void command_SetClimbByPower::Initialize() { m_Climb->SetWinchMotorPower( m_Power() );}

// Called repeatedly when this Command is scheduled to run
void command_SetClimbByPower::Execute() {}

// Called once the command ends or is interrupted.
void command_SetClimbByPower::End(bool interrupted) {}

// Returns true when the command should end.
bool command_SetClimbByPower::IsFinished() {
  return false;
}
