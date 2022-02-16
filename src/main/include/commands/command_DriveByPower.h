// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/subsystem_Drive.h"
#include "Constants.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class command_DriveByPower
    : public frc2::CommandHelper<frc2::CommandBase, command_DriveByPower> {
 public:
  command_DriveByPower(subsystem_Drive* Drive, std::function<double()> Turn, std::function<double()> Throttle);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
  subsystem_Drive* m_Drive;
  std::function<double()> m_Throttle;
  std::function<double()> m_Turn;
};
