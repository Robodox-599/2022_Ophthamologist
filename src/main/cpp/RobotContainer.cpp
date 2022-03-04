// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  
  frc2::JoystickButton xboxA(&xbox, ControllerConstants::xboxA);
  frc2::JoystickButton xboxB(&xbox, ControllerConstants::xboxB);
  frc2::JoystickButton xboxX(&xbox, ControllerConstants::xboxX);
  frc2::JoystickButton xboxY(&xbox, ControllerConstants::xboxY);
  frc2::JoystickButton xboxRB(&xbox, ControllerConstants::xboxRB);
  frc2::JoystickButton xboxLB(&xbox, ControllerConstants::xboxLB);

  frc2::JoystickButton atk3WinchUnlock(&atk3, ControllerConstants::atk3WinchUnlock);
  frc2::JoystickButton atk3WinchLock(&atk3, ControllerConstants::atk3WinchLock);
  frc2::JoystickButton atk3WinchUp(&atk3, ControllerConstants::atk3WinchUp);
  frc2::JoystickButton atk3WinchDown(&atk3, ControllerConstants::atk3WinchDown);
  atk3WinchUp.WhileHeld(command_IncrementWinchPosition(&m_Climb));
  atk3WinchDown.WhileHeld(command_DecrementWinchPosition(&m_Climb));
  atk3WinchLock.WhenPressed(command_LockClimb(&m_Climb));
  atk3WinchUnlock.WhenPressed(command_UnlockClimb(&m_Climb));
  
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
