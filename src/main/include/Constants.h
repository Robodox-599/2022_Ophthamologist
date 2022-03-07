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
    constexpr int frontLeftMotorPort = 13;
    constexpr int rearLeftMotorPort = 14;
    constexpr int frontRightMotorPort = 2;
    constexpr int rearRightMotorPort = 1;

    constexpr int leftEncoderPort = 13;
    constexpr int rightEncoderPort = 2;

    constexpr int pigeonPort = 0;

    constexpr double skimGain = 0.8;
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
    constexpr int ArmTicksUp = 30;
    constexpr int ArmTicksDown = 0;
}

namespace ShooterConstants
{
    constexpr int intakeMotorPort = 15;
    constexpr double shooterkF = 0;
    constexpr double shooterkP = 0.1;
    constexpr double shooterkD = 0;
    constexpr double shooterFeedInPower = 0.3;
    constexpr double shooterFeedOutPower = -0.3;
}

namespace ClimbConstants
{
    constexpr int leftWinchMotorPort = 12;
    constexpr int rightWinchMotorPort = 3;

    constexpr int SolenoidPort = 7;
    

    constexpr double Climb_kF = 0.625;
    constexpr double Climb_kP = 1;
    constexpr double Climb_kI = 0;
    constexpr double Climb_kD = 0;

    constexpr double Climb_kP_DOWN = 2;
    constexpr double Climb_kF_DOWN = 0.8;



    constexpr int ClimbVelocity = 0;
    constexpr int ClimbAcceleration = 0;  

    constexpr int ClimbTicksCrement = 100;
}

namespace ControllerConstants
{
    constexpr int xboxPort = 0;
    constexpr int joystickPort = 1;

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
    constexpr int xboxRightDPad = 11;

    constexpr int atk3WinchLock = 11;
    constexpr int atk3WinchUnlock = 10;
    constexpr int atk3WinchUp = 6;
    constexpr int atk3WinchDown = 7;
    constexpr int atk3WinchUpTest = 3;
    constexpr int atk3WinchDownTest = 2;
}
