// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"

class Climber : public frc2::SubsystemBase {
 public:
  Climber(WPI_TalonFX& InsideMotorLeft, WPI_TalonFX& InsideMotorRight, WPI_TalonFX& OutsideMotorLeft, WPI_TalonFX& OutsideMotorRight);

  double Outside(double speed);
  double Inside(double speed);
  void Periodic() override;

 private:
 WPI_TalonFX& InsideMotorLeft;
 WPI_TalonFX& InsideMotorRight;
 WPI_TalonFX& OutsideMotorLeft;
 WPI_TalonFX& OutsideMotorRight;

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
