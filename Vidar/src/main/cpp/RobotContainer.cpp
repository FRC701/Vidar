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
#include "commands/VisionAimAndShoot.h"
#include "commands/ParallelShoot.h"
#include "commands/ParallelShootRPM.h"
#include "commands/ParallelFlywheelShoot.h"

#include "commands/AutoTaxi.h"
#include "commands/AutoSimpleTaxiShoot.h"
#include "commands/AutoOneShotTaxi.h"
#include "commands/ParallelVisionShoot.h"
#include "commands/ShortShotDeadline.h"
#include "commands/LockTuskanClimbers.h"
#include "commands/UnlockTuskanClimbers.h"
#include "commands/TRleft.h"
#include "commands/TRright.h"
#include "commands/VisionAim2.h"
#include "commands/NormalVisionShoot.h"
#include "commands/VisionAimAndShoot2.h"
#include "commands/VisionFeeder.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here
  // Configure the button bindings


  //Auto Chooser
  mChooser.AddOption("Auto Taxi And Shoot", &mAutoSimpleTaxiShoot);
  mChooser.AddOption("Auto Taxi", &mAutoTaxi);
  mChooser.AddDefault("Auto Taxi and Shoot Once", &mAutoOneShotTaxi);

  frc::SmartDashboard::PutData("Autonomous Chooser", &mChooser);

  //Default Commands
  mShooter.SetDefaultCommand(FlywheelShootRPM(mShooter, 2000));
  mIntake.SetDefaultCommand(AutoEndIntake(mIntake, mFeeder));
  mFeeder.SetDefaultCommand(SpinFeeder(mFeeder, 0.5));
  mClimber.SetDefaultCommand
  (
    Climbers
    (
      mClimber, 
      [this] { return .15*coDriver.GetRightX(); },
      [this] { return .70*coDriver.GetLeftY(); }
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
  

  frc::SmartDashboard::PutData("Vision Aim", new VisionAim(mChassis));
  frc::SmartDashboard::PutData("Vision Shoot", new VisionShoot(mShooter, mChassis));
 // frc::SmartDashboard::PutData("Vision Aim and Shoot", new VisionAimAndShoot(mShooter, mChassis));
  frc::SmartDashboard::PutData("Parallel Vision Aim and Shoot", new ParallelVisionShoot(mChassis, mFeeder, mShooter));


  frc::SmartDashboard::SetDefaultNumber("Set Flywheel VelocityRPM", 0);

  frc::SmartDashboard::PutData("SetFlywheelRPM", new SetFlywheelRPM(mShooter));
  frc::SmartDashboard::PutData("Run Parallel Shooter", new ParallelShootRPM(mFeeder, mShooter, 1500));

  frc::SmartDashboard::PutData("IntakeExtend", new IntakeExtend(mIntake));
  frc::SmartDashboard::PutData("IntakeRetract", new IntakeRetract(mIntake));
 
  frc::SmartDashboard::PutData("Run Intake Sequence", new RunIntake(mIntake, mFeeder, 0.40));
 
  frc::SmartDashboard::PutData("TRright down", new TRright(mClimber, -0.1));
  frc::SmartDashboard::PutData("TRleft down", new TRleft(mClimber, -0.1));
  frc::SmartDashboard::PutData("TRright up", new TRright(mClimber, 0.1));
  frc::SmartDashboard::PutData("TRleft up", new TRleft(mClimber, 0.1));
 
  frc::SmartDashboard::PutData("FeederShoot 0.4", new FeederShoot(mFeeder, mShooter, 0.4, units::second_t(3.0)));
  
  frc::SmartDashboard::PutData("Only Feeder .5", new FeederSpin(mFeeder, 0.5));

  frc::SmartDashboard::PutData("Shoot 3000", new FlywheelShootRPM(mShooter, 3000));

  frc::SmartDashboard::PutData("Auto Taxi and Shoot Once", new AutoOneShotTaxi(mChassis, mShooter, mFeeder));
  frc::SmartDashboard::PutData("Auto Taxi Pick Up and Shoot Twice", new AutoSimpleTaxiShoot(mChassis, mIntake, mShooter, mFeeder));

 }

void RobotContainer::ConfigureButtonBindings()
{
    frc2::Button coA {[this]{return coDriver.GetRawButton(1);}};
    frc2::Button coB {[this]{return coDriver.GetRawButton(2);}};
    frc2::Button coX {[this]{return coDriver.GetRawButton(3);}};                                                               
    frc2::Button coY {[this]{return coDriver.GetRawButton(4);}};
    frc2::Button coBumperLeft {[this]{return coDriver.GetRawButton(5);}};
    frc2::Button coBumperRight {[this]{return coDriver.GetRawButton(6);}};

    frc2::Button coPOV0 {[this]{return coDriver.GetPOV(0);}};
    frc2::Button coPOV90 {[this]{return coDriver.GetPOV(4);}};

    
    coA.ToggleWhenPressed(ShortShotDeadline(mFeeder, mShooter, 850));    //replace 
    coB.ToggleWhenPressed(NormalVisionShoot(mShooter, mChassis, mFeeder, 2000));    //replace 
    coX.ToggleWhenPressed(RunIntake(mIntake, mFeeder, 0.40));   //keep
    coY.ToggleWhenPressed(VisionAimAndShoot(mShooter, mChassis, mFeeder));    //replace 
    //coY.ToggleWhenPressed(VisionShoot(mShooter, mChassis));
    coBumperLeft.ToggleWhenPressed(UnlockTuskanClimbers(mClimber));    //vision shooting 
    coBumperRight.ToggleWhenPressed(LockTuskanClimbers(mClimber));
    coPOV0.ToggleWhenPressed(VisionAimAndShoot(mShooter, mChassis, mFeeder));
    coPOV90.ToggleWhenPressed(VisionFeeder(mFeeder, 0.4));


    frc2::Button driverA {[this]{return driver.GetRawButton(1);}};
    frc2::Button driverB {[this]{return driver.GetRawButton(2);}};
    frc2::Button driverX {[this]{return driver.GetRawButton(3);}};                                                               
    frc2::Button driverY {[this]{return driver.GetRawButton(4);}};
    frc2::Button BumperLeft {[this]{return driver.GetRawButton(5);}};
    frc2::Button BumperRight {[this]{return driver.GetRawButton(6);}};
    driverA.WhileHeld(FlywheelShootRPM(mShooter, 0.0));
    driverB.ToggleWhenPressed(ParallelFlywheelShoot(mFeeder, mShooter));
    driverY.ToggleWhenPressed(ParallelShootRPM(mFeeder, mShooter, 2500));
    driverX.ToggleWhenPressed(RunIntake(mIntake, mFeeder, -0.40));
    BumperLeft.ToggleWhenPressed(VisionShoot(mShooter, mChassis));
}

void RobotContainer::ConfigureAutoChooser(){}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous

  return mChooser.GetSelected();
}
