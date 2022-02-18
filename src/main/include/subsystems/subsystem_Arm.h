// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include "ctre/Phoenix.h"
#include <frc2/command/SubsystemBase.h>
#include "Constants.h"

class subsystem_Arm : public frc2::SubsystemBase {
 public:
  subsystem_Arm();
  void SetArmPosition(int ticks);


  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  TalonSRX m_ArmMotor;
  int m_ArmEncoderRange;
  int m_ArmLimitOffset;
  int m_ArmMaxTicks;
  int m_ArmMinTicks;


  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
