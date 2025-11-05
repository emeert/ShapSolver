#ifndef D2COMMON_HPP
#define D2COMMON_HPP

#include <cmath>
// A global constant we wil need. For converting radians to degrees. 
const double PI = acos(-1.0);


// Calculates Euclidean distance between two 2D points
double D2length(const double pt1[2], const double pt2[2]);

// Calculates slope between two 2D points
double D2Slope(double x1, double y1, double x2, double y2);

// Add more universal 2D utilities here as needed

#endif