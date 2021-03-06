// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonFX.h>

class Shooter : public frc2::SubsystemBase {
 public:
  Shooter(WPI_TalonFX& flywheelMotor1, WPI_TalonFX& flywheelMotor2);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  // SpinFlywheel as percent output
  double SpinFlywheel(double speed);
  // SpinFlwheel at RPM
  double SpinFlywheelRPM(double speedRPM);
  double FlywheelVelocity();
  double FlywheelVelocityRPM();
  bool IsReadyToShoot();
  double ResetVelocity();
  
 private:
 WPI_TalonFX& mFlywheelMotor1;
 WPI_TalonFX& mFlywheelMotor2;
 int mutable mThresholdLoops;

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
