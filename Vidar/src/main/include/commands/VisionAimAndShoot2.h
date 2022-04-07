// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/ParallelDeadlineGroup.h>
#include "subsystems/Chassis.h"
#include "subsystems/Shooter.h"
#include "subsystems/Feeder.h"

class VisionAimAndShoot2
    : public frc2::CommandHelper<frc2::ParallelDeadlineGroup,
                                 VisionAimAndShoot2> {
 public:
  VisionAimAndShoot2(Shooter& mShooter, Chassis& mChassis, Feeder& mFeeder);

private:
Shooter& mShooter;
Chassis& mChassis;
Feeder& mFeeder;
};
