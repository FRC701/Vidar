// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc/smartdashboard/SmartDashboard.h>

#include "RobotContainer.h"
#include "commands/IntakeRun.h"
#include "commands/InsideClimbersMove.h"
#include "commands/OutsideClimbersMove.h"


RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();

  frc::SmartDashboard::PutData("InsideClimbers 0.1", new InsideClimbersMove(mClimber, 0.99));
  frc::SmartDashboard::PutData("InsideClimbers 0.2", new InsideClimbersMove(mClimber, 0.2));
  frc::SmartDashboard::PutData("InsideClimbers 0.3", new InsideClimbersMove(mClimber, 0.3));
  frc::SmartDashboard::PutData("InsideClimbers 0.4", new InsideClimbersMove(mClimber, 0.4));
  frc::SmartDashboard::PutData("InsideClimbers 0.5", new InsideClimbersMove(mClimber, 0.5));
  frc::SmartDashboard::PutData("OutsideClimbers 0.1", new OutsideClimbersMove(mClimber, 0.1));
  frc::SmartDashboard::PutData("OutsideClimbers 0.2", new OutsideClimbersMove(mClimber, 0.2));
  frc::SmartDashboard::PutData("OutsideClimbers 0.3", new OutsideClimbersMove(mClimber, 0.3));
  frc::SmartDashboard::PutData("OutsideClimbers 0.4", new OutsideClimbersMove(mClimber, 0.4));
  frc::SmartDashboard::PutData("OutsideClimbers 0.5", new OutsideClimbersMove(mClimber, 0.5));

 frc::SmartDashboard::PutData("FlywheelShoot .0.1", new FlywheelShoot(mShooter, 0.1));
 frc::SmartDashboard::PutData("FlywheelShoot 0.2", new FlywheelShoot(mShooter, 0.2));
 frc::SmartDashboard::PutData("FlywheelShoot 0.3", new FlywheelShoot(mShooter, 0.3));
 frc::SmartDashboard::PutData("FlywheelShoot 0.5", new FlywheelShoot(mShooter, 0.5));
 frc::SmartDashboard::PutData("FlywheelShoot 0.9", new FlywheelShoot(mShooter, 0.9));

 frc::SmartDashboard::PutData("Intake Motor 0.10",new IntakeRun(mIntake, .10));
 frc::SmartDashboard::PutData("Intake Motor 0.20", new IntakeRun(mIntake, .20));
 frc::SmartDashboard::PutData("Intake Motor 0.30", new IntakeRun(mIntake, .30));
 frc::SmartDashboard::PutData("Intake Motor 0.40", new IntakeRun(mIntake, .40));
 frc::SmartDashboard::PutData("Intake Motor 0.50", new IntakeRun(mIntake, .50));
 frc::SmartDashboard::PutData("Intake Motor 0.60", new IntakeRun(mIntake, .60));
 frc::SmartDashboard::PutData("Intake Motor 0.70", new IntakeRun(mIntake, .70));
 frc::SmartDashboard::PutData("Intake Motor 0.80", new IntakeRun(mIntake, .80));
 frc::SmartDashboard::PutData("Intake Motor 0.90", new IntakeRun(mIntake, .90));
 frc::SmartDashboard::PutData("Intake Motor One", new IntakeRun(mIntake, 1.00));
 frc::SmartDashboard::PutData("Intake Motor 0.55", new IntakeRun(mIntake, .55));
 }

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
