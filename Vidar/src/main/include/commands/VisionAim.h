// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/PIDCommand.h>

#include "subsystems/Chassis.h"

// VisionAim is a command that uses PID to aim the chassis at the target
// The input to the PID is vision information from the Limelight
// The output is the chassis moving right and left
class VisionAim
    : public frc2::CommandHelper<frc2::PIDCommand, VisionAim> {
 public:
  VisionAim(Chassis& chassis);

  bool IsFinished() override;
private:
  Chassis& mChassis;
};
