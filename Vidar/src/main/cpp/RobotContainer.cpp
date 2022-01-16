// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <commands/IntakeSpeed.h>
#include "frc/smartdashboard/SmartDashboard.h"


RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();

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
