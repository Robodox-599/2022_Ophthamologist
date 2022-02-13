/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/command_DriveByJoystick.h"

command_DriveByJoystick::command_DriveByJoystick(subsystem_Drive *theDrive, std::function<double()> xAxis, std::function<double()> yAxis)
  : m_subsystem_Drive{theDrive}, m_xAxis{xAxis}, m_yAxis{yAxis} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_subsystem_Drive});
}

// Called when the command is initially scheduled.
void command_DriveByJoystick::Initialize() {}

<<<<<<< HEAD
// Called repeatedly when this Command is sch.eduled to run
=======
// Called repeatedly when this Command is scheduled to run
>>>>>>> 4c921170e4c00c8756a4e02953846e105db9d5e3
void command_DriveByJoystick::Execute() {
  m_subsystem_Drive->JoystickPowerDrive((0.8*m_xAxis()), (0.8*m_yAxis()));
}

// Called once the command ends or is interrupted.
void command_DriveByJoystick::End(bool interrupted) {}

// Returns true when the command should end.
bool command_DriveByJoystick::IsFinished() { return false; }