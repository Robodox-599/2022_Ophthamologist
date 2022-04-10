// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "subsystems/subsystem_Arm.h"
#include "subsystems/subsystem_Drive.h"
#include "subsystems/subsystem_Shooter.h"

#include "commands/command_ArmByPositionDown.h"
#include "commands/command_ArmByPositionUp.h"
#include "commands/command_DriveByDistance.h"
#include "commands/command_TurnByDegrees.h"
#include "commands/command_ShooterFeedOutput.h"
#include "commands/command_ToggleArmPosition.h"
#include "commands/command_Timer.h"

class cGroup_TriangleAuto
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 cGroup_TriangleAuto> {
 public:
  cGroup_TriangleAuto(subsystem_Drive* Drive, subsystem_Shooter* Shooter, subsystem_Arm* Arm,
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
                      int inchesFromTarmac
                      );
};
