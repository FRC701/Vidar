// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ParallelFlywheelShoot.h"

#include <frc2/command/InstantCommand.h>

#include "commands/SetFlywheelRPM.h"
#include "commands/FeederShoot.h"
#include "commands/FlywheelShoot.h"
// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
ParallelFlywheelShoot::ParallelFlywheelShoot(Feeder& feeder, Shooter& shooter)
  : CommandHelper(
  FeederShoot(feeder, shooter, 0.4, units::second_t(3.0)))
  , mFeeder(feeder)
  ,mShooter(shooter)
 {
          // The deadline command
//          frc2::InstantCommand([] {})) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(
  SetFlywheelRPM(mShooter)
  
  );
}
