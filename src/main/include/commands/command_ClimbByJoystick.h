// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/subsystem_Climb.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class command_ClimbByJoystick
    : public frc2::CommandHelper<frc2::CommandBase, command_ClimbByJoystick> {
 public:
  command_ClimbByJoystick(subsystem_Climb *theClimb, std::function<double()> yAxis);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

private:
  subsystem_Climb *m_subsystem_Climb;
  std::function<double()> m_yAxis;
};
