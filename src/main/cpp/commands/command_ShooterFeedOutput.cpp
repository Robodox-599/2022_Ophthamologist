// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_ShooterFeedOutput.h"
#include "Constants.h"
#include "Robot.h"

command_ShooterFeedOutput::command_ShooterFeedOutput(subsystem_Shooter* shooter, std::function<double()> power) : m_shooter{shooter}, m_power{power}{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({shooter});
}

// Called when the command is initially scheduled.
void command_ShooterFeedOutput::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void command_ShooterFeedOutput::Execute() {m_shooter->SetIntakeWheelOn(m_power());}

// Called once the command ends or is interrupted.
void command_ShooterFeedOutput::End(bool interrupted) {}

// Returns true when the command should end.
bool command_ShooterFeedOutput::IsFinished() {
  return true;
}
