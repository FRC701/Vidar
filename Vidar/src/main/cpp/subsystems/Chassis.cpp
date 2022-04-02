// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Chassis.h"

#include <cmath>
#include <frc/smartdashboard/SmartDashboard.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>

using ControlMode = ctre::phoenix::motorcontrol::ControlMode;
using WPI_TalonFX = ctre::phoenix::motorcontrol::can::WPI_TalonFX;



namespace {

    #ifndef M_PI
        #define M_PI		3.14159265358979323846	/* pi */
    #endif

    std::shared_ptr<nt::NetworkTable> limeLightTable = nt::NetworkTableInstance::GetDefault().GetTable("limelight");

    constexpr double kTicksPerRotation {2048};
    constexpr double kHundredMillisPerSecond {10};
    constexpr double kSecondsPerMin {60};

    constexpr double RPMToTicks(double rpm)
    {
        double ticks = (rpm * kTicksPerRotation) / kHundredMillisPerSecond / kSecondsPerMin;
        return ticks;
    }

    constexpr double kWheelDiameterInches = 6.0;
    constexpr double kWheelDiameterFeet = kWheelDiameterInches / 12.0;
    constexpr double kFeetPerRotation = 3.14159265358979323 * kWheelDiameterFeet;
    constexpr double kWheelGearTeeth = 84.0;
    constexpr double kEncoderGearTeeth = 8.0;

    [[maybe_unused]] 
    double feetToTicks(double feet) 
    {
        return feet * 13000;
    }

    
    constexpr double kMaxVelocityError{3500-3000};
    constexpr double kP{(.10*1023)/kMaxVelocityError};
    constexpr double kI{0.0};
    constexpr double kD{0.0}; // 30 is too high
    constexpr double kF{(.70 * 1023)/ RPMToTicks(3000)};

    void SetPID(WPI_TalonFX& leftFront, WPI_TalonFX& rightFront)
    {
        leftFront.Config_kP(0, kP, 10);
        leftFront.Config_kI(0, kI, 10);
        leftFront.Config_kD(0, kD, 10);
        leftFront.Config_kF(0, kF, 10);

        rightFront.Config_kP(0, kP, 10);
        rightFront.Config_kI(0, kI, 10);
        rightFront.Config_kD(0, kD, 10);
        rightFront.Config_kF(0, kF, 10);
    }


} //namespace

Chassis::Chassis(WPI_TalonFX& leftFront, WPI_TalonFX& leftRear, WPI_TalonFX& rightFront, WPI_TalonFX& rightRear)
:leftFront(leftFront)
,leftRear(leftRear)
,rightFront(rightFront)
,rightRear(rightRear)
,mDrive(leftFront, rightFront)
{
    // TODO: SetSensorPhase does not seem to be having an effect
    // The velocity is still going in reverse to the direction of travel.
    constexpr bool kLeftSensorPhase {false};
    leftFront.SetSensorPhase(kLeftSensorPhase);
    leftRear.SetSensorPhase(!kLeftSensorPhase);

    constexpr bool kLeftInvertered {false};
    leftFront.SetInverted(kLeftInvertered);
    leftRear.SetInverted(kLeftInvertered);
    rightFront.SetInverted(!kLeftInvertered);
    rightRear.SetInverted(!kLeftInvertered);

    leftFront.ConfigMotionAcceleration(1500, 10);
    leftFront.ConfigMotionCruiseVelocity(1500, 10);
    rightFront.ConfigMotionAcceleration(1500, 10);
    rightFront.ConfigMotionCruiseVelocity(1500, 10);
    leftRear.ConfigMotionAcceleration(1500, 10);
    leftRear.ConfigMotionCruiseVelocity(1500, 10);
    rightRear.ConfigMotionAcceleration(1500, 10);
    rightFront.ConfigMotionCruiseVelocity(1500, 10);
    
     leftRear.Follow(leftFront); 
     rightRear.Follow(rightFront); 

     SetPID(leftFront, rightFront);
}

// This method will be called once per scheduler run
void Chassis::Periodic() 
{
    frc::SmartDashboard::PutNumber("Left Velocity", GetLeftVelocity());
    frc::SmartDashboard::PutNumber("Right Velocity", GetRightVelocity());
    frc::SmartDashboard::PutNumber("Target Distance", TargetOffset());
    frc::SmartDashboard::PutNumber("Target Area", TargetDistance());

    frc::SmartDashboard::PutNumber("LeftChassisPosition", GetLeftPos());
    frc::SmartDashboard::PutNumber("RightChassisPosition", GetRightPos());

}

void Chassis::TankDrive(double left, double right)
{
    mDrive.TankDrive(left, right);
}

void Chassis::SlowTankDrive(double left, double right)
{
    mDrive.TankDrive(left * 0.25, right * 0.25);
}

double Chassis::GetLeftVelocity()
{
    return leftFront.GetSelectedSensorVelocity();
}

double Chassis::GetRightVelocity()
{
    return rightFront.GetSelectedSensorVelocity();
}

double Chassis::GetRightPos()
{
    return rightFront.GetSelectedSensorPosition();
}

double Chassis::GetLeftPos()
{
    return rightFront.GetSelectedSensorPosition();
}

void Chassis::ResetLeftPos()
{
    leftFront.SetSelectedSensorPosition(0);
}

void Chassis::ResetRightPos()
{
    leftFront.SetSelectedSensorPosition(0);
}

void Chassis::ArcadeDrive(double speed, double rotation)
{
    mDrive.ArcadeDrive(speed, rotation);
}

double Chassis::TargetDistance()
{
    double target = limeLightTable->GetNumber("ta", 0.0);
    return target;
}

double Chassis::TargetOffset()
{
    double target = limeLightTable->GetNumber("tx", 0.0);
    return target;
}

void Chassis::limeLightLightsOn()
{
    limeLightTable->PutNumber("ledMode", 0);
}