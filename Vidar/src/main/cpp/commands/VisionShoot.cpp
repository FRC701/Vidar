// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <algorithm>

#include "commands/VisionShoot.h"
#include "commands/VisionToSpeed.h"
#include "frc/smartdashboard/SmartDashboard.h"

namespace {

using vision_shoot::VisionToSpeed;

// Recording for future information
// Low shots
// {0,  850}  Touching the hub - 850 RPM
// {5, 1250}  5 feet back from the hub, 1250 RPM 
// (there's no reference for 5 feet so not that much help)
VisionToSpeed VisionToSpeeds []
{
  {20, 0.00107, 3800},
  {15, 0.00224, 2900},
  {10, 0.00462, 2150},
  {5 , 0.00673, 1850}
};

bool isLessThanTargetAreaBySpeed(const VisionToSpeed& visionToSpeeds, double targetArea)
{
  return visionToSpeeds.targetArea < targetArea;
}

bool isLessThanTargetAreaByTargetArea(double targetArea, const VisionToSpeed& visionToSpeeds)
{
  return visionToSpeeds.targetArea < targetArea;
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

double TargetAreaToSpeed(VisionToSpeed* begin, VisionToSpeed* end, double targetArea)
{
  VisionToSpeed* lower = std::lower_bound(begin, end, targetArea, isLessThanTargetAreaBySpeed);
  VisionToSpeed* upper = std::upper_bound(begin, end, targetArea, isLessThanTargetAreaByTargetArea);

  if (lower != end && upper != end) {
    double x1 = lower->targetArea;
    double y1 = lower->speedRPM;
    double x2 = upper->targetArea;
    double y2 = upper->speedRPM;

    double m = (y2 - y1)/(x2 - x1);
    double b = y1 - m * x1;
    double y = m * targetArea + b;
    return y;
  }
  else
  {
    return 0.0;  // Sentinel value that means, something is wrong.
  }
}

double TargetAreaToSpeed(double targetarea)
{
  VisionToSpeed*
  VisionToSpeed2 = lower_bound(targetarea);  
  
  VisionToSpeed*
  VisionToSpeed1 = upper_bound(targetarea);

  double x1 = VisionToSpeed1->targetArea;
  double y1 = VisionToSpeed1->speedRPM;
  double x2 = VisionToSpeed2->targetArea;
  double y2 = VisionToSpeed2->speedRPM;

    frc::SmartDashboard::PutNumber("x1", x1);
    frc::SmartDashboard::PutNumber("y1", y1);
    frc::SmartDashboard::PutNumber("x2", x2);
    frc::SmartDashboard::PutNumber("y2", y2);


  double m = y2-y1/x2-x1;
  double b = y1-m*x1;
  double y = m*targetarea+b;
  return y;
}

} // end namespace

// Implement the additional vision_shoot namespace here for convenience.
namespace vision_shoot {

double FindSpeed(VisionToSpeed* begin, VisionToSpeed* end, double targetArea)
{
  double speedRPM = TargetAreaToSpeed(begin, end, targetArea);  
  return speedRPM;
}

} // end namespace vision_shoot


VisionShoot::VisionShoot(Shooter& shooter, Chassis& chassis) 
: mShooter(shooter)
, mChassis(chassis)
{
  AddRequirements(&mShooter);
}

// Called when the command is initially scheduled.
void VisionShoot::Initialize() {
    double targetArea = mChassis.TargetDistance();
    mspeed = TargetAreaToSpeed(targetArea);
  frc::SmartDashboard::PutNumber("Target Area VS", targetArea);
  frc::SmartDashboard::PutNumber("Target Speed VS", mspeed);
}

// Called repeatedly when this Command is scheduled to run
void VisionShoot::Execute() 
{
    mShooter.SpinFlywheelRPM(mspeed); // Change to SpinFlywheelRPM
}


// Called once the command ends or is interrupted.
void VisionShoot::End(bool interrupted) {}

// Returns true when the command should end.
bool VisionShoot::IsFinished() {
  return false;
}
