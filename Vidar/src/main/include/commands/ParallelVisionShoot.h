// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/ParallelRaceGroup.h>
#include "subsystems/Chassis.h"
#include "subsystems/Feeder.h"
#include "subsystems/Shooter.h"

class ParallelVisionShoot
    : public frc2::CommandHelper<frc2::ParallelRaceGroup,
                                 ParallelVisionShoot> {
 public:
  ParallelVisionShoot(Chassis& chassis, Feeder& feeder, Shooter& shooter);
};
