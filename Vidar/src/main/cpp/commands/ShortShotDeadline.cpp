// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ShortShotDeadline.h"
#include "commands/TimedSpinFeeder.h"
#include "commands/FlywheelShootRPM.h"

#include <frc2/command/InstantCommand.h>

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
ShortShotDeadline::ShortShotDeadline(Feeder& feeder, Shooter& shooter, double speedrpm)
    : CommandHelper(
      TimedSpinFeeder(0.4, feeder, units::second_t(2)))
    , mFeeder(feeder)
    , mShooter(shooter)
      {
  AddCommands(
FlywheelShootRPM(shooter, speedrpm)
      
);
}
