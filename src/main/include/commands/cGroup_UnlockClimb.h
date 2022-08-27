// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "commands/command_SetClimbByPower.h"
#include "commands/command_Timer.h"
#include "commands/command_UnlockSolenoid.h"


#include "subsystems/subsystem_Climb.h"

class cGroup_UnlockClimb
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 cGroup_UnlockClimb> {
 public:
  cGroup_UnlockClimb(subsystem_Climb* Climb);

};
