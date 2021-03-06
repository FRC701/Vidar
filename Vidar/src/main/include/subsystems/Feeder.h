// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
class Feeder : public frc2::SubsystemBase {
 public:
  Feeder(WPI_TalonFX& feederBottom);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  bool BallIsComing();
  double FeederSpin(double speed);
  bool BallIsExiting();
 private:
 WPI_TalonFX& mFeederBottom;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
