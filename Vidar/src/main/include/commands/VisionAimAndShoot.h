// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "subsystems/Shooter.h"
#include "subsystems/Chassis.h"

class VisionAimAndShoot
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 VisionAimAndShoot> {
 public:
  VisionAimAndShoot(Shooter& mShooter, Chassis& mChassis);

  private:

Shooter& mShooter;
Chassis& mChassis;
};
