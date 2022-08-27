// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_TurnByDegrees.h"

command_TurnByDegrees::command_TurnByDegrees(subsystem_Drive* Drive, double Degrees):
m_Drive{Drive},
m_Degrees{Degrees} {
  AddRequirements({Drive});
  // Use addRequirements() here to declare subsystem dependencies.

}

// Called when the command is initially scheduled.
void command_TurnByDegrees::Initialize() {

   m_Timer.Stop();
   m_Timer.Reset();
   m_Timer.Start();
   m_CurrentGyroAngle = m_Drive->GetGyroAngle();
   m_TargetGyroAngle = m_CurrentGyroAngle - m_Degrees;
  //  if(m_Degrees < 0){
  //    m_Drive->TurnByVelocity(-1 * DriveConstants::velocityRPM);
  //  }else{
  //    m_Drive ->TurnByVelocity(DriveConstants::velocityRPM);
  //  }
  // m_Drive->TurnByVelocity( DriveConstants::velocityRPM);
  if(m_Degrees < 0){
    m_Drive->TurnByPower(-1 * DriveConstants::turnPower);
  }else{
    m_Drive -> TurnByPower( DriveConstants::turnPower);
  }
  
}

// Called repeatedly when this Command is scheduled to run
void command_TurnByDegrees::Execute() {
  m_CurrentGyroAngle = m_Drive->GetGyroAngle();
  
 
  frc::SmartDashboard::PutNumber("Gyro Angle ", m_CurrentGyroAngle);
  frc::SmartDashboard::PutNumber("Target Gyro Angle", m_TargetGyroAngle);
}

// Called once the command ends or is interrupted.
void command_TurnByDegrees::End(bool interrupted) {
   m_Drive -> TurnByPower(0);
}

// Returns true when the command should end.
bool command_TurnByDegrees::IsFinished() {
  if(m_Degrees < 0){
   return ( m_TargetGyroAngle <= m_CurrentGyroAngle ) || ( DriveConstants::turnTimeout <= (double)m_Timer.Get() );
  }else{
    return ( m_TargetGyroAngle >= m_CurrentGyroAngle )|| ( DriveConstants::turnTimeout <= (double)m_Timer.Get() );
  }
  
  //return true;
}
