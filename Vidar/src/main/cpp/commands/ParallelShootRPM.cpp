// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ParallelShootRPM.h"
#include "commands/SetFlywheelRPM.h"
#include "commands/FeederShoot.h"
#include "commands/SimpleShooting.h"
#include "commands/FlywheelShootRPM.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
ParallelShootRPM::ParallelShootRPM(Feeder& feeder, Shooter& shooter)
: CommandHelper(FeederShoot(feeder, shooter, 0.4, units::second_t(3.0)))
, mFeeder(feeder)
, mShooter(shooter)
{
  // Add your commands here, e.g.

  // AddCommands(FooCommand(), BarCommand());
  AddCommands(
    SetFlywheelRPM(mShooter)
  );
}