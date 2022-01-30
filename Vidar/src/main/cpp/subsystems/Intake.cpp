#include "subsystems/Intake.h"

constexpr frc::DoubleSolenoid::Value kIntakeExtend {frc::DoubleSolenoid::kForward};
constexpr frc::DoubleSolenoid::Value kIntakeRetract {frc::DoubleSolenoid::kReverse};

Intake::Intake(WPI_TalonFX& intakeMotor, frc::DoubleSolenoid& intakePiston)
: IntakeMotor(intakeMotor)
, IntakePiston(intakePiston)
{

}

void Intake::Periodic() 
{}

double Intake::IntakeSpin(double speed)
{
    IntakeMotor.Set(speed);

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
