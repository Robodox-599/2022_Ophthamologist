/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/command_DriveByDistance.h"

command_DriveByDistance::command_DriveByDistance(subsystem_Drive *theDrive, int inches)
  : m_subsystem_Drive{theDrive}, m_inches{inches} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_subsystem_Drive});
}

// Called when the command is initially scheduled.
void command_DriveByDistance::Initialize() {
  m_subsystem_Drive->DriveDistance(m_inches);
  printf("B");
}

// Called repeatedly when this Command is scheduled to run
void command_DriveByDistance::Execute() {
  if (fabs(m_subsystem_Drive->GetPIDError(m_inches)) < m_errorWindow)
  {
    m_errorWindowCount++;
    printf("_2");
  }
  else
  {
    m_errorWindowCount = 0;
    printf("_4");
  }
  printf("_3");
}

// Called once the command ends or is interrupted.
void command_DriveByDistance::End(bool interrupted) {}

// Returns true when the command should end.
bool command_DriveByDistance::IsFinished() { return m_errorWindowCount > m_errorWindowTargetCount; }
