// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <algorithm>

#include "commands/VisionShoot.h"

namespace {

  struct VisionToSpeed
  {
    double Distance;
    double TargetArea;
    double SpeedRPM;
  };

VisionToSpeed VisionToSpeeds []
{
  {10, 2.5, 300},
  {15, 3.5, 350},
  {20, 4.5, 400},
  {25, 5.5, 450},
  {30, 6.5, 500}
};

bool isLessThanTargetAreaBySpeed(const VisionToSpeed& visionToSpeeds, double targetArea)
{
  return visionToSpeeds.TargetArea < targetArea;
}

bool isLessThanTargetAreaByTargetArea(double targetArea, const VisionToSpeed& visionToSpeeds)
{
  return visionToSpeeds.TargetArea < targetArea;
}

VisionToSpeed* lower_bound(double targetarea)
{
  return std::lower_bound(
    std::begin(VisionToSpeeds), 
    std::end(VisionToSpeeds),
    targetarea,
    isLessThanTargetAreaBySpeed);

}
VisionToSpeed* upper_bound(double targetarea)
{
  return std::upper_bound(
    std::begin(VisionToSpeeds), 
    std::end(VisionToSpeeds),
    targetarea,
    isLessThanTargetAreaByTargetArea);

}

double TargetAreaToSpeed(double targetarea)
{
  VisionToSpeed*
  VisionToSpeed1 = lower_bound(targetarea);  
  
  VisionToSpeed*
  VisionToSpeed2 = upper_bound(targetarea);

  double x1 = VisionToSpeed1->TargetArea;
  double y1 = VisionToSpeed1->SpeedRPM;
  double x2 = VisionToSpeed2->TargetArea;
  double y2 = VisionToSpeed2->SpeedRPM;
  

  double m = y2-y1/x2-x1;
  double b = y1-m*x1;
  double y = m*targetarea+b;
  return y;
}

}


VisionShoot::VisionShoot(Shooter& shooter, Chassis& chassis) 
: mShooter(shooter)
, mChassis(chassis)
{
  AddRequirements(&mShooter);
}

// Called when the command is initially scheduled.
void VisionShoot::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void VisionShoot::Execute() 
{
    double targetArea = mChassis.TargetDistance();
    double speed = TargetAreaToSpeed(targetArea);
    mShooter.SpinFlywheel(speed); // Change to SpinFlywheelRPM
}


// Called once the command ends or is interrupted.
void VisionShoot::End(bool interrupted) {}

// Returns true when the command should end.
bool VisionShoot::IsFinished() {
  return false;
}
