/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/subsystem_Drive.h"
<<<<<<< HEAD
#include "Constants.h"
#include <frc/Timer.h>
=======

>>>>>>> 113b445ca4f2a53d904bf70f4ab1dd74b1cec125
/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class command_DriveByDistance
    : public frc2::CommandHelper<frc2::CommandBase, command_DriveByDistance> {
 public:
<<<<<<< HEAD
  command_DriveByDistance(subsystem_Drive *theDrive, int inches, double timeout);
=======
  command_DriveByDistance(subsystem_Drive *theDrive, int inches);
>>>>>>> 113b445ca4f2a53d904bf70f4ab1dd74b1cec125

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  subsystem_Drive *m_subsystem_Drive;
  int m_inches;
  int m_errorWindow = 2;
  int m_errorWindowTargetCount = 50;
  int m_errorWindowCount = 0;
<<<<<<< HEAD
  double m_timeout;
  frc::Timer m_Timer;
=======
>>>>>>> 113b445ca4f2a53d904bf70f4ab1dd74b1cec125
};
