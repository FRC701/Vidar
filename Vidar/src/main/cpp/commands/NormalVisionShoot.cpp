// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/NormalVisionShoot.h"
#include "commands/VisionAim2.h"
#include "commands/ParallelShootRPM.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
NormalVisionShoot::NormalVisionShoot(Shooter& shooter,
Chassis& chassis,
Feeder& feeder, double liam) 
: mChassis(chassis)
, mShooter(shooter)
, mFeeder(feeder)
, liam(liam)
{
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(
    VisionAim2(mChassis),
    ParallelShootRPM(mFeeder, mShooter, liam)
  );
}
