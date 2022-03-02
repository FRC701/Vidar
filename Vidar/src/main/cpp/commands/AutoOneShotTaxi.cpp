// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoOneShotTaxi.h"
#include "commands/AutoTaxi.h"
#include "commands/DeadParallelShootRPM.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
AutoOneShotTaxi::AutoOneShotTaxi(Chassis& chassis, Shooter& shooter, Feeder& feeder)
: mChassis(chassis)
, mShooter(shooter)
, mFeeder(feeder)

{
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  const double ChassisFirstMovement {-0.4};
  const double LeftChassisSecondMovement {0};
  const double RightChassisSecondMovement {0};
  AddCommands(
    AutoTaxi(mChassis, 
            units::second_t(2.5),
            ChassisFirstMovement, 
            LeftChassisSecondMovement, 
            RightChassisSecondMovement),
    DeadParallelShootRPM(mFeeder, mShooter)
  );
}
