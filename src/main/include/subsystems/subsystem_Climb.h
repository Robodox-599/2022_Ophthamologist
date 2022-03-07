// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"
#include "Constants.h"

class subsystem_Climb : public frc2::SubsystemBase {
 public:
  subsystem_Climb();
  void SetWinchMotorPower(double power);
  void SetWinchMotorVelocity(double velocity);
  void SetWinchMotorPosition(double inches);
  void DeviateWinchMotorPosition(double ticks);
  void LockClimb();
  void UnlockClimb();
  


  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  TalonSRX m_leftWinchMotor;
  TalonSRX m_rightWinchMotor;
  VictorSPX m_solenoid;
  double m_position;

  // int m_climbArmEncoderRange;
  // int m_climbArmLimitOffset;
  // int m_climbArmLimitMax;
  // int m_climbArmLimitMin;
};
