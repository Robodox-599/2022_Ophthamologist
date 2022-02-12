// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_TurnByTime.h"

command_TurnByTime::command_TurnByTime(subsystem_Drive* Drive, std::function<double()> Turn, std::function<double()> Time): 
m_Drive{Drive}, 
m_Time{Time}, 
m_Turn{Turn}
{
  // Use addRequirements() here to declare subsystem dependencies.
AddRequirements({Drive});
  
}

// Called when the command is initially scheduled.
void command_TurnByTime::Initialize() {
  m_Timer.Stop();
  m_Timer.Reset();
  m_Timer.Start();
  m_Drive->DriveByPower(m_Turn(), 0);
}

// Called repeatedly when this Command is scheduled to run
void command_TurnByTime::Execute() {}

// Called once the command ends or is interrupted.
void command_TurnByTime::End(bool interrupted) {
  m_Drive->DriveByPower(0,0);
}

// Returns true when the command should end.
bool command_TurnByTime::IsFinished() {
  return (int)m_Timer.Get() > m_Time();
}
