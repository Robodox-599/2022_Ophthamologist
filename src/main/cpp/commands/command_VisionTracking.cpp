// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_VisionTracking.h"

command_VisionTracking::command_VisionTracking(subsystem_Vision *vision, subsystem_Drive *drive) : m_vision(vision), m_drive(drive)
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_vision);
  AddRequirements(m_drive);
} 

// Called when the command is initially scheduled.
void command_VisionTracking::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void command_VisionTracking::Execute()
{
  double turn = 0;
  double power = 0;
  if (m_vision->isVisionOnline() && m_vision->getBlocks(0.65, 1.35, (int)(frc::SmartDashboard::GetNumber("Alliance  (Blue - 1, Red - 2): ", 0))).size() > 0)
  {
    PixyBlock desiredBlock = m_vision->getDesiredBlock(m_vision->getBlocks(0.65, 1.35, (int)(frc::SmartDashboard::GetNumber("Alliance  (Blue - 1, Red - 2): ", 0))));

    turn = kT * atan(desiredBlock.getX() / desiredBlock.getY());
    power = (-1 * pMax / wMax) * desiredBlock.getW() + pMax;

    frc::SmartDashboard::PutNumber("Width: ", desiredBlock.getW());
    frc::SmartDashboard::PutNumber("X: ", desiredBlock.getX());
    frc::SmartDashboard::PutNumber("Y: ", desiredBlock.getY());
    frc::SmartDashboard::PutNumber("Turn: ", turn); 
    frc::SmartDashboard::PutNumber("Powa: ", power);

    m_drive->DriveByPower(turn, power);
    printf("working");
    
  }
  else{
    turn = 0;
    power = 0;
    m_drive->DriveByPower(turn, power);
  }
}

// Called once the command ends or is interrupted.p
void command_VisionTracking::End(bool interrupted) {}

// Returns true when the command should end.
bool command_VisionTracking::IsFinished()
{
  return false;
}
