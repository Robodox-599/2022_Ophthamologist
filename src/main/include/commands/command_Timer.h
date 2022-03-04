// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/Timer.h>


/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class command_Timer
    : public frc2::CommandHelper<frc2::CommandBase, command_Timer> {
 public:
<<<<<<<< HEAD:src/main/include/commands/command_Timer.h
  command_Timer(double Time);
========
  /**
   * Creates a new ExampleCommand.
   *
   * @param subsystem The subsystem used by this command.
   */
  explicit ExampleCommand(ExampleSubsystem* subsystem);
  
void Initialize() override;

void Execute() override;

void End(bool interrupted) override;

bool IsFinished() override;
>>>>>>>> 113b445ca4f2a53d904bf70f4ab1dd74b1cec125:src/main/include/commands/ExampleCommand.h

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  private:
  frc::Timer m_Timer;
  double m_Time;
};
