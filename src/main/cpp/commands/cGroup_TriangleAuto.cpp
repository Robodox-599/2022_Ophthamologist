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
                      double degreesToPerpLine,
                      int inchesToPerpLine,
                      double degreesToHub,
                      int inchesToHub) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(command_ShooterFeedOutput(Shooter, [=]{return intakePower;}),
              command_Timer(time),
              command_ShooterFeedOutput(Shooter, [=]{return 0;}),
              command_DriveByDistance(Drive, inchesFromHub, timeout),
              command_TurnByDegrees(Drive, degreesToFirstBall),
              command_ArmByPositionDown(Arm),
              command_ShooterFeedOutput(Shooter, [=]{return intakePower;}),
              command_DriveByDistance(Drive, inchesToFirstBall, timeout),
              command_TurnByDegrees(Drive, degressToSecondBall),
              command_DriveByDistance(Drive, inchesToSecondBall, timeout),
              command_ArmByPositionUp(Arm),
              command_ShooterFeedOutput(Shooter, [=]{return 0;}),
              command_TurnByDegrees(Drive, degreesToPerpLine),
              command_DriveByDistance(Drive, inchesToPerpLine, timeout),
              command_TurnByDegrees(Drive, degreesToHub),
              command_DriveByDistance(Drive, inchesToHub, timeout),
              command_ShooterFeedOutput(Shooter, [=]{return intakePower;}),
              command_Timer(time),
              command_ShooterFeedOutput(Shooter, [=]{return 0;}) );

}
