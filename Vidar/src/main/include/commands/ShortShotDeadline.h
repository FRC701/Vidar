// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/ParallelDeadlineGroup.h>
#include "subsystems/Feeder.h"
#include "subsystems/Shooter.h"

class ShortShotDeadline
    : public frc2::CommandHelper<frc2::ParallelDeadlineGroup,
                                 ShortShotDeadline> {
 public:
  ShortShotDeadline(Feeder& mFeeder, Shooter& mShooter, double speedrpm);
 private:
 double speedrpm;
 Feeder& mFeeder;
 Shooter& mShooter;
};
