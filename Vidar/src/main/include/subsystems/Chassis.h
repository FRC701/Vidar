// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <cstddef>

#include <ctre/phoenix/motion/MotionProfileStatus.h>
#include <ctre/phoenix/motion/SetValueMotionProfile.h>
#include <ctre/phoenix/motion/TrajectoryPoint.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonFX.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/Notifier.h>
#include <frc2/command/SubsystemBase.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>
#include <ctre/phoenix/motorcontrol/can/TalonFX.h>

class Chassis : public frc2::SubsystemBase {
 public:
  Chassis();
  using WPI_TalonFX = ctre::phoenix::motorcontrol::can::WPI_TalonFX;
  using MotionProfileStatus = ctre::phoenix::motion::MotionProfileStatus;
  using SetValueMotionProfile = ctre::phoenix::motion::SetValueMotionProfile;
  using TrajectoryPoint = ctre::phoenix::motion::TrajectoryPoint;

  Chassis(WPI_TalonFX& leftFront, WPI_TalonFX& leftRear, WPI_TalonFX& rightFront, WPI_TalonFX& rightRear);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void TankDrive(double left, double right);
  void SlowTankDrive(double left, double right);
  void ArcadeDrive(double speed, double rotation);

  double GetLeftVelocity();
  double GetRightVelocity();

  double GetRightPos();
  double GetLeftPos();

  void ResetLeftPos();
  void ResetRightPos();

  double TargetOffset();
  double TargetDistance();

  void limeLightLightsOn(); 
 
 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
    WPI_TalonFX& leftFront;
    WPI_TalonFX& leftRear;
    WPI_TalonFX& rightFront;
    WPI_TalonFX& rightRear;
    frc::DifferentialDrive mDrive;
    };
