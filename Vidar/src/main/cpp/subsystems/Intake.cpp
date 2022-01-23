#include "subsystems/Intake.h"

Intake::Intake(WPI_TalonFX& IntakeLeft, WPI_TalonFX& IntakeRight) 
: IntakeLeft(IntakeLeft)
, IntakeRight(IntakeRight)
{
    IntakeRight.SetInverted(false);
}


void Intake::Periodic() {}

double Intake::IntakeSpin(double speed)
{
IntakeLeft.Set(speed);
IntakeRight.Set(speed);
return speed;
}