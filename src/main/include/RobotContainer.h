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

#include "commands/cGroup_TriangleAuto.h"
#include "commands/cGroup_ThreeBallAuto.h"
#include "commands/cGroup_TwoBallAuto.h"
#include "commands/cGroup_OneBallAuto.h"
#include "commands/cGroup_OneBallAutoIntake.h"
#include "commands/cGroup_AutonomousDelayedDrive.h"
#include "commands/cGroup_AutoDelayedDriveIntake.h"


#include "commands/command_DriveByJoystick.h"
#include "commands/command_DriveByPower.h"
#include "commands/command_DriveByDistance.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/smartdashboard/SendableChooser.h>
#include "frc2/command/button/JoystickButton.h"


#include "commands/command_LockClimb.h"
#include "commands/command_SetClimbByPosition.h"
#include "commands/command_SetClimbByPower.h"
#include "commands/command_UnlockClimb.h"
#include "commands/command_DecrementWinchPosition.h"
#include "commands/command_IncrementWinchPosition.h"
#include "commands/command_SetClimbByVelocity.h"


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



  cGroup_AutonomousDelayedDrive m_zeroBallAuto{&m_drive, 40, 0, 10.0};
  cGroup_AutonomousDelayedDrive m_delayedZeroBallAuto{&m_drive, 40, 10.0, 10.0};
  cGroup_AutoDelayedDriveIntake m_zeroBallAutoAndIntake{&m_drive, &m_shooter, &m_arm, 0.8, 40, 10.0};


  cGroup_OneBallAuto m_oneBallAuto{&m_drive, &m_shooter, &m_arm, 0.0, 0, 5, 0.8, 10, 60};
  cGroup_OneBallAutoIntake m_oneBallAutoAndIntake{&m_drive, &m_shooter, &m_arm, 0.8, 3.0, 50, 5, 180.0, 40};
  cGroup_OneBallAutoIntake m_MidBallAutoAndIntake{&m_drive, &m_shooter, &m_arm, 0.8, 3.0, 50, 50, -110.0, 20};



  cGroup_TwoBallAuto m_twoBallAuto{&m_drive, &m_shooter, &m_arm, 0.8, 20, 5.0, 180.0, 20, 10.0, 30, 3, 60};
  cGroup_TwoBallAuto m_complexTwoBallAuto{&m_drive, &m_shooter, &m_arm, 0.8, 20, 5.0, 180.0, 20, 45.0, 10, 3, 60 };
  cGroup_TriangleAuto m_triangleAuto{&m_drive, &m_shooter, &m_arm, 0.8, 3, 20, 5, 170.0, 40, 60.0, 40, 90.0, 20, -30.0, 20};  

  frc::SendableChooser<frc2::Command*> m_chooser;
  





  frc::XboxController xbox{ControllerConstants::xboxPort};
  frc::Joystick atk3{ControllerConstants::joystickPort};
  void ConfigureButtonBindings();

};
