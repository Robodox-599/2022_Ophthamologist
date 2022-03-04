// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_SetClimbByPosition.h"

command_SetClimbByPosition::command_SetClimbByPosition(subsystem_Climb* Climb, std::function<double()> Inches): m_Climb{Climb}, m_Inches{Inches} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({Climb});
}

// Called when the command is initially scheduled.
void command_SetClimbByPosition::Initialize() {m_Climb->SetWinchMotorPosition( m_Inches() );}

// Called repeatedly when this Command is scheduled to run
void command_SetClimbByPosition::Execute() {}

// Called once the command ends or is interrupted.
void command_SetClimbByPosition::End(bool interrupted) {}

// Returns true when the command should end.
bool command_SetClimbByPosition::IsFinished() {
  return false;
}
