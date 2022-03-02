// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/ParallelDeadlineGroup.h>
#include "subsystems/Intake.h"
#include "subsystems/Feeder.h"
#include "subsystems/Chassis.h"

class AutoIntake
    : public frc2::CommandHelper<frc2::ParallelDeadlineGroup,
                                 AutoIntake> {
 public:
  AutoIntake(Intake& mIntake, Feeder& mFeeder, Chassis& mChassis);

private:

  const double ChassisFirstMovement {0.4};
  const double LeftChassisSecondMovement {0.5};
  const double RightChassisSecondMovement {-0.5};

  Intake& mIntake;
  Feeder& mFeeder;
  Chassis& mChassis;
};
