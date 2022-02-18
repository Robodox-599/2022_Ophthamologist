// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_ShooterFeedIn.h"
#include "Constants.h"
#include "Robot.h"

command_ShooterFeedIn::command_ShooterFeedIn(subsystem_Shooter* shooter, std::function<double()> power) : m_shooter{shooter}, m_power{power}{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({shooter});
}

// Called when the command is initially scheduled.
void command_ShooterFeedIn::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void command_ShooterFeedIn::Execute() {m_shooter->SetIntakeWheelOn(m_power);}

// Called once the command ends or is interrupted.
void command_ShooterFeedIn::End(bool interrupted) {}

// Returns true when the command should end.
bool command_ShooterFeedIn::IsFinished() {
  return false;
}
