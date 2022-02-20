// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
 // m_Arm.SetDefaultCommand( command_ArmByPositionUp(&m_Arm));
 // m_Arm.SetDefaultCommand( command_ArmByPositionDown(&m_Arm));
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
   xboxA.WhenPressed(command_ArmByPositionDown(&m_Arm));
   xboxB.WhenPressed(command_ArmByPositionUp(&m_Arm));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
