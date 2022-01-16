#pragma once
#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>


class Intake : public frc2::SubsystemBase {
  public:
    Intake(WPI_TalonFX& IntakeLeft, WPI_TalonFX& IntakeRight);

    double IntakeSpin(double speed);

    void Periodic() override;

 private:
    WPI_TalonFX& IntakeLeft;
    WPI_TalonFX& IntakeRight;
};
