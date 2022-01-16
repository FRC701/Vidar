// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>

#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"
#include <subsystems/Intake.h>
#include "subsystems/Climber.h"
#include "frc/smartdashboard/SmartDashboard.h"

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

static constexpr int kInsideClimberMotorLeft{0};
static constexpr int kOutsideClimberMotorLeft{5};
static constexpr int kInsideClimberMotorRight{6};
static constexpr int kOutsideClimberMotorRight{8};

  frc2::Command* GetAutonomousCommand();

  static constexpr int kIntakeleft{5};
  static constexpr int kIntakeright{10};

 private:

  WPI_TalonFX IntakeLeft{kIntakeleft};
  WPI_TalonFX IntakeRight{kIntakeright};
  Intake mIntake{IntakeLeft, IntakeRight};

 WPI_TalonFX InsideMotorLeft{kInsideClimberMotorLeft};
 WPI_TalonFX InsideMotorRight{kInsideClimberMotorRight};
 WPI_TalonFX OutsideMotorLeft{kOutsideClimberMotorLeft};
 WPI_TalonFX OutsideMotorRight{kOutsideClimberMotorRight};
 Climber mClimber{InsideMotorLeft, InsideMotorRight, OutsideMotorLeft, OutsideMotorRight};

  // The robot's subsystems and commands are defined here...
  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;

  void ConfigureButtonBindings();
};
