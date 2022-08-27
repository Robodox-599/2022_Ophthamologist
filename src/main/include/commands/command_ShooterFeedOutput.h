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
class command_ShooterFeedOutput
    : public frc2::CommandHelper<frc2::CommandBase, command_ShooterFeedOutput> {
 public:
  command_ShooterFeedOutput(subsystem_Shooter *shooter, std::function<double()> power, std::function<bool()> isAuto);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  private:
    subsystem_Shooter* m_shooter;
    std::function<double()> m_power;
    std::function<bool()> m_isAuto;
};
