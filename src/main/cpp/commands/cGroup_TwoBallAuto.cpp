// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/cGroup_TwoBallAuto.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
cGroup_TwoBallAuto::cGroup_TwoBallAuto(subsystem_Drive* Drive, subsystem_Shooter* Shooter, subsystem_Arm* Arm,  
  double intakePower,  
  int inchesToBall,
  double timeout,
  double degreesToHub,
  int inchesToHub,
  double time, 
  int inchesFromTarmac) {

    AddCommands(
                command_ArmByPositionDown(Arm), 
                command_ShooterFeedOutput(Shooter, [=]{return intakePower;}, [=]{return true;}), 
                command_DriveByDistance(Drive, inchesToBall, timeout), 
                command_ShooterFeedOutput(Shooter, [=]{return 0;}, [=]{return true;}), 
                command_ArmByPositionUp(Arm), 
                command_DriveByDistance(Drive, -1 * inchesToBall, timeout),
                cGroup_OneBallAuto(Drive, Shooter, Arm, degreesToHub, inchesToHub, timeout, -1 , time, 0.0, inchesFromTarmac)   );


   

  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
}
