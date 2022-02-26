// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc/Joystick.h>
#include "frc/XboxController.h"
#include "frc2/command/button/JoystickButton.h"
#include "subsystems/subsystem_Drive.h"
#include "subsystems/subsystem_Vision.h"
#include "commands/command_VisionTracking.h"
#include "commands/placeHolder.h"

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
  subsystem_Vision m_subsystem_Vision;
  subsystem_Drive m_drive;
  placeHolder m_autonomousCommand;

  frc::XboxController xbox{ControllerConstants::xboxPort};

  void ConfigureButtonBindings();
};
