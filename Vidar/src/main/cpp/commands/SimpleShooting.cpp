// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/SimpleShooting.h"
#include "commands/FeederShoot.h"
#include "commands/FeederSpin.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
SimpleShooting::SimpleShooting(Feeder& feeder/*, Shooter& shooter*/)
:mFeeder(feeder)
//,mShooter(shooter)
 {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  constexpr units::second_t ktest{2};
  AddCommands(
    frc2::WaitCommand(ktest),
    //FeederShoot(mFeeder, mShooter, 0.35, units::second_t(3.0))
    FeederSpin(mFeeder, 0.35)
  );
}
