 // Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/subsystem_Shooter.h"

subsystem_Shooter::subsystem_Shooter(): IntakeMotor{ShooterConstants::intakeMotorPort}{
    IntakeMotor.SetInverted(false);
    IntakeMotor.SetSensorPhase(false);

    IntakeMotor.Config_kF(0, ShooterConstants::Shooter_kF, 0);
    IntakeMotor.Config_kP(0, ShooterConstants::Shooter_kP, 0);
    IntakeMotor.Config_kI(0, ShooterConstants::Shooter_kI, 0);
    IntakeMotor.Config_kD(0, ShooterConstants::Shooter_kD, 0);
    IntakeMotor.Set(ControlMode::Velocity, 0.0);

    IntakeMotor.ConfigClosedloopRamp(ShooterConstants::ClosedLoopRampRate);
    IntakeMotor.ConfigOpenloopRamp(ShooterConstants::OpenLoopRampRate);
    

   // IntakeMotor.ConfigMotionCruiseVelocity(ShooterConstants::ShooterVelocity);
   // IntakeMotor.ConfigMotionAcceleration(ShooterConstants::ShooterAcceleration); 
}

void subsystem_Shooter::SetIntakeWheelOn(double power){
    IntakeMotor.Set(ControlMode::PercentOutput, power);
}

void subsystem_Shooter::SetIntakeWheelOff(){
    IntakeMotor.Set(ControlMode::PercentOutput, 0.0);
}

void subsystem_Shooter::SetIntakeVelocity(double velocity){
    IntakeMotor.Set(ControlMode::Velocity, velocity);
}


// This method will be called once per scheduler run
void subsystem_Shooter::Periodic() {}
