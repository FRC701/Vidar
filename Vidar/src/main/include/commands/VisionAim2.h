// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/controller/PIDController.h>
#include "subsystems/Chassis.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class VisionAim2
    : public frc2::CommandHelper<frc2::CommandBase, VisionAim2> {
 public:
  VisionAim2(Chassis& mChassis);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

private:

Chassis& mChassis;

frc2::PIDController controller{0.065, 0, 0.005}; 

//p-0.1 i-0.0 d-0.03 accurate but takes long

};
