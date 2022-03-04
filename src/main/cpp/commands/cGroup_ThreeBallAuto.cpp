// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

// #include "commands/cGroup_ThreeBallAuto.h"

// // NOTE:  Consider using this command inline, rather than writing a subclass.
// // For more information, see:
// // https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
// cGroup_ThreeBallAuto::cGroup_ThreeBallAuto(subsystem_Drive* Drive, subsystem_Shooter* Shooter, subsystem_Arm* Arm, 
//   double intakePower, 
//   double time, 
//   int inchesHubToIntersection,
//   double degreesToBall,
//   int inchesToBall,
//   double timeout,
//   double degreesToIntersection,
//   int inchesBallToIntersection,
//   double degreesToHub,
//   int inchesToHub, 
//   int inchesHubToJunction,
//   double degreesToJunction,
//   int inchesToHighway,
//   double degreesToPeaPod,
//   int inchesToPeaPod,
//   int inchesFromTarmac) {
//   // Add your commands here, e.g.
//   // AddCommands(FooCommand(), BarCommand());
//   AddCommands(cGroup_TwoBallAuto(Drive, Shooter, Arm, intakePower, time, inchesHubToIntersection, degreesToBall, inchesToBall, timeout, degreesToIntersection, inchesBallToIntersection, degreesToHub, inchesToHub, inchesHubToJunction),
//               command_TurnByDegrees(Drive, degreesToJunction),
//               command_DriveByDistance(Drive, inchesToHighway, timeout),
//               command_TurnByDegrees(Drive, degreesToPeaPod),
//               command_ArmByPositionDown(Arm),
//               command_ShooterFeedOutput(Shooter, [=]{return intakePower;}),
//               command_DriveByDistance(Drive, inchesToPeaPod, timeout),
//               command_ArmByPositionUp(Arm),
//               command_ShooterFeedOutput(Shooter, [=]{return 0;}),
//               command_DriveByDistance(Drive, -1 * inchesToPeaPod, timeout),
//               command_TurnByDegrees(Drive, -1 * degreesToPeaPod),
//               command_DriveByDistance(Drive, -1 * inchesToHighway, timeout),
//               command_TurnByDegrees(Drive, -1 * degreesToJunction),
//               cGroup_OneBallAuto(Drive, Shooter, Arm, 0, inchesHubToJunction, timeout, intakePower, time, inchesFromTarmac) );
// }
