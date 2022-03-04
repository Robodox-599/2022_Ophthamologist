
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "frc/smartdashboard/SmartDashboard.h"
#include "RobotContainer.h"
#include "Constants.h"


<<<<<<< HEAD
RobotContainer::RobotContainer()  {
  // m_chooser.SetDefaultOption("Middle Auto", &m_autonomousCommandMiddle);
  // m_chooser.AddOption("Left Auto", &m_autonomousCommandLeft);
  // m_chooser.AddOption("Right Auto", &m_autonomousCommandRight);
  // // Put the chooser on the dashboard

  m_chooser.SetDefaultOption("Zero Ball Auto",&m_zeroBallAuto);
  m_chooser.AddOption("Delayed Zero Ball Auto", &m_delayedZeroBallAuto);
  m_chooser.AddOption("Zero Ball Auto + Intake", &m_zeroBallAutoAndIntake);
  m_chooser.AddOption("One Ball Auto", &m_oneBallAuto);
  m_chooser.AddOption("One Ball Auto + Intake", &m_oneBallAutoAndIntake);
  m_chooser.AddOption("Middle Ball Auto + Intake", &m_MidBallAutoAndIntake);
  m_chooser.AddOption("Two Ball Auto", &m_twoBallAuto);
  m_chooser.AddOption("Complex Two Ball Auto", &m_complexTwoBallAuto);
  m_chooser.AddOption("Triangle Auto", &m_triangleAuto);
  frc::SmartDashboard::PutData(&m_chooser);



   //Initialize all of your commands and subsystems here
  // m_Arm.SetDefaultCommand( command_ArmByPositionUp(&m_Arm));
 // m_Arm.SetDefaultCommand( command_ArmByPositionDown(&m_Arm));
  // Initialize all of your commands and subsystems here
=======
RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  
   //Initialize all of your commands and subsystems here

  m_drive.SetDefaultCommand(command_DriveByPower(&m_drive, [this] {return xbox.GetRawAxis(ControllerConstants::xboxRXAxis);},
  [this] {return xbox.GetRawAxis(ControllerConstants::xboxLYAxis);}));
  // m_drive.SetDefaultCommand(command_DriveByJoystick(&m_drive, [this]{return xbox.GetRawAxis(ControllerConstants::xboxLYAxis);}, 
  // [this] {return xbox.GetRawAxis(ControllerConstants::xboxRXAxis);}));

 // m_drive.SetDefaultCommand(command_DriveByPower(&m_drive, [this] {return xbox.GetRawAxis(ControllerConstants::xboxRTAxis) - xbox.GetRawAxis(ControllerConstants::xboxLTAxis); }, 
  //                                                [this] {return xbox.GetRawAxis(ControllerConstants::xboxLXAxis);}));
>>>>>>> 113b445ca4f2a53d904bf70f4ab1dd74b1cec125

  m_drive.SetDefaultCommand(command_DriveByPower(&m_drive, [this] {return xbox.GetRawAxis(ControllerConstants::xboxLYAxis);},
  [this] {return xbox.GetRawAxis(ControllerConstants::xboxRXAxis);}));
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
<<<<<<< HEAD
  xboxRB.WhenPressed( command_ArmByPositionDown(&m_arm) );
  xboxRB.WhenReleased( command_ArmByPositionUp(&m_arm) );
  xboxA.WhenPressed( command_ShooterFeedOutput(&m_shooter, [=]{return 0.1;}));
  xboxA.WhenReleased( command_ShooterFeedOutput(&m_shooter, [=]{return 0;}));
  xboxB.WhenPressed( command_ShooterFeedOutput(&m_shooter, [=]{return -0.1;}));
  xboxB.WhenReleased( command_ShooterFeedOutput(&m_shooter, [=]{return 0;})); 

  xboxY.WhenHeld(command_VisionTracking(&m_subsystem_Vision, &m_drive)); 

  frc2::JoystickButton atk3WinchUnlock(&atk3, ControllerConstants::atk3WinchUnlock);
  frc2::JoystickButton atk3WinchLock(&atk3, ControllerConstants::atk3WinchLock);
  frc2::JoystickButton atk3WinchUp(&atk3, ControllerConstants::atk3WinchUp);
  frc2::JoystickButton atk3WinchDown(&atk3, ControllerConstants::atk3WinchDown);
  atk3WinchUp.WhileHeld(command_IncrementWinchPosition(&m_Climb));
  atk3WinchDown.WhileHeld(command_DecrementWinchPosition(&m_Climb));
  atk3WinchLock.WhenPressed(command_LockClimb(&m_Climb));
  atk3WinchUnlock.WhenPressed(command_UnlockClimb(&m_Climb));
=======
>>>>>>> 113b445ca4f2a53d904bf70f4ab1dd74b1cec125
  
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return m_chooser.GetSelected();
}
