#pragma once
#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/DoubleSolenoid.h>

class Intake : public frc2::SubsystemBase {
  public:
    Intake(WPI_TalonFX& IntakeLeft, WPI_TalonFX& IntakeRight, frc::DoubleSolenoid& IntakePiston);

    double IntakeSpin(double speed);

    void IntakeEngage();

    void IntakeDisengage();

    void Periodic() override;


 
 private:
    WPI_TalonFX& IntakeLeft;
    WPI_TalonFX& IntakeRight;
    frc::DoubleSolenoid& IntakePiston;
};
