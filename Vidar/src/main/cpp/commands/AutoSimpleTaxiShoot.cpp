// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoSimpleTaxiShoot.h"
#include "commands/RunIntake.h"
#include "commands/DeadParallelShootRPM.h"
#include "commands/AutoTaxi.h"
#include "commands/AutoIntake.h"
#include "commands/VisionAim2.h"
// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
AutoSimpleTaxiShoot::AutoSimpleTaxiShoot(Chassis& chassis, Intake& intake, Shooter& shooter, Feeder& feeder)
: mChassis(chassis)
, mIntake(intake)
, mShooter(shooter)
, mFeeder(feeder)
{
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());

  AddCommands(
    AutoIntake(mIntake, mFeeder, mChassis),
    VisionAim2(mChassis),
    DeadParallelShootRPM(mFeeder, mShooter, 2050)
  );
}
