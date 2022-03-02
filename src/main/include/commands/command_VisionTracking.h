// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "frc/smartdashboard/SmartDashboard.h"
#include "subsystems/subsystem_Drive.h"
#include "subsystems/subsystem_Vision.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class command_VisionTracking
    : public frc2::CommandHelper<frc2::CommandBase, command_VisionTracking> {
 public:
  command_VisionTracking(subsystem_Vision *vision, subsystem_Drive *drive);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
 private:
  subsystem_Vision *m_vision;
  subsystem_Drive *m_drive;
  static constexpr double kT = 0.63661977236;
  static constexpr double turnTest = 0.15; 
  static constexpr double pMax = 0.15;
  static constexpr double wMax = 314; 
};
