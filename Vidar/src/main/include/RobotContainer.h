// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/XboxController.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonFX.h>


#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/Chassis.h"
#include "subsystems/Intake.h"
#include "subsystems/Climber.h"
#include "subsystems/Shooter.h"
#include "commands/FlywheelShoot.h"

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

 static constexpr int kIntakeLeft{2};
 static constexpr int kIntakeRight{17};

 static constexpr int kFeederLeft{8};
 static constexpr int kFeederRight{11};

 static constexpr int kShooterFlywheelLeft{9};
 static constexpr int kShooterFlywheelRight{10};

 

  frc2::Command* GetAutonomousCommand();

 private:
 frc::XboxController driver{0};
 frc::XboxController coDriver{1};

//Chassis Stuff
  WPI_TalonFX leftFront{kChassisLeftFront};
  WPI_TalonFX leftRear{kChassisLeftRear};
  WPI_TalonFX rightFront{kChassisRightFront};
  WPI_TalonFX rightRear{kChassisRightRear};
  Chassis mChassis{leftFront, leftRear, rightFront, rightRear};

  WPI_TalonFX IntakeLeft{kIntakeLeft};
  WPI_TalonFX IntakeRight{kIntakeRight};
  Intake mIntake{IntakeLeft, IntakeRight};

  WPI_TalonFX InsideMotorLeft{kClimberLeftInside};
  WPI_TalonFX InsideMotorRight{kClimberRightInside};
  WPI_TalonFX OutsideMotorLeft{kClimberLeftOutside};
  WPI_TalonFX OutsideMotorRight{kClimberRightOutside};
  Climber mClimber{InsideMotorLeft, InsideMotorRight, OutsideMotorLeft, OutsideMotorRight};

  // The robot's subsystems and commands are defined here...
  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;

  WPI_TalonFX mFlywheelMotor{kShooterFlywheelLeft};
  Shooter mShooter{mFlywheelMotor};

  void ConfigureButtonBindings();
};
