// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; y'ou can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc/smartdashboard/SmartDashboard.h>

#include "RobotContainer.h"
#include "commands/IntakeSpeed.h"
#include "commands/InsideClimbersMove.h"
#include "commands/OutsideClimbersMove.h"
#include "commands/SpinFeeder.h"

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

 frc::SmartDashboard::PutData("HoodEngage .1", new HoodEngage(mShooter, 0.1));
 frc::SmartDashboard::PutData("HoodEngage .2", new HoodEngage(mShooter, 0.2));
 frc::SmartDashboard::PutData("HoodEngage .3", new HoodEngage(mShooter, 0.3));
 frc::SmartDashboard::PutData("HoodEngage .4", new HoodEngage(mShooter, 0.4));
 frc::SmartDashboard::PutData("HoodEngage .5", new HoodEngage(mShooter, 0.5));
 frc::SmartDashboard::PutData("HoodEngage 1.0", new HoodEngage(mShooter, 1.0));
 
 frc::SmartDashboard::PutData("FlywheelShoot .0.1", new FlywheelShoot(mShooter, 0.1));
 frc::SmartDashboard::PutData("FlywheelShoot 0.2", new FlywheelShoot(mShooter, 0.2));
 frc::SmartDashboard::PutData("FlywheelShoot 0.3", new FlywheelShoot(mShooter, 0.3));
 frc::SmartDashboard::PutData("FlywheelShoot 0.5", new FlywheelShoot(mShooter, 0.5));
 frc::SmartDashboard::PutData("FlywheelShoot 0.9", new FlywheelShoot(mShooter, 0.9));
 frc::SmartDashboard::PutData("FlywheelShoot 0.75", new FlywheelShoot(mShooter, 0.75));

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

 frc::SmartDashboard::PutData("Feeder .1", new SpinFeeder(mFeeder, 0.1));
 frc::SmartDashboard::PutData("Feeder .2", new SpinFeeder(mFeeder, 0.2));
 frc::SmartDashboard::PutData("Feeder .3", new SpinFeeder(mFeeder, 0.3));
 frc::SmartDashboard::PutData("Feeder .4", new SpinFeeder(mFeeder, 0.4));
 frc::SmartDashboard::PutData("Feeder .5", new SpinFeeder(mFeeder, 0.5));
 frc::SmartDashboard::PutData("Feeder .6", new SpinFeeder(mFeeder, 0.6));
 frc::SmartDashboard::PutData("Feeder .7", new SpinFeeder(mFeeder, 0.7));
 frc::SmartDashboard::PutData("Feeder .8", new SpinFeeder(mFeeder, 0.8));
 frc::SmartDashboard::PutData("Feeder .9", new SpinFeeder(mFeeder, 0.9));
 frc::SmartDashboard::PutData("Feeder 1", new SpinFeeder(mFeeder, 1));
 }

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
