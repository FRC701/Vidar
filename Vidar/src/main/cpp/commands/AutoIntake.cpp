// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoIntake.h"

#include <frc2/command/InstantCommand.h>
#include "commands/RunIntake.h"
#include "commands/AutoTaxi.h"
#include "commands/SpinFeeder.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
AutoIntake::AutoIntake(Intake& intake, Feeder& feeder, Chassis& chassis)
    : CommandHelper(AutoTaxi(chassis, 
            units::second_t(6.2),
            0.425, 
            0.425, 
            -0.425))
          // The deadline comand
          , mIntake(intake)
          , mFeeder(feeder)
          , mChassis(chassis)
{
  // Add your commands here, e.g.
  //AddRequirements(&mIntake);
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(RunIntake(mIntake, mFeeder, 0.40), SpinFeeder(mFeeder, 0.4));
}
