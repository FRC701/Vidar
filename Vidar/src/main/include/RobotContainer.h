// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/Intake.h"
#include "subsystems/Climber.h"
#include "commands/FlywheelShoot.h"
#include "commands/HoodEngage.h"
#include "subsystems/Feeder.h"
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

 static constexpr int kFeederBottom{8};
 static constexpr int kFeederTop{11};

 static constexpr int kShooterFlywheelLeft{9};
 static constexpr int kShooterFlywheelRight{5}; //10

 static constexpr int kHoodLeft{4};
 static constexpr int kHoodRight{15};


  frc2::Command* GetAutonomousCommand();

 private:

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

  WPI_TalonFX mFlywheelMotor1{kShooterFlywheelLeft};
  WPI_TalonFX mFlywheelMotor2{kShooterFlywheelRight};
  WPI_TalonFX mHoodMotor{kHoodLeft};
  Shooter mShooter{mFlywheelMotor1, mFlywheelMotor2, mHoodMotor};

  WPI_TalonFX FeederBottom{kFeederBottom};
  WPI_TalonFX FeederTop{kFeederTop};
  Feeder mFeeder{FeederBottom, FeederTop};


  void ConfigureButtonBindings();
};
