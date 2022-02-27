// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/Shooter.h"
#include "subsystems/Chassis.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelmper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 * hi 
 */
class VisionShoot
    : public frc2::CommandHelper<frc2::CommandBase, VisionShoot> {
 public:
  VisionShoot(Shooter& shooter, Chassis& chassis);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

private:
  Shooter& mShooter;
  Chassis& mChassis;

  double mspeed;
};
