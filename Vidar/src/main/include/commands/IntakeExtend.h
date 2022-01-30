// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>
#include "subsystems/Intake.h"
class IntakeExtend
    : public frc2::CommandHelper<frc2::InstantCommand,
                                 IntakeExtend> {
 public:
  IntakeExtend(Intake& mIntake);

  void Initialize() override;

 private:
 Intake& mIntake;
};
