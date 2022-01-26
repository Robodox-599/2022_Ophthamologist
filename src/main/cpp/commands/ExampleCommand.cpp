// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ExampleCommand.h"

ExampleCommand::ExampleCommand(ExampleSubsystem* subsystem)
    : m_subsystem{subsystem} {
    }

// Called when the command is initially scheduled.
void ExampleCommand::Initialize() {
        printf("test");
}

// Called repeatedly when this Command is scheduled to run
void ExampleCommand::Execute() {

}

// Called once the command ends or is interrupted.
void ExampleCommand::End(bool interrupted) {}

// Returns true when the command should end.
bool ExampleCommand::IsFinished() { return true; }

