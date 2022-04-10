// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_UnlockSolenoid.h"

command_UnlockSolenoid::command_UnlockSolenoid(subsystem_Climb* Climb): m_Climb{Climb} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({Climb});
}

// Called when the command is initially scheduled.
void command_UnlockSolenoid::Initialize() {
  m_Climb->UnlockClimb(ClimbConstants::LeftWinchMotor);
  m_Climb->UnlockClimb(ClimbConstants::RightWinchMotor);
 }

// Called repeatedly when this Command is scheduled to run
void command_UnlockSolenoid::Execute() {}

// Called once the command ends or is interrupted.
void command_UnlockSolenoid::End(bool interrupted) {}

// Returns true when the command should end.

bool command_UnlockSolenoid::IsFinished() {
  return true;
}
