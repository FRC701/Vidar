#pragma once
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/Intake.h"
#include "subsystems/Feeder.h"

class IntakeRun
    : public frc2::CommandHelper<frc2::CommandBase, IntakeRun> {
 public:
  IntakeRun(Intake& intake, Feeder& mFeeder, double motorSpeed);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;


  private:
  
  Intake& mIntake;
  Feeder& mFeeder;
  double motorSpeed;

};
