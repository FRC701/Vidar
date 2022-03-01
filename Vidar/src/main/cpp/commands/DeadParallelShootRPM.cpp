// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DeadParallelShootRPM.h"
#include "commands/FeederShoot.h"
#include "commands/FlywheelShootRPM.h"
#include <frc2/command/InstantCommand.h>

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
DeadParallelShootRPM::DeadParallelShootRPM(Feeder& feeder, Shooter& shooter)
    : CommandHelper(FeederShoot(feeder, shooter, 0.4, units::second_t(3.0)))
          , mFeeder(feeder)
          , mShooter(shooter)
{
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(
    FlywheelShootRPM(mShooter, 3800)
  );
}
