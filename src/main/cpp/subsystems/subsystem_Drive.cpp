/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/subsystem_Drive.h"

subsystem_Drive::subsystem_Drive() :
  m_frontLeftMotor{DriveConstants::frontLeftMotorPort, rev::CANSparkMax::MotorType::kBrushless},
  m_frontRightMotor{DriveConstants::frontRightMotorPort, rev::CANSparkMax::MotorType::kBrushless},
  m_rearLeftMotor{DriveConstants::rearLeftMotorPort, rev::CANSparkMax::MotorType::kBrushless},
  m_rearRightMotor{DriveConstants::rearRightMotorPort, rev::CANSparkMax::MotorType::kBrushless}
{
  m_frontLeftMotor.SetInverted(true);
  m_frontRightMotor.SetInverted(false);
  m_rearLeftMotor.SetInverted(true);
  m_rearRightMotor.SetInverted(false);

  m_frontLeftMotor.Set(0.0);
  m_frontRightMotor.Set(0.0);
  m_rearLeftMotor.Set(0.0);
  m_rearRightMotor.Set(0.0);

  m_leftEncoder.SetPosition(0);
  m_rightEncoder.SetPosition(0);
  // m_rearLeftMotor.Follow(m_frontLeftMotor);
  // m_rearRightMotor.Follow(m_frontRightMotor);

  int smartCurrent = 70;
  m_frontLeftMotor.SetSmartCurrentLimit(smartCurrent, smartCurrent);
  m_frontRightMotor.SetSmartCurrentLimit(smartCurrent, smartCurrent);
  m_rearLeftMotor.SetSmartCurrentLimit(smartCurrent, smartCurrent);
  m_rearRightMotor.SetSmartCurrentLimit(smartCurrent, smartCurrent);


}

void subsystem_Drive::SetPositionControl()
{
  double kP = 0.1, kI = 0, kD = 0, kIz = 0, kFF = 0, kMaxOutput = 1, kMinOutput = -1;

  m_leftPidController.SetP(kP);
  m_leftPidController.SetI(kI);
  m_leftPidController.SetD(kD);
  m_leftPidController.SetIZone(kIz);
  m_leftPidController.SetFF(kFF);
  m_leftPidController.SetOutputRange(kMinOutput, kMaxOutput);

  m_rightPidController.SetD(kD);
  m_rightPidController.SetI(kI);
  m_rightPidController.SetP(kP);
  m_rightPidController.SetIZone(kIz);
  m_rightPidController.SetFF(kFF);
  m_rightPidController.SetOutputRange(kMinOutput, kMaxOutput);
}

void subsystem_Drive::DriveDistance(int inches)
{
  SetPositionControl();
  m_leftPidController.SetReference(ConvertInchesToRotations(inches), rev::ControlType::kPosition);
  m_rightPidController.SetReference(ConvertInchesToRotations(inches), rev::ControlType::kPosition);
}

double subsystem_Drive::GetPIDError(int inches)
{
  return m_leftEncoder.GetPosition() - ConvertInchesToRotations(inches);
}

double subsystem_Drive::GetCurrentOutput(){
  return ( m_frontLeftMotor.GetOutputCurrent() + m_frontRightMotor.GetOutputCurrent() + m_rearLeftMotor.GetOutputCurrent() + m_rearRightMotor.GetOutputCurrent() ) /4.0;
}

int subsystem_Drive::ConvertInchesToRotations(int inches)
{


  //double wheelDiameter = 4;
  //double gearRatio = 7.74;


  double wheelDiameter = 6;
  double gearRatio = 10.45;
  return ((inches)/(wheelDiameter*3.14))*gearRatio;
}

void subsystem_Drive::JoystickPowerDrive(double x, double y)
{
  double l;
  double r;
  if (y > 0.2)
  {
    y = (y - 0.2) * 1 / .8;
  }
  else if (y < -0.2)
  {
    y = (y + 0.2) * 1 / .8;
  }
  else
  {
    y = 0;
  }
  if (x > 0.2)
  {
    x = (x - 0.2) * 1 / .8;
  }
  else if (x < -0.2)
  {
    x = (x + 0.2) * 1 / .8;
  }
  else
  {
    x = 0;
  }

  l = -y + x;
  r = -y - x;

  m_frontLeftMotor.Set(-l);
  m_rearLeftMotor.Set(-l);
  m_frontRightMotor.Set(r);
  m_rearRightMotor.Set(r);
}

double subsystem_Drive::Skim(double input){
  if(input > 1.0){
    return -1 * ( (input -1.0) * DriveConstants::skimGain );
  } else if ( input < -1.0){
    return -1 * ( (input + 1.0) * DriveConstants::skimGain );
  }
  return 0;
}

void subsystem_Drive::DriveByPower(double turn, double throttle){

  if (throttle > .2){
    turn = turn * (DriveConstants::turnGain * fabs(throttle));
  }
  
  double left = throttle + turn;
  double right = throttle - turn;

  double leftMotorOutput = left + Skim(right);
  double rightMotorOutput = right + Skim(left);

   m_frontLeftMotor.Set(leftMotorOutput);
   m_rearLeftMotor.Set(leftMotorOutput);
   m_frontRightMotor.Set(rightMotorOutput);
   m_rearRightMotor.Set(rightMotorOutput);
  
}

void subsystem_Drive::JoystickDrive(double x, double y){
  if (y > 0.2) {y = pow( (y - 0.2) * 1 / .8, 2);}
  else if (y <-0.2) {y = -1* pow( (y + 0.2) * 1 / .8, 2);}
  else{y = 0;}
  
  if (x > 0.2) {x = pow( (x - 0.2) * 1 / .8, 2);}
  else if (x < -0.2) {x = -1 * pow( (x + 0.2) * 1 / .8, 2);}
  else{x = 0;}

  DriveByPower(x, y);
}

void subsystem_Drive::ThrottleDrive(double ltY, double rtY, double X){

}

/*positive values are clockwise and negative values are counterclockwise*/
void subsystem_Drive::TurnByDegrees(int degrees){
  //0.0 is a place holder for the distance traveled by the wheels when making a full 360 degree turn
  double inches = degrees * (0.0 / 360.0);
  SetPositionControl();
  m_leftPidController.SetReference(ConvertInchesToRotations(inches), rev::ControlType::kPosition);
  m_rightPidController.SetReference(-1 * ConvertInchesToRotations(inches), rev::ControlType::kPosition);
  //same thing but with rotations instead of inches traveled
  // double rotations = degrees * (0.0/360.0);
  // SetPositionControl();
  // m_leftPidController.SetReference(rotations, rev::ControlType::kPosition);
  // m_rightPidController.SetReference(-1 * rotations, rev::ControlType::kPosition);
}







// This method will be called once per scheduler run
void subsystem_Drive::Periodic() {}
