/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/command_DriveByDistance.h"

<<<<<<< HEAD
command_DriveByDistance::command_DriveByDistance(subsystem_Drive *theDrive, int inches, double timeout)
  : m_subsystem_Drive{theDrive}, m_inches{inches}, m_timeout{timeout} {
=======
command_DriveByDistance::command_DriveByDistance(subsystem_Drive *theDrive, int inches)
  : m_subsystem_Drive{theDrive}, m_inches{inches} {
>>>>>>> 64798c9f81b6832c9614965e53afb6ed13c9fd2c
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_subsystem_Drive});
}

// Called when the command is initially scheduled.
void command_DriveByDistance::Initialize() {
<<<<<<< HEAD
  m_Timer.Stop();
  m_Timer.Reset();
  m_Timer.Start();
=======
>>>>>>> 64798c9f81b6832c9614965e53afb6ed13c9fd2c
  m_subsystem_Drive->DriveDistance(m_inches);
}

// Called repeatedly when this Command is scheduled to run
void command_DriveByDistance::Execute() {
  if (fabs(m_subsystem_Drive->GetPIDError(m_inches)) < m_errorWindow)
  {
    m_errorWindowCount++;
  }
  else
  {
    m_errorWindowCount = 0;
  }
}

// Called once the command ends or is interrupted.
void command_DriveByDistance::End(bool interrupted) {}

// Returns true when the command should end.
<<<<<<< HEAD
bool command_DriveByDistance::IsFinished() { 
  if( (double) m_Timer.Get() > m_timeout || m_subsystem_Drive->GetCurrentOutput() >= DriveConstants::snuggleCurrent){
    return true;
  }else{
    return m_errorWindowCount > m_errorWindowTargetCount; 
  }
}
=======
bool command_DriveByDistance::IsFinished() { return m_errorWindowCount > m_errorWindowTargetCount; }
>>>>>>> 64798c9f81b6832c9614965e53afb6ed13c9fd2c
