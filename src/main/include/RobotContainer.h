// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once


#include <frc2/command/Command.h>
#include <frc/Joystick.h>
#include <frc/smartdashboard/SendableChooser.h>
#include "frc/XboxController.h"
#include "frc2/command/button/JoystickButton.h"
#include "subsystems/subsystem_Drive.h"
#include "subsystems/subsystem_Vision.h"
#include "commands/command_VisionTracking.h"

#include "subsystems/subsystem_Drive.h"
#include "subsystems/subsystem_Arm.h"
#include "subsystems/subsystem_Shooter.h"
#include "subsystems/subsystem_Climb.h"

#include "subsystems/subsystem_Shooter.h"
#include "commands/cGroup_TriangleAuto.h"
#include "commands/cGroup_TwoBallAuto.h"
#include "commands/cGroup_OneBallAuto.h"
#include "commands/cGroup_OneBallAutoIntake.h"
#include "commands/cGroup_AutonomousDelayedDrive.h"
#include "commands/cGroup_AutoDelayedDriveIntake.h"

#include "commands/command_ArmByPositionDown.h"
#include "commands/command_ArmByPositionUp.h"
#include "commands/command_ToggleArmPosition.h"



#include "commands/command_DriveByJoystick.h"
#include "commands/command_DriveByPower.h"
#include "commands/command_DriveByDistance.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/smartdashboard/SendableChooser.h>
#include "frc2/command/button/JoystickButton.h"


#include "commands/command_LockClimb.h"
#include "commands/command_SetClimbByPower.h"
#include "commands/command_ClimbByJoystick.h"
#include "commands/command_UnlockSolenoid.h"
#include "commands/cGroup_UnlockClimb.h"
#include "commands/command_ManualUnlockClimb.h"
#include "commands/command_TurnByDegrees.h"

#include "frc/XboxController.h"
#include "frc2/command/button/JoystickButton.h"
#include <frc/Joystick.h>
#include "Constants.h"



/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  // The robot's subsystems and commands are defined here...
  subsystem_Drive m_drive;
  subsystem_Arm m_arm;
  subsystem_Shooter m_shooter;
  subsystem_Climb m_Climb;
  subsystem_Vision m_subsystem_Vision;



  cGroup_AutonomousDelayedDrive m_zeroBallAuto{&m_drive, -40, 0.0, 5.0};
  cGroup_AutonomousDelayedDrive m_delayedZeroBallAuto{&m_drive, -40, 10.0, 11.0};
  cGroup_AutoDelayedDriveIntake m_zeroBallAutoAndIntake{&m_drive, &m_shooter, &m_arm, 0.8, -72, 2.0};


  cGroup_OneBallAuto m_oneBallAuto{&m_drive, &m_shooter, &m_arm, 0, 0, 3.0, -1.0, 0.5, 5.0, 80};
  cGroup_OneBallAutoIntake m_oneBallAutoAndIntake{&m_drive, &m_shooter, &m_arm, -1.0, 1.0, 50, 5.0, 180.0, 40};
  cGroup_OneBallAutoIntake m_MidBallAutoAndIntake{&m_drive, &m_shooter, &m_arm, -1.0, 1.0, 50, 50, -110.0, 20};

  cGroup_TwoBallAuto m_terminalTwoBallAuto{&m_drive, &m_shooter, &m_arm, 0.8, -41, 5, 170, -40, 0.5, 90 };
  cGroup_TwoBallAuto m_hangarTwoBallAuto{&m_drive, &m_shooter, &m_arm, 0.8, -41, 3, -170, -40, 0.5, 90};
  cGroup_TwoBallAuto m_midballTwoBallAuto{&m_drive, &m_shooter, &m_arm, 0.8, -11, 3, 180, 20, 0.5, 20};

  cGroup_TriangleAuto m_triangleAuto{&m_drive, &m_shooter, &m_arm, 1.0, .5, 20, 5, 150.0, -64, 86.0, -89, 120.0, -85, -17.5, 80};  

  cGroup_OneBallAuto m_DBDTest{&m_drive, &m_shooter, &m_arm, 0, -20, 10.0, 0.0, 0.0, 0.0, 20};
  command_TurnByDegrees m_TurnByDegrees{&m_drive, -360.0};

  
  

  frc::SendableChooser<frc2::Command*> m_chooser;
  





  frc::XboxController xboxDriveRad{ControllerConstants::xboxPortDriveRad};
  frc::Joystick xboxYaperator{ControllerConstants::xboxPortYaperator};
  void ConfigureButtonBindings();

};
