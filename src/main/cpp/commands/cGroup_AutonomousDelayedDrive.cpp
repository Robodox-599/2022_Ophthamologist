// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/cGroup_AutonomousDelayedDrive.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
<<<<<<< HEAD
cGroup_AutonomousDelayedDrive::cGroup_AutonomousDelayedDrive(subsystem_Drive* Drive, int inches, double time, double timeout){ 
  AddCommands( command_Timer( time ), command_DriveByDistance( Drive, inches, timeout) );
=======
cGroup_AutonomousDelayedDrive::cGroup_AutonomousDelayedDrive(subsystem_Drive* Drive, std::function<double()> Inches, double Time){ 
  AddCommands( command_Timer( Time ), command_DriveByDistance( Drive, Inches()) );
>>>>>>> 113b445ca4f2a53d904bf70f4ab1dd74b1cec125
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
}
