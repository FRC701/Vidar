// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>

class Shooter : public frc2::SubsystemBase {
 public:
  Shooter(WPI_TalonFX& FlywheelMotor1, WPI_TalonFX& FlywheelMotor2, WPI_TalonFX& HoodMotor);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  double SpinFlywheel(double speed);
  void MoveHood(double speed);


 private:
 WPI_TalonFX& FlywheelMotor1;
 WPI_TalonFX& FlywheelMotor2;
 WPI_TalonFX& HoodMotor;

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
