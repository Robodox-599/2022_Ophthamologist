// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_LockClimb.h"

command_LockClimb::command_LockClimb(subsystem_Climb* Climb): m_Climb{Climb} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({Climb});
}

// Called when the command is initially scheduled.
void command_LockClimb::Initialize() { m_Climb->LockClimb();}

// Called repeatedly when this Command is scheduled to run
void command_LockClimb::Execute() {}

// Called once the command ends or is interrupted.
void command_LockClimb::End(bool interrupted) {}

// Returns true when the command should end.
bool command_LockClimb::IsFinished() {
  return false;
}
