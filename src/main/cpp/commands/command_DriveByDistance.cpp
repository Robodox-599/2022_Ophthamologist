/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/command_DriveByDistance.h"

command_DriveByDistance::command_DriveByDistance(subsystem_Drive *theDrive, int inches, double timeout)
  : m_subsystem_Drive{theDrive}, m_inches{inches}, m_timeout{timeout} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_subsystem_Drive});
}

// Called when the command is initially scheduled.
void command_DriveByDistance::Initialize() {
  m_Timer.Stop();
  m_Timer.Reset();
  m_Timer.Start();
  m_subsystem_Drive->DriveDistance(m_inches);
  frc::SmartDashboard::PutNumber("Initial pos", m_subsystem_Drive->getCurrentPosition());
  m_originalPosition = m_subsystem_Drive->getCurrentPosition();
}

// Called repeatedly when this Command is scheduled to run
void command_DriveByDistance::Execute() {
  if ( fabs(m_subsystem_Drive->GetPIDError(m_originalPosition, m_inches)) < m_errorWindow )
  {
    m_errorWindowCount++;

  }
  else
  {
    m_errorWindowCount = 0;
  }
  frc::SmartDashboard::PutNumber("Error Window Count", m_errorWindowCount);
  frc::SmartDashboard::PutNumber("Time", (double)m_Timer.Get());
  frc::SmartDashboard::PutNumber("error", fabs(m_subsystem_Drive->GetPIDError(m_originalPosition, m_inches)));
  
}

// Called once the command ends or is interrupted.
void command_DriveByDistance::End(bool interrupted) {
  frc::SmartDashboard::PutNumber("Final Pos", m_subsystem_Drive->getCurrentPosition());
}

// Returns true when the command should end.
bool command_DriveByDistance::IsFinished() { 
   if( ( ( (double) m_Timer.Get() ) > m_timeout ) || (m_subsystem_Drive->GetCurrentOutput() >= DriveConstants::snuggleCurrent) ){
     return true;
   }else{
    return m_errorWindowCount > m_errorWindowTargetCount; 
  }
}
