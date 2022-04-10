
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "frc/smartdashboard/SmartDashboard.h"
#include "RobotContainer.h"
#include "Constants.h"



RobotContainer::RobotContainer()  {

  // auton chooser + names
   m_chooser.SetDefaultOption("Zero Ball Auto",&m_zeroBallAuto);
   m_chooser.AddOption("Delayed Zero Ball Auto", &m_delayedZeroBallAuto);
   m_chooser.AddOption("Zero Ball Auto + Intake", &m_zeroBallAutoAndIntake);
   m_chooser.AddOption("One Ball Auto", &m_oneBallAuto);
   m_chooser.AddOption("One Ball Auto + Intake", &m_oneBallAutoAndIntake);
   m_chooser.AddOption("Middle Ball Auto + Intake", &m_MidBallAutoAndIntake);
   m_chooser.AddOption("Hangar Two Ball Auto", &m_hangarTwoBallAuto);
   m_chooser.AddOption("Terminal Two Ball Auto", &m_terminalTwoBallAuto);
   m_chooser.AddObject("Midball Two Ball Auto", &m_midballTwoBallAuto);
   m_chooser.AddOption("Triangle Auto", &m_triangleAuto);
   m_chooser.AddObject("Test", &m_DBDTest);
   m_chooser.AddObject("TurnByDegrees", &m_TurnByDegrees);
   frc::SmartDashboard::PutData(&m_chooser);

  //New Drive Code; Trigger Drive
   m_drive.SetDefaultCommand(command_DriveByPower(&m_drive, [this] {return -1 * xboxDriveRad.GetRawAxis(ControllerConstants::xboxLXAxis);}, 
                                                  [this] {return xboxDriveRad.GetRawAxis(ControllerConstants::xboxLTAxis) - xboxDriveRad.GetRawAxis(ControllerConstants::xboxRTAxis); } ));
  
  //New Drive Code; Joystick Drive
  // m_drive.SetDefaultCommand(command_DriveByPower(&m_drive, [this] {return -1 *xboxDriveRad.GetRawAxis(ControllerConstants::xboxRXAxis);},
  // [this] {return xbox.GetRawAxis(ControllerConstants::xboxLYAxis);}));

  //Old Drive Code; Joystick Drive

  //  m_drive.SetDefaultCommand(command_DriveByJoystick(&m_drive, [this]{return xboxDriveRad.GetRawAxis(ControllerConstants::xboxRXAxis);}, 
  //  [this] {return xboxDriveRad.GetRawAxis(ControllerConstants::xboxLYAxis);}));

  //
  // m_drive.SetDefaultCommand(command_DriveByPower(&m_drive, [this] {return xboxDriveRad.GetRawAxis(ControllerConstants::xboxLTAxis) - xboxDriveRad.GetRawAxis(ControllerConstants::xboxRTAxis); }, 
  //                                                [this] {return -1 * xboxDriveRad.GetRawAxis(ControllerConstants::xboxLXAxis);} ));
                                                 //[this] {return -1 * xboxDriveRad.GetRawAxis(ControllerConstants::xboxLXAxis);}
  //intake if joystick drive
  //m_shooter.SetDefaultCommand( command_ShooterFeedOutput(&m_shooter, [=]{return xbox.GetRawAxis(ControllerConstants::xboxRTAxis);}));
  //m_shooter.SetDefaultCommand( command_ShooterFeedOutput(&m_shooter, [=]{return xbox.GetRawAxis(ControllerConstants::xboxLTAxis);}));

  //intake if trigger drive 
  //m_shooter.SetDefaultCommand( command_shooterFeedOutput(&m_shooter, [=]{return xbox.GetRawAxis(ControllerConstants::xboxRYAxis)*0.55;}))

  //climb
  // if(xboxYaperator.GetRawAxis(ControllerConstants::xboxLTAxis) > 0.25){
  //   m_shooter.SetDefaultCommand(command_ShooterFeedOutput(&m_shooter, [this] {return 0.8;}));
  // } else if (xboxYaperator.GetRawAxis(ControllerConstants::xboxRTAxis) > 0.25){
  //   m_shooter.SetDefaultCommand(command_ShooterFeedOutput(&m_shooter, [this] {return -1;}));
  // }
  m_Climb.SetDefaultCommand(command_ClimbByJoystick(&m_Climb, [this] {return -1 * xboxYaperator.GetRawAxis(ControllerConstants::xboxLYAxis);}));

  m_shooter.SetDefaultCommand(command_ShooterFeedOutput(&m_shooter, [this] {return ( xboxYaperator.GetRawAxis(ControllerConstants::xboxLTAxis) - xboxYaperator.GetRawAxis(ControllerConstants::xboxRTAxis));}, [=]{return false;}));

  ConfigureButtonBindings();
}


