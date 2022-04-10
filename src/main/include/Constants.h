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
    constexpr int pigeonPort = 15;

    constexpr int leftEncoderPort = 13;
    constexpr int rightEncoderPort = 2;


    constexpr double skimGain = 0.8;
    constexpr double turnGain = 2;

    constexpr double snuggleCurrent = 40;

    constexpr double velocityRPM = 3840.0;
    constexpr double turnPower = 0.4;
    constexpr double turnTimeout = 15;
}

namespace ArmConstants
{
    constexpr int ArmMotorPort = 3;
    

    constexpr double ArmEncoderMax = 0;
    constexpr double ArmEncoderMin = 0;
    constexpr double ArmEncoderLimitPercent = 10;


    constexpr double ArmVelocity = 320;
    constexpr double ArmAcceleration = 320;

//VALUES USED FOR COMMANDS
    constexpr int ArmTicksUp = 0;
    constexpr int ArmTicksDown = -30;
}

namespace ShooterConstants
{
    constexpr int intakeMotorPort = 11;
    constexpr double shooterkF = 0;
    constexpr double shooterkP = 0.1;
    constexpr double shooterkD = 0;
    constexpr double shooterFeedInPower = 0.8;
    constexpr double shooterFeedOutPower = -1;

    constexpr double Shooter_kF = 0.1;
    constexpr double Shooter_kP = 0.1;
    constexpr double Shooter_kI = 0;
    constexpr double Shooter_kD = 0;

  //  constexpr double ShooterVelocity = 0;
  //  constexpr double ShooterAcceleration = .8;
}

namespace ClimbConstants
{
    constexpr int leftWinchMotorPort = 12;
    constexpr int rightWinchMotorPort = 4;

    constexpr int leftSolenoidPort = 8;
    constexpr int rightSolenoidPort = 7;
    

    constexpr double Climb_kF = 0.7;
    constexpr double Climb_kP = 0.2;
    constexpr double Climb_kI = 0;
    constexpr double Climb_kD = 0;

    constexpr double Climb_kF_DOWN = 0.7;
    constexpr double Climb_kP_DOWN = 0.2;

    constexpr bool LeftWinchMotor = false;
    constexpr bool RightWinchMotor = true;

    constexpr double UnlockSolenoidTime = 1;

    constexpr double currentSpike = 40;

    constexpr int ClimbVelocity = 0;
    constexpr int ClimbAcceleration = 0;  

    constexpr int ClimbTicksCrement = 100;
}

namespace ControllerConstants
{
    constexpr int xboxPortDriveRad = 0;
    constexpr int xboxPortYaperator = 1;

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

    constexpr int atk3WinchLock = 6;
    constexpr int atk3WinchUnlock = 7;
    constexpr int atk3WinchUp = 10;
    constexpr int atk3WinchDown = 11;
    constexpr int atk3WinchUpTest = 3;
    constexpr int atk3WinchDownTest = 2;
    constexpr int atk3YAxis = 1;
}
