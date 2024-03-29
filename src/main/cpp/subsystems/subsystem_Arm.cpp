// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/subsystem_Arm.h"

subsystem_Arm::subsystem_Arm() : m_ArmMotor{ArmConstants::ArmMotorPort, rev::CANSparkMax::MotorType::kBrushless}{
    //arm motor set up 
    m_isRaised = true;

    double kP = 1, kI = 0, kD = 0, kIz = 0, kFF = 0, kMaxOutput = .3, kMinOutput = -.3;
    m_ArmPidController.SetP(kP);
    m_ArmPidController.SetI(kI);
    m_ArmPidController.SetD(kD);
    m_ArmPidController.SetIZone(kIz);
    m_ArmPidController.SetFF(kFF);
    m_ArmPidController.SetOutputRange(kMinOutput, kMaxOutput);
    m_ArmPidController.SetSmartMotionAccelStrategy(rev::CANPIDController::AccelStrategy::kTrapezoidal, 0);
    m_ArmPidController.SetSmartMotionMaxAccel(ArmConstants::ArmAcceleration);
    m_ArmPidController.SetSmartMotionMaxVelocity(ArmConstants::ArmVelocity);
    
    m_ArmEncoder.SetPosition(0);
    m_ArmMotor.SetInverted(true);
//    m_ArmEncoder.SetInverted(true);

    //built_different
    //thing
}
/*moves the position of the arm by the inputed amount of ticks. 
  0 ticks is the arm in the horizontal position              */
void subsystem_Arm::SetArmPosition(int ticks){
  if(ticks == ArmConstants::ArmTicksUp){
    m_isRaised = true;
  }else{
    m_isRaised = false;
  }
  m_ArmPidController.SetReference(ticks, rev::ControlType::kPosition,0);

}

void subsystem_Arm::toggleArmPosition(){
  if(m_isRaised){
    SetArmPosition(ArmConstants::ArmTicksDown);
  }else{
    SetArmPosition(ArmConstants::ArmTicksUp);
  }

}

double subsystem_Arm::GetArmPosition(){
  return m_ArmEncoder.GetPosition();
}


// This method will be called once per scheduler run
void subsystem_Arm::Periodic() {
  frc::SmartDashboard::PutNumber("POSITION", m_ArmEncoder.GetPosition());
  frc::SmartDashboard::PutNumber("CURRENT", m_ArmMotor.GetOutputCurrent());
//Stall prevention, checks the current of the motor to make sure that it isn't stuck
  if(m_ArmMotor.GetOutputCurrent() > 100){
    SetArmPosition(ArmConstants::ArmTicksUp);
  }

}
