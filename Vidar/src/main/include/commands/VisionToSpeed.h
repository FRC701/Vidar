#pragma once

namespace vision_shoot {

struct VisionToSpeed
{
    double distance;
    double targetArea;
    double speedRPM;
};

// Return the linearly interpolated speed from the table identified from
// begin to end looking for targetArea. 
// 
// The table must be sorted increasing by targetArea.
//
// Return: the RPM speed to use for the specified targetArea
//   A return value of 0.0 indicates that some part of the data was unusable
//   Examples:
//   1. begin == end (the table is empty)
//   2. targetArea is before or after the begin and end. Can only target between the max and the min
double FindSpeed(VisionToSpeed* begin, VisionToSpeed* end, double targetArea);

}   // end namespace vision_shoot
