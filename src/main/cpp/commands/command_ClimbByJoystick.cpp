// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_ClimbByJoystick.h"

command_ClimbByJoystick::command_ClimbByJoystick(subsystem_Climb *theClimb, std::function<double()> yAxis)
  : m_subsystem_Climb{theClimb}, m_yAxis{yAxis}
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_subsystem_Climb});
}

// Called when the command is initially scheduled.
void command_ClimbByJoystick::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void command_ClimbByJoystick::Execute() {
  m_subsystem_Climb->JoystickPowerClimb((1*m_yAxis()));
  if(m_subsystem_Climb ->GetClimbArmCurrent(ClimbConstants::RightWinchMotor) >= ClimbConstants::currentSpike){
    m_subsystem_Climb->LockClimb(ClimbConstants::RightWinchMotor);
  }
  if(m_subsystem_Climb -> GetClimbArmCurrent(ClimbConstants::LeftWinchMotor) >= ClimbConstants::currentSpike){
    m_subsystem_Climb->LockClimb(ClimbConstants::LeftWinchMotor);
  }
}

// Called once the command ends or is interrupted.
void command_ClimbByJoystick::End(bool interrupted) {}

// Returns true when the command should end.
bool command_ClimbByJoystick::IsFinished() {
  return false;
}
