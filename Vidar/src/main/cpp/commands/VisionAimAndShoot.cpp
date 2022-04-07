// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/VisionAimAndShoot.h"
#include "commands/VisionShoot.h"
#include "commands/VisionAim2.h"
#include"commands/VisionAimAndShoot2.h"
#include "frc2/command/WaitCommand.h"
#include "commands/SpinFeeder.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
VisionAimAndShoot::VisionAimAndShoot(Shooter& shooter, Chassis& chassis, Feeder& feeder)
: mShooter(shooter)
, mChassis(chassis)
, mFeeder(feeder)
{

    constexpr units::second_t ktest{.5};

  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(
    VisionAim2(mChassis),
    VisionShoot(mShooter, mChassis)
    //frc2::WaitCommand(ktest),
    //SpinFeeder(feeder, 0.40)
    //VisionAimAndShoot2(mShooter, mChassis, mFeeder)
  );
}
