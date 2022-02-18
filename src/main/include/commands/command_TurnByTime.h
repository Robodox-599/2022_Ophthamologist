// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/subsystem_Drive.h"
#include "Constants.h"
#include <frc/Timer.h>

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class command_TurnByTime
    : public frc2::CommandHelper<frc2::CommandBase, command_TurnByTime> {
 public:
  command_TurnByTime(subsystem_Drive* Drive, std::function<double()> Turn, std::function<double()> Time);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
  subsystem_Drive* m_Drive;
  frc::Timer m_Timer;
  std::function<double()> m_Time;
  std::function<double()> m_Turn;
};
