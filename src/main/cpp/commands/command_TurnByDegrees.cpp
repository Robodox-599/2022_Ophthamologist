// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_TurnByDegrees.h"

<<<<<<< HEAD
command_TurnByDegrees::command_TurnByDegrees(subsystem_Drive* Drive, double Degrees):
=======
command_TurnByDegrees::command_TurnByDegrees(subsystem_Drive* Drive, std::function<double()> Degrees):
>>>>>>> 113b445ca4f2a53d904bf70f4ab1dd74b1cec125
m_Drive{Drive},
m_Degrees{Degrees} {
  AddRequirements({Drive});
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void command_TurnByDegrees::Initialize() {
<<<<<<< HEAD
  m_Drive->TurnByDegrees(m_Degrees);
=======
  m_Drive->TurnByDegrees(m_Degrees());
>>>>>>> 113b445ca4f2a53d904bf70f4ab1dd74b1cec125
}

// Called repeatedly when this Command is scheduled to run
void command_TurnByDegrees::Execute() {}

// Called once the command ends or is interrupted.
void command_TurnByDegrees::End(bool interrupted) {}

// Returns true when the command should end.
bool command_TurnByDegrees::IsFinished() {
  return true;
}
