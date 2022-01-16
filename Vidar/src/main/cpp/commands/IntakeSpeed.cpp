#include "commands/IntakeSpeed.h"

IntakeSpeed::IntakeSpeed(Intake& intake, double motorSpeed)
: mIntake(intake)
, motorSpeed(motorSpeed)
{
}


void IntakeSpeed::Initialize() {}

void IntakeSpeed::Execute() 
{
  mIntake.IntakeSpin(motorSpeed);
}

void IntakeSpeed::End(bool interrupted) 
{
  mIntake.IntakeSpin(0.);
}

bool IntakeSpeed::IsFinished() {
return false;
}
