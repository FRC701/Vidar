// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc/smartdashboard/SmartDashboard.h>

#include "RobotContainer.h"
#include "commands/IntakeSpeed.h"
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

 frc::SmartDashboard::PutData("HoodEngage .01", new HoodEngage(mShooter, 0.01));
 frc::SmartDashboard::PutData("HoodEngage .02", new HoodEngage(mShooter, 0.02));
 frc::SmartDashboard::PutData("HoodEngage .03", new HoodEngage(mShooter, 0.03));
 frc::SmartDashboard::PutData("HoodEngage .04", new HoodEngage(mShooter, 0.04));
 frc::SmartDashboard::PutData("HoodEngage .05", new HoodEngage(mShooter, 0.3));

 frc::SmartDashboard::PutData("FlywheelShoot .0.1", new FlywheelShoot(mShooter, 0.1));
 frc::SmartDashboard::PutData("FlywheelShoot 0.2", new FlywheelShoot(mShooter, 0.2));
 frc::SmartDashboard::PutData("FlywheelShoot 0.3", new FlywheelShoot(mShooter, 0.3));
 frc::SmartDashboard::PutData("FlywheelShoot 0.5", new FlywheelShoot(mShooter, 0.5));
 frc::SmartDashboard::PutData("FlywheelShoot 0.9", new FlywheelShoot(mShooter, 0.9));

 frc::SmartDashboard::PutData("Intake Motor 0.10",new IntakeSpeed(mIntake, .10));
 frc::SmartDashboard::PutData("Intake Motor 0.20", new IntakeSpeed(mIntake, .20));
 frc::SmartDashboard::PutData("Intake Motor 0.30", new IntakeSpeed(mIntake, .30));
 frc::SmartDashboard::PutData("Intake Motor 0.40", new IntakeSpeed(mIntake, .40));
 frc::SmartDashboard::PutData("Intake Motor 0.50", new IntakeSpeed(mIntake, .50));
 frc::SmartDashboard::PutData("Intake Motor 0.60", new IntakeSpeed(mIntake, .60));
 frc::SmartDashboard::PutData("Intake Motor 0.70", new IntakeSpeed(mIntake, .70));
 frc::SmartDashboard::PutData("Intake Motor 0.80", new IntakeSpeed(mIntake, .80));
 frc::SmartDashboard::PutData("Intake Motor 0.90", new IntakeSpeed(mIntake, .90));
 frc::SmartDashboard::PutData("Intake Motor One", new IntakeSpeed(mIntake, 1.00));
 frc::SmartDashboard::PutData("Intake Motor 0.55", new IntakeSpeed(mIntake, .55));
 }

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
