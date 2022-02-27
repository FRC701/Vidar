// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Shooter.h"
#include "frc/smartdashboard/SmartDashboard.h"

namespace
{

  constexpr double kTicksPerRotation{2048};
  constexpr double kHundredMillisPerSecond{10};
  constexpr double kSecondsPerMin{60};

  constexpr double RPMToTicks(double rpm)
  {
    double ticks = (rpm * kTicksPerRotation) / kHundredMillisPerSecond / kSecondsPerMin;
    return ticks;
  }

  constexpr double ticksToRPM(double speed)
  {
    double rpm = (speed / kTicksPerRotation) * kHundredMillisPerSecond * kSecondsPerMin;
    return rpm;
  }

}

Shooter::Shooter(WPI_TalonFX& flywheelMotor1, WPI_TalonFX& flywheelMotor2) 
: mFlywheelMotor1(flywheelMotor1)
, mFlywheelMotor2(flywheelMotor2)
, mThresholdLoops(0)
{
  constexpr auto kMotor1IsInverted{false};
  mFlywheelMotor1.SetInverted(kMotor1IsInverted);
  mFlywheelMotor2.SetInverted(!kMotor1IsInverted);
  mFlywheelMotor2.Set(ControlMode::Follower, mFlywheelMotor1.GetDeviceID());
  mFlywheelMotor1.ConfigOpenloopRamp(1.75);
  mFlywheelMotor1.ConfigClosedloopRamp(1.75);

  constexpr int kDefaultSlotId{0};
  constexpr double kP{0.3};
  constexpr double kI{0.0003};
  constexpr double kD{0};
  constexpr double kF{0.05};

  mFlywheelMotor1.Config_kP(kDefaultSlotId, kP);
  mFlywheelMotor1.Config_kI(kDefaultSlotId, kI);
  mFlywheelMotor1.Config_kD(kDefaultSlotId, kD);
  mFlywheelMotor1.Config_kF(kDefaultSlotId, kF);
}

double Shooter::SpinFlywheel(double speed)
{
  frc::SmartDashboard::PutNumber("SpinFlywheel", speed);
  mFlywheelMotor1.Set(ControlMode::PercentOutput, speed);
  return speed;
}

double Shooter::SpinFlywheelRPM(double speedRPM)
{
  frc::SmartDashboard::PutNumber("SpinFlywheelRPM", speedRPM);
  double speed = RPMToTicks(speedRPM);
  mFlywheelMotor1.Set(ControlMode::Velocity, speed);
  return speed;
}

bool Shooter::IsReadyToShoot()
{  
    constexpr int kErrorThresholdRPM = 50;
    constexpr int kLoopsToSettle = 15;

    constexpr double kErrorThresholdTicks{RPMToTicks(kErrorThresholdRPM)};
    int loopError = mFlywheelMotor1.GetClosedLoopError();
    double target = mFlywheelMotor1.GetClosedLoopTarget();

    frc::SmartDashboard::PutNumber("Error Threshold", kErrorThresholdTicks);  
    frc::SmartDashboard::PutNumber("Loop Error", loopError);
    frc::SmartDashboard::PutNumber("Loop Target", target);

    if (loopError < kErrorThresholdTicks && loopError > -kErrorThresholdTicks)
    {
      ++mThresholdLoops;
    }
    else
    {
      mThresholdLoops = 0;
    }
    return mThresholdLoops >= kLoopsToSettle;
}

double Shooter::FlywheelVelocityRPM()
{
  double speed = FlywheelVelocity();
  double speedRPM = ticksToRPM(speed);
  return speedRPM;
}

double Shooter::FlywheelVelocity()
{
  return mFlywheelMotor1.GetSelectedSensorVelocity();
}

double Shooter::ResetVelocity() 
{
  mThresholdLoops = 0;
  return mThresholdLoops;
}

// This method will be called once per scheduler run
void Shooter::Periodic()
{
  frc::SmartDashboard::PutNumber("Flywheel Velocity", FlywheelVelocity());
  frc::SmartDashboard::PutNumber("Flywheel Velocity RPM", FlywheelVelocityRPM());
  frc::SmartDashboard::PutNumber("Flywheel Velocity RPM", FlywheelVelocityRPM());
  frc::SmartDashboard::PutNumber("Loop Target", mFlywheelMotor1.GetClosedLoopTarget());
  frc::SmartDashboard::PutNumber("Loop Error", mFlywheelMotor1.GetClosedLoopError());
  frc::SmartDashboard::PutNumber("Flywheeel Output Voltage", mFlywheelMotor1.GetMotorOutputVoltage());
  frc::SmartDashboard::PutNumber("Flywheeel Output Current", mFlywheelMotor1.GetOutputCurrent());

  frc::SmartDashboard::PutNumber("Threshold Loops", mThresholdLoops);
}
