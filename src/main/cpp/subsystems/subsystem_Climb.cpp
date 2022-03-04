// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/subsystem_Climb.h"

subsystem_Climb::subsystem_Climb() : 
m_leftWinchMotor(ClimbConstants::leftWinchMotorPort), 
m_rightWinchMotor(ClimbConstants::rightWinchMotorPort), 
m_leftSolenoid(ClimbConstants::leftSolenoidPort), 
m_rightSolenoid(ClimbConstants::rightSolenoidPort) {

    m_leftSolenoid.Set(ControlMode::PercentOutput, 0.0);
    m_rightSolenoid.Set(ControlMode::PercentOutput, 0.0);
    m_rightSolenoid.SetSensorPhase(false);
    m_leftSolenoid.SetSensorPhase(false);
    m_leftSolenoid.SetInverted(false);
    m_leftSolenoid.SetInverted(false);
    m_leftSolenoid.Follow(m_rightSolenoid);

    m_leftWinchMotor.Set(ControlMode::PercentOutput, 0.0);
    m_rightWinchMotor.Set(ControlMode::PercentOutput, 0.0);
    m_rightWinchMotor.SetSensorPhase(false);
    m_leftWinchMotor.SetSensorPhase(false);
    m_leftWinchMotor.SetInverted(false);
    m_rightWinchMotor.SetInverted(true);
    m_leftWinchMotor.Follow(m_rightWinchMotor); 
    

    m_rightWinchMotor.Config_kF(0, ClimbConstants::Climb_kF, 0);
    m_rightWinchMotor.Config_kP(0, ClimbConstants::Climb_kP, 0);
    m_rightWinchMotor.Config_kI(0, ClimbConstants::Climb_kI, 0);
    m_rightWinchMotor.Config_kD(0, ClimbConstants::Climb_kD, 0);
    //m_rightWinchMotor.ConfigMotionCruiseVelocity(ClimbConstants::ClimbVelocity);
    //m_rightWinchMotor.ConfigMotionAcceleration(ClimbConstants::ClimbAcceleration);   
}


void subsystem_Climb::SetWinchMotorPower(double power){
    m_rightWinchMotor.Set(ControlMode::PercentOutput, power);
}

void subsystem_Climb::SetWinchMotorPosition(double inches){
    m_rightWinchMotor.Set(ControlMode::MotionMagic, inches);
}

void subsystem_Climb::DeviateWinchMotorPosition(double ticks){
    m_position = m_position + ticks;
}



//I just guessed that this solenoid is a current to retract type beat, will need to 
//switch nums if proven otherwise
void subsystem_Climb::UnlockClimb(){
    m_rightSolenoid.Set(ControlMode::PercentOutput, 1);
}

void subsystem_Climb::LockClimb(){
    m_rightSolenoid.Set(ControlMode::PercentOutput, 0);
}



// This method will be called once per scheduler run
void subsystem_Climb::Periodic() {
    m_rightWinchMotor.Set(ControlMode::MotionMagic, m_position);
}
