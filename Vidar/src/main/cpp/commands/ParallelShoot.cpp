// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ParallelShoot.h"

#include "commands/FeederShoot.h"
#include "commands/VisionShoot.h"
#include "commands/VisionAimAndShoot.h"
#include "commands/VisionAim.h"
// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
ParallelShoot::ParallelShoot(Feeder& feeder, Shooter& shooter, Chassis& chassis)
: CommandHelper(
      FeederShoot(feeder, shooter, 0.4, units::second_t(4.0)))
, mFeeder(feeder)
,mShooter(shooter)
,mChassis(chassis)
{
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(
    //VisionAim(mChassis),
    VisionShoot(mShooter, mChassis)
  );
}
