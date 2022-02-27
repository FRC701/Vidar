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
#include "commands/IntakeExtend.h"
#include "commands/IntakeRetract.h"
#include "commands/TankDrive.h"
#include "commands/AutoEndIntake.h"
#include "commands/RunIntake.h"
#include "commands/FlywheelShoot.h"
#include "commands/FeederShoot.h"
#include "commands/FlywheelShootRPM.h"
#include "commands/SetFlywheelRPM.h"
#include "commands/Climbers.h"
#include "commands/FeederSpin.h"
#include "ctre/phoenix/music/Orchestra.h"
#include "commands/VisionShoot.h"
#include "commands/VisionAim.h"
#include "commands/ParallelShoot.h"
#include "commands/ParallelShootRPM.h"
#include "commands/ParallelFlywheelShoot.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here
  // Configure the button bindings

  mShooter.SetDefaultCommand(FlywheelShoot(mShooter, 0));
  mIntake.SetDefaultCommand(AutoEndIntake(mIntake, mFeeder));
  mFeeder.SetDefaultCommand(SpinFeeder(mFeeder, 0.5));
  mClimber.SetDefaultCommand
  (
    Climbers
    (
      mClimber, 
      [this] { return 1.0*coDriver.GetRightX(); },
      [this] { return 1.0*coDriver.GetRightY(); }
    )
  );
  

  ConfigureButtonBindings();

  mChassis.SetDefaultCommand
  (
    TankDrive
    (
      mChassis,
      [this] { return -1.0*driver.GetLeftY(); },
      [this] { return -1.0*driver.GetRightY(); }
    )
  );
  


  frc::SmartDashboard::PutData("FlywheelShoot 0.1", new FlywheelShoot(mShooter, 0.1));
  frc::SmartDashboard::PutData("FlywheelShoot 0.2", new FlywheelShoot(mShooter, 0.2));
  frc::SmartDashboard::PutData("FlywheelShoot 0.3", new FlywheelShoot(mShooter, 0.3));
  frc::SmartDashboard::PutData("FlywheelShoot 0.5", new FlywheelShoot(mShooter, 0.5));
  frc::SmartDashboard::PutData("FlywheelShoot 0.9", new FlywheelShoot(mShooter, 0.9));
  frc::SmartDashboard::PutData("FlywheelShoot 1.0", new FlywheelShoot(mShooter, 1.0));

  frc::SmartDashboard::SetDefaultNumber("Set Flywheel VelocityRPM", 0);

  frc::SmartDashboard::PutData("SetFlywheelRPM", new SetFlywheelRPM(mShooter));
  frc::SmartDashboard::PutData("Run Parallel Shooter", new ParallelShootRPM(mFeeder, mShooter));
  

 frc::SmartDashboard::PutData("Intake Motor 0.25", new IntakeRun(mIntake, mFeeder, .25));
 frc::SmartDashboard::PutData("Intake Motor 0.50", new IntakeRun(mIntake, mFeeder, .50));
 frc::SmartDashboard::PutData("Intake Motor 0.75", new IntakeRun(mIntake, mFeeder, .75));

 frc::SmartDashboard::PutData("IntakeExtend", new IntakeExtend(mIntake));
 frc::SmartDashboard::PutData("IntakeRetract", new IntakeRetract(mIntake));
 
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

  frc::SmartDashboard::PutData("FeederShoot 0.4", new FeederShoot(mFeeder, mShooter, 0.4, units::second_t(3.0)));

  frc::SmartDashboard::PutData("Only Feeder .25", new FeederSpin(mFeeder, 0.25));
  frc::SmartDashboard::PutData("Only Feeder .5", new FeederSpin(mFeeder, 0.5));
  frc::SmartDashboard::PutData("Only Feeder .75", new FeederSpin(mFeeder, 0.75));
  frc::SmartDashboard::PutData("Only Feeder 1.0", new FeederSpin(mFeeder, 1.0));

  frc::SmartDashboard::PutData("Shoot 1000", new FlywheelShootRPM(mShooter, 1000));
  frc::SmartDashboard::PutData("Shoot 2000", new FlywheelShootRPM(mShooter, 2000));
  frc::SmartDashboard::PutData("Shoot 3000", new FlywheelShootRPM(mShooter, 3000));
  frc::SmartDashboard::PutData("Shoot 4000", new FlywheelShootRPM(mShooter, 4000));
  frc::SmartDashboard::PutData("Shoot 5000", new FlywheelShootRPM(mShooter, 5000));
  frc::SmartDashboard::PutData("Shoot 6000", new FlywheelShootRPM(mShooter, 6000));


 }

void RobotContainer::ConfigureButtonBindings()
{
    frc2::Button coA {[this]{return coDriver.GetRawButton(1);}};
    frc2::Button coB {[this]{return coDriver.GetRawButton(2);}};
    frc2::Button coX {[this]{return coDriver.GetRawButton(3);}};                                                               
    frc2::Button coY {[this]{return coDriver.GetRawButton(4);}};
    frc2::Button coBumperLeft {[this]{return coDriver.GetRawButton(5);}};
    frc2::Button coBumperRight {[this]{return coDriver.GetRawButton(6);}};
    coA.ToggleWhenPressed(SetFlywheelRPM(mShooter));
    coB.ToggleWhenPressed(ParallelFlywheelShoot(mFeeder, mShooter));
    coY.ToggleWhenPressed(ParallelShoot(mFeeder, mShooter, mChassis));
    coX.ToggleWhenPressed(RunIntake(mIntake, mFeeder));
    coBumperLeft.ToggleWhenPressed(ParallelFlywheelShoot(mFeeder, mShooter));
    coBumperRight.ToggleWhenPressed(FeederShoot(mFeeder, mShooter, 0.4, units::second_t(3.0)));

    // coBumperLeft.ToggleWhenPressed(new FeederShoot(mFeeder, mShooter, 0.5, units::second_t(4.0)));
    // coBumperRight.ToggleWhenPressed(new WinchHook(mWinch, kWinchNudge));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
