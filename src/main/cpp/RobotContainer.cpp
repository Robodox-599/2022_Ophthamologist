// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include "Constants.h"
#include "commands/command_ShooterFeedIn.h"
#include "commands/command_ShooterFeedOut.h"
//: m_autonomousCommand(&m_subsystem)


RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
//  m_Arm.SetDefaultCommand( command_ArmByPositionUp(&m_Arm));
//  m_Arm.SetDefaultCommand( command_ArmByPositionDown(&m_Arm));

  // Initialize all of your commands and subsystems here
  m_shooter.SetDefaultCommand(command_ShooterFeedIn(&m_shooter));
  m_shooter.SetDefaultCommand(command_ShooterFeedOut(&m_shooter));
  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here

  xboxRB.WhenPressed(command_ShooterFeedIn(&m_shooter, [=] {return 0.3;}));
  xboxLB.WhenPressed(command_ShooterFeedOut(&m_shooter, [=] {return -0.3;}));
  xboxRB.WhenReleased(command_ShooterFeedIn(&m_shooter, [=] {return 0.0;}));
  xboxLB.WhenReleased(command_ShooterFeedOut(&m_shooter, [=] {return 0.0;}));
  
  frc2::JoystickButton xboxA(&xbox, ControllerConstants::xboxA);
  frc2::JoystickButton xboxB(&xbox, ControllerConstants::xboxB);
  frc2::JoystickButton xboxX(&xbox, ControllerConstants::xboxX);
  frc2::JoystickButton xboxY(&xbox, ControllerConstants::xboxY);
  frc2::JoystickButton xboxRB(&xbox, ControllerConstants::xboxRB);
  frc2::JoystickButton xboxLB(&xbox, ControllerConstants::xboxLB);
   xboxA.WhenPressed(command_ArmByPositionDown(&m_Arm));
   xboxX.WhenPressed(command_ArmByPositionUp(&m_Arm));
}

// frc2::Command* RobotContainer::GetAutonomousCommand() {
//   // An example command will be run in autonomous
//   return &m_autonomousCommand;
// }
