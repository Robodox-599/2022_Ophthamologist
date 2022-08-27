// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_ToggleArmPosition.h"

command_ToggleArmPosition::command_ToggleArmPosition(subsystem_Arm* Arm): m_Arm{Arm} {

  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({Arm});
}

// Called when the command is initially scheduled.
void command_ToggleArmPosition::Initialize() {
  m_Arm->toggleArmPosition();
}

// Called repeatedly when this Command is scheduled to run
void command_ToggleArmPosition::Execute() {}

// Called once the command ends or is interrupted.
void command_ToggleArmPosition::End(bool interrupted) {}

// Returns true when the command should end.
bool command_ToggleArmPosition::IsFinished() {
  return true;
}
