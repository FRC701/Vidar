// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; y'ou can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc/smartdashboard/SmartDashboard.h>

#include <frc2/command/button/Trigger.h>
#include <frc2/command/button/JoystickButton.h>
#include "RobotContainer.h"
#include "commands/IntakeRun.h"
#include "commands/InsideClimbersMove.h"
#include "commands/OutsideClimbersMove.h"
#include "commands/SpinFeeder.h"
#include "commands/TankDrive.h"
#include "commands/AutoEndIntake.h"
#include "commands/RunIntake.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here
  // Configure the button bindings

  // mIntake.SetDefaultCommand(AutoEndIntake(mIntake, mFeeder));

  ConfigureButtonBindings();
  {
    frc2::Button coA {[this]{return coDriver.GetRawButton(1);}};
    frc2::Button coB {[this]{return coDriver.GetRawButton(2);}};
    frc2::Button coX {[this]{return coDriver.GetRawButton(3);}};
    frc2::Button coY {[this]{return coDriver.GetRawButton(4);}};
    coA.ToggleWhenPressed(FlywheelShoot(mShooter, 0.75));
    coB.ToggleWhenPressed(FlywheelShoot(mShooter, 0.75));
    coY.ToggleWhenPressed(FlywheelShoot(mShooter, 0.75));
    coX.ToggleWhenPressed(RunIntake(mIntake, mFeeder));

  mChassis.SetDefaultCommand
  (
    TankDrive
    (
      mChassis,
      [this] { return -1.0*driver.GetLeftY(); },
      [this] { return -1.0*driver.GetRightY(); }
    )
  );
  }

  frc::SmartDashboard::PutData("InsideClimbers 0.25", new InsideClimbersMove(mClimber, 0.25));
  frc::SmartDashboard::PutData("InsideClimbers 0.5", new InsideClimbersMove(mClimber, 0.5));
  frc::SmartDashboard::PutData("InsideClimbers 0.75", new InsideClimbersMove(mClimber, 0.75));

  frc::SmartDashboard::PutData("OutsideClimbers 0.25", new OutsideClimbersMove(mClimber, 0.25));
  frc::SmartDashboard::PutData("OutsideClimbers 0.5", new OutsideClimbersMove(mClimber, 0.5));
  frc::SmartDashboard::PutData("OutsideClimbers 0.75", new OutsideClimbersMove(mClimber, 0.75));

  frc::SmartDashboard::PutData("FlywheelShoot 0.1", new FlywheelShoot(mShooter, 0.1));
  frc::SmartDashboard::PutData("FlywheelShoot 0.2", new FlywheelShoot(mShooter, 0.2));
  frc::SmartDashboard::PutData("FlywheelShoot 0.3", new FlywheelShoot(mShooter, 0.3));
  frc::SmartDashboard::PutData("FlywheelShoot 0.5", new FlywheelShoot(mShooter, 0.5));
  frc::SmartDashboard::PutData("FlywheelShoot 0.9", new FlywheelShoot(mShooter, 0.9));

 frc::SmartDashboard::PutData("Intake Motor 0.25", new IntakeRun(mIntake, mFeeder, .25));
 frc::SmartDashboard::PutData("Intake Motor 0.50", new IntakeRun(mIntake, mFeeder, .50));
 frc::SmartDashboard::PutData("Intake Motor 0.75", new IntakeRun(mIntake, mFeeder, .75));

 frc::SmartDashboard::PutData("Run Intake Sequence", new RunIntake(mIntake, mFeeder));

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
