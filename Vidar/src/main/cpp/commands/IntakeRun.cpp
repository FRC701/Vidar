#include "commands/IntakeRun.h"

IntakeRun::IntakeRun(Intake& intake, Feeder& feeder, double motorSpeed)
: mIntake(intake)
, mFeeder(feeder)
, motorSpeed(motorSpeed)
{
  AddRequirements(&mIntake);
}
void IntakeRun::Initialize() {}

void IntakeRun::Execute() 
{
    mIntake.IntakeSpin(motorSpeed);
}

void IntakeRun::End(bool interrupted) 
{
  mIntake.IntakeSpin(0);
}

bool IntakeRun::IsFinished() {

return mFeeder.BallIsExiting();
}
