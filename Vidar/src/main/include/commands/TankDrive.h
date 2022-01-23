// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <subsystems/Chassis.h>

/**
 * TankDrive command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class TankDrive
    : public frc2::CommandHelper<frc2::CommandBase, TankDrive> {
 public:
  TankDrive(Chassis& chassis, std::function<double()> left, std::function<double()> right);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
private:
  Chassis& mChassis;
  std::function<double()> mLeft;
  std::function<double()> mRight;
};