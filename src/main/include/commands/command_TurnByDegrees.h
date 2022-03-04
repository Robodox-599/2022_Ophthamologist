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
class command_TurnByDegrees
    : public frc2::CommandHelper<frc2::CommandBase, command_TurnByDegrees> {
 public:
<<<<<<< HEAD
  command_TurnByDegrees(subsystem_Drive* Drive, double Degrees);
=======
  command_TurnByDegrees(subsystem_Drive* Drive, std::function<double()> Degrees);
>>>>>>> 64798c9f81b6832c9614965e53afb6ed13c9fd2c

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  private:
  subsystem_Drive* m_Drive;
<<<<<<< HEAD
  double m_Degrees;
=======
  std::function<double()> m_Degrees;
>>>>>>> 64798c9f81b6832c9614965e53afb6ed13c9fd2c
};
