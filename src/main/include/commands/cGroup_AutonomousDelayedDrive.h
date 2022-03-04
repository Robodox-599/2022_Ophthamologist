// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "Constants.h"
#include "subsystems/subsystem_Drive.h"
#include "commands/command_DriveByDistance.h"
#include "commands/command_Timer.h"

class cGroup_AutonomousDelayedDrive
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 cGroup_AutonomousDelayedDrive> {
 public:
  cGroup_AutonomousDelayedDrive(subsystem_Drive* Drive, int inches, double time, double timeout);

};
