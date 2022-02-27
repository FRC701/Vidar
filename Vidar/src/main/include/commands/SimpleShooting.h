// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "subsystems/Feeder.h"
#include "subsystems/Shooter.h"
#include "frc2/command/WaitCommand.h"

class SimpleShooting
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 SimpleShooting> {
 public:
  SimpleShooting(Feeder& mFeeder/*, Shooter& mShooter*/);

private:
  Feeder& mFeeder;
  //Shooter& mShooter;
};
