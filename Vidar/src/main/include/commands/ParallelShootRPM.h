// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/ParallelCommandGroup.h>
#include "subsystems/Feeder.h"
#include "subsystems/Shooter.h"
class ParallelShootRPM
    : public frc2::CommandHelper<frc2::ParallelCommandGroup,
                                 ParallelShootRPM> {
 public:
  ParallelShootRPM(Feeder& mFeeder, Shooter& mShooter);

private:

Feeder& mFeeder;
Shooter& mShooter;
};
