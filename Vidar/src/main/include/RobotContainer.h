// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/XboxController.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonFX.h>
#include <frc/DoubleSolenoid.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/Chassis.h"
#include "subsystems/Intake.h"
#include "subsystems/Climber.h"
#include "subsystems/Shooter.h"
#include "subsystems/Feeder.h"
#include "commands/AutoSimpleTaxiShoot.h"
#include "commands/AutoOneShotTaxi.h"
#include "commands/AutoTaxi.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();
  using WPI_TalonFX = ctre::phoenix::motorcontrol::can::WPI_TalonFX;

// Keep the constants sorted by ID number. (Sorting by the ID is unusual. Lists are usually sorted alphabetically.)
 
 static constexpr int kClimberLeftOutside{3};
 static constexpr int kClimberLeftInside{7};
 static constexpr int kClimberRightOutside{6};
 static constexpr int kClimberRightInside{12};

 static constexpr int kChassisLeftFront{0};
 static constexpr int kChassisLeftRear{1};
 static constexpr int kChassisRightFront{18};
 static constexpr int kChassisRightRear{19};

 static constexpr int kIntakeMotor{2};
 
 static constexpr int kFeederBottom{8};

 static constexpr int kShooterFlywheelLeft{9};
 static constexpr int kShooterFlywheelRight{10};


 static constexpr int kIntakeExtend{7};
 static constexpr int kIntakeRetract{0};

 static constexpr int kClimberExtend{6};
 static constexpr int kClimberRetract{1};


  frc2::Command* GetAutonomousCommand();

 private:
 frc::SendableChooser<frc2::Command*> mChooser;

 frc::XboxController driver{0};
 frc::XboxController coDriver{1};

//Chassis Stuff
  WPI_TalonFX leftFront{kChassisLeftFront};
  WPI_TalonFX leftRear{kChassisLeftRear};
  WPI_TalonFX rightFront{kChassisRightFront};
  WPI_TalonFX rightRear{kChassisRightRear};
  Chassis mChassis{leftFront, leftRear, rightFront, rightRear};

  WPI_TalonFX IntakeMotor{kIntakeMotor};
  frc::DoubleSolenoid IntakePiston{frc::PneumaticsModuleType::CTREPCM, kIntakeExtend, kIntakeRetract};
  Intake mIntake{IntakeMotor, IntakePiston};

  WPI_TalonFX InsideMotorLeft{kClimberLeftInside};
  WPI_TalonFX InsideMotorRight{kClimberRightInside};
  WPI_TalonFX OutsideMotorLeft{kClimberLeftOutside};
  WPI_TalonFX OutsideMotorRight{kClimberRightOutside};
  frc::DoubleSolenoid ClimberPiston{frc::PneumaticsModuleType::CTREPCM, kClimberExtend, kClimberRetract};
  Climber mClimber{InsideMotorLeft, InsideMotorRight, OutsideMotorLeft, OutsideMotorRight, ClimberPiston};

  // The robot's subsystems and commands are defined here...
  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;

  WPI_TalonFX mFlywheelMotor1{kShooterFlywheelLeft};
  WPI_TalonFX mFlywheelMotor2{kShooterFlywheelRight};
  Shooter mShooter{mFlywheelMotor1, mFlywheelMotor2};

  WPI_TalonFX mFeederBottom{kFeederBottom};
  Feeder mFeeder{mFeederBottom};

  AutoSimpleTaxiShoot mAutoSimpleTaxiShoot{mChassis, mIntake, mShooter, mFeeder};
  AutoOneShotTaxi mAutoOneShotTaxi{mChassis, mShooter, mFeeder};
  AutoTaxi mAutoTaxi{mChassis, units::second_t(5), -0.5, -0.5, -0.5};


  void ConfigureButtonBindings();
  void ConfigureAutoChooser();
};
