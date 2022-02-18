// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_ArmByPositionUp.h"

command_ArmByPositionUp::command_ArmByPositionUp(subsystem_Arm *Arm): m_Arm{Arm} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({Arm});
}

// Called when the command is initially scheduled.
void command_ArmByPositionUp::Initialize() {
  m_Arm->SetArmPosition(ArmConstants::ArmTicksUp);
}

// Called repeatedly when this Command is scheduled to run
void command_ArmByPositionUp::Execute() {}

// Called once the command ends or is interrupted.
void command_ArmByPositionUp::End(bool interrupted) {}

// Returns true when the command should end.
bool command_ArmByPositionUp::IsFinished() {
  return false;
}
