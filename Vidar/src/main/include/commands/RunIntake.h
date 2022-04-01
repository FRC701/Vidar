// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "subsystems/Intake.h"
#include "subsystems/Feeder.h"
class RunIntake
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 RunIntake> {
 public:
  RunIntake(Intake& mIntake, Feeder& mFeeder, double speed);

 private:
 Intake& mIntake; 
 Feeder& mFeeder;
 double speed; 
};
