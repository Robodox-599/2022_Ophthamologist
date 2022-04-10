// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include "rev/CANSparkMax.h"
#include <frc2/command/SubsystemBase.h>
#include "Constants.h"
#include <frc/smartdashboard/SmartDashboard.h>


class subsystem_Arm : public frc2::SubsystemBase {
 public:
  subsystem_Arm();
  void SetArmPosition(int ticks);
  void toggleArmPosition();
  double GetArmPosition();


  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  bool m_isRaised;
  rev::CANSparkMax m_ArmMotor;
  rev::SparkMaxRelativeEncoder m_ArmEncoder = m_ArmMotor.GetEncoder();
  rev::SparkMaxPIDController m_ArmPidController = m_ArmMotor.GetPIDController();






  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
