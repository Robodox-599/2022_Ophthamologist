// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_ArmByPositionDown.h"

command_ArmByPositionDown::command_ArmByPositionDown(subsystem_Arm* Arm): m_Arm{Arm} {
  AddRequirements({Arm});
}

// Called when the command is initially scheduled.
void command_ArmByPositionDown::Initialize() {
  m_Arm->SetArmPosition(ArmConstants::ArmTicksDown);
}

// Called repeatedly when this Command is scheduled to run
void command_ArmByPositionDown::Execute() {
}

// Called once the command ends or is interrupted.
void command_ArmByPositionDown::End(bool interrupted) {}

// Returns true when the command should end.
bool command_ArmByPositionDown::IsFinished() {
  return false;
}
