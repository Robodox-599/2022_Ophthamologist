// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/cGroup_TriangleAuto.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
cGroup_TriangleAuto::cGroup_TriangleAuto(subsystem_Drive* Drive, subsystem_Shooter* Shooter, subsystem_Arm* Arm,
                      double intakePower,
                      double time, 
                      int inchesFromHub,
                      double timeout,
                      double degreesToFirstBall,
                      int inchesToFirstBall,
                      double degressToSecondBall,
                      int inchesToSecondBall,
                      double degreesToHubPoint,
                      int inchesToHub,
                      double degreesToHub,
                      int inchesFromTarmac) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(command_ShooterFeedOutput(Shooter, [=]{return -1 *intakePower;}, [=]{return true;}),
              command_Timer(time),
              command_ShooterFeedOutput(Shooter, [=]{return 0;}, [=]{return true;}),
              command_DriveByDistance(Drive, inchesFromHub, timeout),
              command_ToggleArmPosition(Arm),
              command_TurnByDegrees(Drive, degreesToFirstBall),
              command_ShooterFeedOutput(Shooter, [=]{return intakePower;}, [=]{return true;}),
              command_DriveByDistance(Drive, inchesToFirstBall, timeout),
              command_ShooterFeedOutput(Shooter, [=]{return 0;}, [=]{return true;}),
              command_TurnByDegrees(Drive, degressToSecondBall),
              command_ShooterFeedOutput(Shooter, [=]{return intakePower;}, [=]{return true;}),
              command_DriveByDistance(Drive, inchesToSecondBall, timeout),
              command_ShooterFeedOutput(Shooter, [=]{return 0;}, [=]{return true;}),
              command_ToggleArmPosition(Arm),              
              command_TurnByDegrees(Drive, degreesToHubPoint),
              command_DriveByDistance(Drive, inchesToHub, timeout),
              command_TurnByDegrees(Drive, degreesToHub),
              command_ShooterFeedOutput(Shooter, [=]{return -1 *intakePower;}, [=]{return true;}),
              command_Timer(time),
              command_ShooterFeedOutput(Shooter, [=]{return 0;}, [=]{return true;}),
              command_DriveByDistance(Drive, inchesFromTarmac, timeout));

}
