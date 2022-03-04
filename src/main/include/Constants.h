// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */
namespace DriveConstants
{
<<<<<<< HEAD
    constexpr int frontLeftMotorPort = 3;
    constexpr int rearLeftMotorPort = 4;
    constexpr int frontRightMotorPort = 2;
    constexpr int rearRightMotorPort = 1;
=======
    constexpr int frontLeftMotorPort = 1;
    constexpr int rearLeftMotorPort = 2;
    constexpr int frontRightMotorPort = 4;
    constexpr int rearRightMotorPort = 3;
>>>>>>> 64798c9f81b6832c9614965e53afb6ed13c9fd2c

    constexpr int leftEncoderPort = 1;
    constexpr int rightEncoderPort = 3;

    constexpr int pigeonPort = 0;

    constexpr double skimGain = 0.8;
<<<<<<< HEAD
    constexpr double turnGain = 0.1;

    constexpr double snuggleCurrent = 0.0;
}

namespace ArmConstants
{
    constexpr int ArmMotorPort = 3;
    

    constexpr double ArmEncoderMax = 0;
    constexpr double ArmEncoderMin = 0;
    constexpr double ArmEncoderLimitPercent = 10;


    constexpr double ArmVelocity = 20;
    constexpr double ArmAcceleration = .001;  

//VALUES USED FOR COMMANDS
    constexpr int ArmTicksUp = 100;
    constexpr int ArmTicksDown = 0;
}

namespace ShooterConstants
{
    constexpr int intakeMotorPort = 2;
    constexpr double shooterkF = 0;
    constexpr double shooterkP = 0;
    constexpr double shooterkD = 0;
    constexpr double shooterFeedInPower = 0.3;
    constexpr double shooterFeedOutPower = -0.3;
=======
    constexpr double turnGain = 0.2;
>>>>>>> 64798c9f81b6832c9614965e53afb6ed13c9fd2c
}

namespace ControllerConstants
{
    constexpr int xboxPort = 0;

    constexpr int xboxLXAxis = 0;
    constexpr int xboxLYAxis = 1;
    constexpr int xboxRXAxis = 4;
    constexpr int xboxRYAxis = 5;

    constexpr int xboxLTAxis = 2;
    constexpr int xboxRTAxis = 3;

    constexpr int xboxA = 1;
    constexpr int xboxB = 2;
    constexpr int xboxX = 3;
    constexpr int xboxY = 4;
    constexpr int xboxLB = 5;
    constexpr int xboxRB = 6;
    constexpr int xboxView = 7;
    constexpr int xboxMenu = 8;
    constexpr int xboxLeftJoyPress = 9;
    constexpr int xboxRightJoyPress = 10;
<<<<<<< HEAD
=======
    
    constexpr int xboxRightDPad = 11;
>>>>>>> 64798c9f81b6832c9614965e53afb6ed13c9fd2c
}
