// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_SetShooterVelocity.h"

command_SetShooterVelocity::command_SetShooterVelocity(subsystem_Shooter* Shooter,  std::function<double()> velocity):
m_Shooter{Shooter}, m_velocity{velocity} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({Shooter});
}

// Called when the command is initially scheduled.
void command_SetShooterVelocity::Initialize() {m_Shooter->SetIntakeVelocity(m_velocity()); }

// Called repeatedly when this Command is scheduled to run
void command_SetShooterVelocity::Execute() {}

// Called once the command ends or is interrupted.
void command_SetShooterVelocity::End(bool interrupted) {}

// Returns true when the command should end.
bool command_SetShooterVelocity::IsFinished() {
  return false;
}
