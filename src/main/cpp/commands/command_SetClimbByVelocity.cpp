// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_SetClimbByVelocity.h"

command_SetClimbByVelocity::command_SetClimbByVelocity(subsystem_Climb* Climb, std::function<double()> Velocity): m_Climb{Climb}, m_Velocity{Velocity} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({Climb});
}

// Called when the command is initially scheduled.
void command_SetClimbByVelocity::Initialize() { m_Climb->SetWinchMotorVelocity(m_Velocity() );}

// Called repeatedly when this Command is scheduled to run
void command_SetClimbByVelocity::Execute() {}

// Called once the command ends or is interrupted.
void command_SetClimbByVelocity::End(bool interrupted) {}

// Returns true when the command should end.
bool command_SetClimbByVelocity::IsFinished() {
  return true;
}
