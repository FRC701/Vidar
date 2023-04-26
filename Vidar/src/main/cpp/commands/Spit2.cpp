// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Spit2.h"

#include <frc2/command/InstantCommand.h>
#include "frc2/command/WaitCommand.h"
#include "commands/FlywheelShoot.h"
#include "commands/FeederSpin.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
Spit2::Spit2(Shooter& shooter, Feeder& feeder)
    : CommandHelper(
      frc2::WaitCommand(units::second_t(3)))
      , mShooter(shooter), mFeeder(feeder)
      
          // The deadline command
          
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  {
  AddCommands(
    FlywheelShoot(mShooter, 0.3),
    FeederSpin(mFeeder, 0.3)
  );
}
