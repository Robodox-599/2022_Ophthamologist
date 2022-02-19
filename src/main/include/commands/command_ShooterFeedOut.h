// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/subsystem_Shooter.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class command_ShooterFeedOut
    : public frc2::CommandHelper<frc2::CommandBase, command_ShooterFeedOut> {
 public:
  command_ShooterFeedOut(subsystem_Shooter *shooter, std::function<double()> power);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  private:
    subsystem_Shooter m_shooter;
    std::function<double()> m_power;
};
