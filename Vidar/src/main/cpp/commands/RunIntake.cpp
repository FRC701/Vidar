// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/RunIntake.h"
#include "commands/IntakeExtend.h"
#include "commands/IntakeRun.h"
#include "commands/IntakeRetract.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
RunIntake::RunIntake(Intake& mIntake, Feeder& mFeeder, double speed) 
: mIntake(mIntake)
, mFeeder(mFeeder)
, speed(speed)
{
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(
    IntakeExtend(mIntake),
    IntakeRun(mIntake, mFeeder, speed)
  );
}
