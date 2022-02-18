// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/subsystem_Arm.h"

subsystem_Arm::subsystem_Arm() : m_ArmMotor(1){
    m_ArmMotor.Set(ControlMode::PercentOutput, 0);
    m_ArmMotor.SetInverted(false);
    m_ArmMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
    m_ArmMotor.SetSensorPhase(true);
    m_ArmMotor.Config_kF(0, ArmConstants::Arm_kF, 0);
    m_ArmMotor.Config_kP(0, ArmConstants::Arm_kP, 0);
    m_ArmMotor.Config_kI(0, ArmConstants::Arm_kI, 0);
    m_ArmMotor.Config_kD(0, ArmConstants::Arm_kD, 0);
    m_ArmMotor.ConfigMotionCruiseVelocity(1250);
    m_ArmMotor.ConfigMotionAcceleration(1250);

    // m_climbArmEncoderRange = ClimbConstants::climbArmEncoderMax-ClimbConstants::climbArmEncoderMin;

    // m_climbArmLimitOffset = (m_climbArmEncoderRange)*(ClimbConstants::climbArmEncoderLimitPercent/100);
    // m_climbArmLimitMax = ClimbConstants::climbArmEncoderMax - m_climbArmLimitOffset;
    // m_climbArmLimitMin = ClimbConstants::climbArmEncoderMin + m_climbArmLimitOffset;

    // m_climbArmMotor.ConfigForwardSoftLimitThreshold((int)round(m_climbArmLimitMax));
    // m_climbArmMotor.ConfigReverseSoftLimitThreshold((int)round(m_climbArmLimitMin));
    // m_climbArmMotor.ConfigForwardSoftLimitEnable(true);
    // m_climbArmMotor.ConfigReverseSoftLimitEnable(true); 

    //built_different
}

void subsystem_Arm::SetArmPosition(int ticks){
    m_ArmMotor.Set(ControlMode::Position,ticks);
}


// This method will be called once per scheduler run
void subsystem_Arm::Periodic() {
    
}
