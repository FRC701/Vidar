// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/Feeder.h"
#include "subsystems/Shooter.h"
#include <frc/Timer.h>

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class FeederShoot
    : public frc2::CommandHelper<frc2::CommandBase, FeederShoot> {
 public:
  FeederShoot(Feeder& mFeeder, Shooter& mShooter, double feederspeed, units::second_t shooterTimeout);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
private:

Feeder& mFeeder;
Shooter& mShooter;
double feederspeed;

  enum CommandState
  {
    CommandState_WaitingForBall = 0,
    CommandState_WaitingForShooter = 1,
    CommandState_Shooting = 2
  };

  CommandState mState;

  void WaitingForBall();
  void WaitingForShooter();
  void Shooting();
  units::second_t mShooterTimeout;
  frc::Timer mTimer;
  bool mTimerIsRunning; // Timer does not expose that the timer is running.

};