void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
   frc2::JoystickButton xboxA(&xboxYaperator, ControllerConstants::xboxA);
   frc2::JoystickButton xboxB(&xboxYaperator, ControllerConstants::xboxB);
   frc2::JoystickButton xboxX(&xboxYaperator, ControllerConstants::xboxX);
   frc2::JoystickButton xboxY(&xboxYaperator, ControllerConstants::xboxY);
   frc2::JoystickButton xboxRB(&xboxYaperator, ControllerConstants::xboxRB);
   frc2::JoystickButton xboxLB(&xboxYaperator, ControllerConstants::xboxLB);
   frc2::JoystickButton xboxLTAxis(&xboxYaperator, ControllerConstants::xboxLTAxis);
   frc2::JoystickButton xboxRTAxis(&xboxYaperator, ControllerConstants::xboxRTAxis);


  //  xboxRB.WhenPressed( command_ArmByPositionDown(&m_arm) );
  //  xboxLB.WhenPressed( command_ArmByPositionUp(&m_arm) );

   xboxLB.WhenPressed(command_ToggleArmPosition(&m_arm));
  //  xboxLTAxis.WhenPressed(command_ShooterFeedOutput(&m_shooter, [=]{return ShooterConstants::shooterFeedInPower;}));
  //  xboxLTAxis.WhenReleased(command_ShooterFeedOutput(&m_shooter, [=]{return 0;}));
  //  xboxRTAxis.WhenPressed(command_ShooterFeedOutput(&m_shooter, [=]{return ShooterConstants::shooterFeedOutPower;}));
  //  xboxRTAxis.WhenReleased(command_ShooterFeedOutput(&m_shooter, [=]{return 0;})); 
  
   xboxX.WhenPressed(cGroup_UnlockClimb(&m_Climb));
   xboxA.WhenPressed(command_LockClimb(&m_Climb));
   xboxY.WhenPressed(command_ManualUnlockClimb(&m_Climb));

  // //xboxY.WhenHeld(command_VisionTracking(&m_subsystem_Vision, &m_drive)); 

//atk3 climb controls

  //  frc2::JoystickButton atk3SolenoidUnlock(&atk3, ControllerConstants::atk3WinchUnlock);
  //  frc2::JoystickButton atk3SolenoidLock(&atk3, ControllerConstants::atk3WinchLock);

  //  frc2::JoystickButton atk3WinchUp(&atk3, ControllerConstants::atk3WinchUp);
  //  frc2::JoystickButton atk3WinchDown(&atk3, ControllerConstants::atk3WinchDown);
  //  frc2::JoystickButton atk3WinchDownTest(&atk3, ControllerConstants::atk3WinchDownTest);
  //  frc2::JoystickButton atk3WinchUpTest(&atk3, ControllerConstants::atk3WinchUpTest);

  //  atk3WinchUp.WhenPressed(command_SetClimbByPower(&m_Climb, [=]{return 0.5;}));
  //  atk3WinchUp.WhenReleased(command_SetClimbByPower(&m_Climb, [=]{return 0;}));
  //  atk3WinchDown.WhenPressed(command_SetClimbByPower(&m_Climb, [=]{return -0.5;}));
  //  atk3WinchDown.WhenReleased(command_SetClimbByPower(&m_Climb, [=]{return 0;}));
  //  atk3SolenoidLock.WhenPressed(command_LockClimb(&m_Climb));
  //  atk3SolenoidUnlock.WhenPressed(command_UnlockClimb(&m_Climb));
  
//  atk3WinchUpTest.WhileHeld(command_IncrementWinchPosition(&m_Climb));
//  atk3WinchDownTest.WhileHeld(command_DecrementWinchPosition(&m _Climb));


}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return m_chooser.GetSelected();
}
