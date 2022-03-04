// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/cGroup_OneBallAuto.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
cGroup_OneBallAuto::cGroup_OneBallAuto(subsystem_Drive *Drive,
                                        subsystem_Shooter* Shooter,
                                        subsystem_Arm* Arm,
                                        double degrees,
                                        int inchesToHub, 
                                        double timeout,   
                                        double power, 
                                        double time,
                                        int inchesFromTarmac) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(command_TurnByDegrees(Drive, degrees),
               command_DriveByDistance(Drive, inchesToHub, timeout), 
               command_ShooterFeedOutput(Shooter, [=]{return power;}),
               command_Timer(time),
               command_ShooterFeedOutput(Shooter, [=]{return 0;}),
               command_DriveByDistance(Drive, inchesFromTarmac, timeout) );
}
