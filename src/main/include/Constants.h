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
namespace ClimbConstants
{
    constexpr int leftWinchMotorPort = 1;
    constexpr int rightWinchMotorPort = 2;

    constexpr int leftSolenoidPort =3;
    constexpr int rightSolenoidPort =4;
    

    constexpr double Climb_kF = 0;
    constexpr double Climb_kP = 0.1;
    constexpr double Climb_kI = 0;
    constexpr double Climb_kD = 0;

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

    constexpr int atk3WinchLock = 6;
    constexpr int atk3WinchUnlock = 7;
    constexpr int atk3WinchUp = 11;
    constexpr int atk3WinchDown = 12;
}
