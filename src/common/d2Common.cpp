
#include "D2Common.hpp"
#include <cmath>




double D2length( const double pt1[2], const double pt2[2])
{

    double length; 
    
    //(x1-x2)^2 
    double   xdiffsquare = pow(pt1[0]-pt2[0],2);
    //(y1-y2)^2 
    double   ydiffsquare = pow(pt1[1]-pt2[1],2);

    //(x1-x2)^2 + (y1-y2)^2
    length = xdiffsquare + ydiffsquare;
    //sqrt((x1-x2)^2 +(y1-y2)^2)
    length = sqrt(length);

    return length; 
}

double D2Slope(double x1, double y1, double x2, double y2)
{
    double m = (y2-y1)/(x2-x1);
    return m; 
}
