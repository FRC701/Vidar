// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/VisionAimAndShoot2.h"

#include <frc2/command/InstantCommand.h>

#include "commands/VisionAim2.h"
#include "commands/VisionShoot.h"
#include "commands/FeederShoot.h"
#include "commands/VisionAimAndShoot.h"
// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
VisionAimAndShoot2::VisionAimAndShoot2(Shooter& shooter, Chassis& chassis, Feeder& feeder)
    : CommandHelper(FeederShoot(mFeeder, mShooter, 0.4, units::second_t(4.0)))
      , mShooter(shooter)
      , mChassis(chassis)
      , mFeeder(feeder)
          // The deadline command
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  {
  AddCommands(
    //VisionAimAndShoot(mShooter, mChassis)
    //VisionAim2(mChassis),
    VisionShoot(mShooter, mChassis)
  );
}
