#include "subsystems/Intake.h"

constexpr frc::DoubleSolenoid::Value kIntakeExtend {frc::DoubleSolenoid::kForward};
constexpr frc::DoubleSolenoid::Value kIntakeRetract {frc::DoubleSolenoid::kReverse};

Intake::Intake(WPI_TalonFX& intakeLeft, WPI_TalonFX& intakeRight, frc::DoubleSolenoid& intakePiston)
: IntakeLeft(intakeLeft)
, IntakeRight(intakeRight)
, IntakePiston(intakePiston)
{
    IntakeRight.SetInverted(false);
}

void Intake::Periodic() 
{}

double Intake::IntakeSpin(double speed)
{
    IntakeLeft.Set(speed);
    IntakeRight.Set(speed);
    return speed;
}

void Intake::IntakeEngage()
{
    IntakePiston.Set(kIntakeExtend);
}

void Intake::IntakeDisengage()
{
    IntakePiston.Set(kIntakeRetract);
}
