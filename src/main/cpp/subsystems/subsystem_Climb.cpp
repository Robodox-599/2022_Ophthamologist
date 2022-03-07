// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/subsystem_Climb.h"

subsystem_Climb::subsystem_Climb() : 
m_leftWinchMotor(ClimbConstants::leftWinchMotorPort), 
m_rightWinchMotor(ClimbConstants::rightWinchMotorPort),  
m_solenoid(ClimbConstants::SolenoidPort){

    m_solenoid.Set(ControlMode::PercentOutput, 0.0);
    m_solenoid.SetSensorPhase(false);
    m_solenoid.SetInverted(false);


    m_leftWinchMotor.Set(ControlMode::Velocity, 0);
    m_rightWinchMotor.Set(ControlMode::Velocity, 0);
    m_rightWinchMotor.SetSensorPhase(true);
    m_leftWinchMotor.SetSensorPhase(false);
    m_leftWinchMotor.SetInverted(true);
    m_rightWinchMotor.SetInverted(true);
    

    m_rightWinchMotor.Config_kF(0, ClimbConstants::Climb_kF, 0);
    m_rightWinchMotor.Config_kP(0, ClimbConstants::Climb_kP, 0);
    m_rightWinchMotor.Config_kI(0, ClimbConstants::Climb_kI, 0);
    m_rightWinchMotor.Config_kD(0, ClimbConstants::Climb_kD, 0);
    m_leftWinchMotor.Config_kF(0, ClimbConstants::Climb_kF, 0);
    m_leftWinchMotor.Config_kP(0, ClimbConstants::Climb_kP, 0);
    m_leftWinchMotor.Config_kI(0, ClimbConstants::Climb_kI, 0);
    m_leftWinchMotor.Config_kD(0, ClimbConstants::Climb_kD, 0);
    LockClimb();
    //m_rightWinchMotor.ConfigMotionCruiseVelocity(ClimbConstants::ClimbVelocity);
    //m_rightWinchMotor.ConfigMotionAcceleration(ClimbConstants::ClimbAcceleration);   
}


void subsystem_Climb::SetWinchMotorPower(double power){
    m_rightWinchMotor.Set(ControlMode::PercentOutput, power);
    m_leftWinchMotor.Set(ControlMode::PercentOutput, power);
    
}

void subsystem_Climb::SetWinchMotorVelocity(double velocity){
    if(velocity < 0){
        m_rightWinchMotor.Config_kF(0, ClimbConstants::Climb_kF, 0);
        m_rightWinchMotor.Config_kP(0, ClimbConstants::Climb_kP, 0);
        m_rightWinchMotor.Config_kI(0, ClimbConstants::Climb_kI, 0);
        m_rightWinchMotor.Config_kD(0, ClimbConstants::Climb_kD, 0);
        m_leftWinchMotor.Config_kF(0, ClimbConstants::Climb_kF, 0);
        m_leftWinchMotor.Config_kP(0, ClimbConstants::Climb_kP, 0);
        m_leftWinchMotor.Config_kI(0, ClimbConstants::Climb_kI, 0);
        m_leftWinchMotor.Config_kD(0, ClimbConstants::Climb_kD, 0);
    }else{
        m_rightWinchMotor.Config_kF(0, ClimbConstants::Climb_kF_DOWN, 0);
        m_rightWinchMotor.Config_kP(0, ClimbConstants::Climb_kP_DOWN, 0);
        m_rightWinchMotor.Config_kI(0, ClimbConstants::Climb_kI, 0);
        m_rightWinchMotor.Config_kD(0, ClimbConstants::Climb_kD, 0);
        m_leftWinchMotor.Config_kF(0, ClimbConstants::Climb_kF, 0);
        m_leftWinchMotor.Config_kP(0, ClimbConstants::Climb_kP_DOWN, 0);
        m_leftWinchMotor.Config_kI(0, ClimbConstants::Climb_kI, 0);
        m_leftWinchMotor.Config_kD(0, ClimbConstants::Climb_kD, 0);    
    }
    m_rightWinchMotor.Set(ControlMode::Velocity, velocity);
    m_leftWinchMotor.Set(ControlMode::Velocity, velocity);
    
}

void subsystem_Climb::SetWinchMotorPosition(double inches){
    m_rightWinchMotor.Set(ControlMode::Position, inches);
}

void subsystem_Climb::DeviateWinchMotorPosition(double ticks){
   // m_position = m_position + ticks;
   m_rightWinchMotor.Set(ControlMode::Position, ticks);
   m_leftWinchMotor.Set(ControlMode::Position, ticks);
   
}



//I just guessed that this solenoid is a current to retract type beat, will need to 
//switch nums if proven otherwise
void subsystem_Climb::UnlockClimb(){
    m_solenoid.Set(ControlMode::PercentOutput, 1);
}

void subsystem_Climb::LockClimb(){
    m_solenoid.Set(ControlMode::PercentOutput, 0);
}



// This method will be called once per scheduler run
void subsystem_Climb::Periodic() {
  //  m_leftWinchMotor.Set(ControlMode::MotionMagic, m_position);
  //  m_rightWinchMotor.Set(ControlMode::MotionMagic, m_position);
}

