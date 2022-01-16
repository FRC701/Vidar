#pragma once
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/Intake.h"

class IntakeSpeed
    : public frc2::CommandHelper<frc2::CommandBase, IntakeSpeed> {
 public:
  IntakeSpeed(Intake& intake, double motorSpeed);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;


  private:
  
  Intake& mIntake;
  double motorSpeed;

};
