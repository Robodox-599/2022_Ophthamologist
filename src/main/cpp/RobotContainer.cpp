// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "frc/smartdashboard/SmartDashboard.h"
#include "RobotContainer.h"
#include "Constants.h"

RobotContainer::RobotContainer() : m_autonomousCommand() {
  // (&m_subsystem_Vision, &m_drive)
  // Initialize all of your commands and subsystems here
  // m_subsystem_Vision.SetDefaultCommand(command_VisionTest(&m_subsystem_Vision));
  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  frc2::JoystickButton xboxY(&xbox, ControllerConstants::xboxY);
  xboxY.WhenHeld(command_VisionTracking(&m_subsystem_Vision, &m_drive)); 
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
