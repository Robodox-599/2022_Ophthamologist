// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/cGroup_OneBallAutoIntake.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
cGroup_OneBallAutoIntake::cGroup_OneBallAutoIntake(subsystem_Drive *Drive,
                            subsystem_Shooter* Shooter,
                            subsystem_Arm* Arm,
                            double power,
                            double time,
                            int inchesFromHub,
                            double timeout,
                            double degreesToBall,
                            int inchesFromTarmac) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(command_ShooterFeedOutput(Shooter, [=]{return power;}, [=]{return true;}),
                command_Timer(time),
                command_ShooterFeedOutput(Shooter, [=]{return 0;}, [=]{return true;}),
                command_DriveByDistance(Drive, inchesFromHub, timeout),
                command_TurnByDegrees(Drive, degreesToBall),
                command_ArmByPositionDown(Arm),
                command_ShooterFeedOutput(Shooter, [=]{return power;}, [=]{return true;}),
                command_DriveByDistance(Drive, inchesFromTarmac, timeout),
                command_ArmByPositionUp(Arm),
                command_ShooterFeedOutput(Shooter, [=]{return 0;}, [=]{return true;}));
}
