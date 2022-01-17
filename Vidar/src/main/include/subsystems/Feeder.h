// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
class Feeder : public frc2::SubsystemBase {
 public:
  Feeder(WPI_TalonFX& FeederLeft, WPI_TalonFX& FeederRight);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  double FeederSpin(double speed);
 private:
 WPI_TalonFX& FeederLeft;
 WPI_TalonFX& FeederRight;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};