 // Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/subsystem_Shooter.h"

subsystem_Shooter::subsystem_Shooter(){
    IntakeMotor.SetInverted(false);
};

void subsystem_Shooter::SetIntakeWheelOn(double power){
    IntakeMotor.Set(ControlMode::PercentOutput, power);
}

void subsystem_Shooter::SetIntakeWheelOff(){
    IntakeMotor.Set(ControlMode::PercentOutput, 0.0);
}
// This method will be called once per scheduler run
void subsystem_Shooter::Periodic() {}
