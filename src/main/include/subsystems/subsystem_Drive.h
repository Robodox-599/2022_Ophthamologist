/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"
#include "rev/CANSparkMax.h"
#include "Constants.h"


class subsystem_Drive : public frc2::SubsystemBase {
 public:
  subsystem_Drive();

  void JoystickVelocityDrive(double x, double y);
  void JoystickPowerDrive(double x, double y);
  void DriveDistance(int inches);
  double GetPIDError(int inches);


  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();


 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  rev::CANSparkMax m_frontLeftMotor;
  rev::CANSparkMax m_frontRightMotor;
  rev::CANSparkMax m_rearLeftMotor;
  rev::CANSparkMax m_rearRightMotor;

  rev::SparkMaxRelativeEncoder m_leftEncoder = m_frontLeftMotor.GetEncoder();
  rev::SparkMaxRelativeEncoder m_rightEncoder = m_frontRightMotor.GetEncoder();

  rev::SparkMaxPIDController m_leftPidController = m_frontLeftMotor.GetPIDController();
  rev::SparkMaxPIDController m_rightPidController = m_frontRightMotor.GetPIDController();


  void SetPositionControl();
  int ConvertInchesToRotations(int inches);
};
