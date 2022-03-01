// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "subsystems/Chassis.h"
#include "subsystems/Shooter.h"
#include "subsystems/Feeder.h"

class AutoOneShotTaxi
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 AutoOneShotTaxi> {
 public:
  AutoOneShotTaxi(Chassis& mChassis, Shooter& mShooter, Feeder& mFeeder);

private:

Chassis& mChassis;
Shooter& mShooter;
Feeder& mFeeder;
};
