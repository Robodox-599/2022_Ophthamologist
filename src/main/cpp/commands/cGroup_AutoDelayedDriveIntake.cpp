// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/cGroup_AutoDelayedDriveIntake.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
cGroup_AutoDelayedDriveIntake::cGroup_AutoDelayedDriveIntake(subsystem_Drive* Drive, subsystem_Shooter* Shooter, subsystem_Arm* Arm, 
                                                              double power, 
                                                              int inches,  
                                                              double timeout) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(command_ArmByPositionDown(Arm),
              command_ShooterFeedOutput(Shooter, [=]{return power;}),
              command_DriveByDistance(Drive, inches, timeout),
              command_ArmByPositionUp(Arm),
              command_ShooterFeedOutput(Shooter, [=]{return 0;}));
}
