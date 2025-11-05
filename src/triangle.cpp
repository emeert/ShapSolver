#include "triangle.hpp"
#include "D2Common.hpp" // for D2length, D2Slope
#include <iostream>
#include <cmath>

using namespace std;

void triangleGraphic(int triangle_Type)
{
    enum { acute, obtuse, right };

    switch (triangle_Type)
    {
        case acute: 
        {
            cout << "That is an acute triangle" << endl << endl;
            cout << "         *         " << endl;
            cout << "        * *        " << endl;
            cout << "       *   *       " << endl;
            cout << "      *     *      " << endl;
            cout << "     *       *     " << endl;
            cout << "    *         *    " << endl;
            cout << "   *           *   " << endl;
            cout << "  *-------------*  " << endl;
            break;
        }

        case obtuse: 
        {
            cout << "That is an obtuse triangle" << endl << endl;
            cout << "         *                       " << endl;
            cout << "        *   *                    " << endl;
            cout << "       *       *                 " << endl;
            cout << "      *           *              " << endl;
            cout << "     *               *           " << endl;
            cout << "    *                   *        " << endl;
            cout << "   *                       *     " << endl;
            cout << "  * - - - - - - - - - - - -  *   " << endl;
            break;
        }

        case right: 
        {
            cout << "That is a right triangle" << endl << endl;
            cout << "  *                            " << endl;
            cout << "  *   *                        " << endl;
            cout << "  *       *                    " << endl;
            cout << "  *           *                " << endl;
            cout << "  *               *            " << endl;
            cout << "  *                   *        " << endl;
            cout << "  *                      *     " << endl;
            cout << "  * - - - - - - - - - - - -  * " << endl;
            break;
        }
    }
}





/**
 * @brief Solves and displays geometric properties of a triangle defined by three 2D vertices.
 *
 * This function prompts the user to input three ordered pairs representing the triangle's vertices.
 * It then calculates and displays the triangle's:
 * - Side lengths
 * - Perimeter
 * - Area (using Heron's formula)
 * - Heights from each vertex to the opposite side
 * - Centroid coordinates
 * - Interior angle calculation via Law of Cosines
 * - Triangle classification by sides and angles
 * - Computation of special points (incenter, circumcenter, orthocenter)
 ** Future enhancements may include:

 * - Medians and angle bisectors
 *
 * @note Requires a valid implementation of D2length() to compute side lengths.
 */

void triangleSolver()
{  
    // We generate 3 ordered pairs (x, y)
    double triangle[3][2];
    cout << "Enter your vertices" << endl;

    for (int i = 0; i < 3; i++) 
    {
        cout << "x" << i << " = ";
        cin >> triangle[i][0];
        cout << "y" << i << " = ";
        cin >> triangle[i][1];
    }

    // Calculate the perimeter of the triangle
    double AB = D2length(triangle[0], triangle[1]);
    double AC = D2length(triangle[0], triangle[2]);
    double BC = D2length(triangle[1], triangle[2]);
    double perimeter = AB + AC + BC;

    int angleType, sideType;

    enum
    {
        acute,
        obtuse,
        right,
        scalene,
        isosceles,
        equilateral
    };

    // Side classification
    if ((AB == AC) && (AB == BC))
    {
        sideType = equilateral;
    }
    else if ((AB == AC) || (AB == BC) || (AC == BC))
    {
        sideType = isosceles;
    } 
    else 
    {
        sideType = scalene;
    }

    // Calculate the area using Heron's formula
    double s = perimeter / 2;
    double area = sqrt(s * (s - AB) * (s - AC) * (s - BC));

    // Determine the triangle heights by reverse-solving the area
    double height_from_C = (2 * area) / AB;
    double height_from_B = (2 * area) / AC;
    double height_from_A = (2 * area) / BC;

    // Determine the coordinates of the centroid
    double xg = (triangle[0][0] + triangle[1][0] + triangle[2][0]) / 3;
    double yg = (triangle[0][1] + triangle[1][1] + triangle[2][1]) / 3;



    // Triangle vertices
    double aX = triangle[0][0];
    double aY = triangle[0][1];
    double bX = triangle[1][0];
    double bY = triangle[1][1];
    double cX = triangle[2][0];
    double cY = triangle[2][1];

    // Angle bisector point D on side BC
    double dAx = (bX * AC + cX * AB) / (AC + AB);
    double dAy = (bY * AC + cY * AB) / (AC + AB);

    // Angle bisector point E on side AC
    double eBx = (aX * BC + cX * AB) / (BC + AB);
    double eBy = (aY * BC + cY * AB) / (BC + AB);

    // Angle bisector point F on side AB
    double fCx = (aX * BC + bX * AC) / (BC + AC);
    double fCy = (aY * BC + bY * AC) / (BC + AC);

    // Incenter via weighted average
    // side lengths
    double a = BC;
    double b = AC; 
    double c = AB; 
    double Ix = (a * aX + b * bX + c * cX) / perimeter;
    double Iy = (a * aY + b * bY + c * cY) / perimeter;



    /*
        Law of Cosines — angle at vertex A is opposite side BC

        Side naming:
        - AB = side from A to B → opposite angle C
        - AC = side from A to C → opposite angle B
        - BC = side from B to C → opposite angle A

        Law of Cosines:
        cos(A) = (AB² + AC² - BC²) / (2 * AB * AC)
        cos(B) = (AB² + BC² - AC²) / (2 * AB * BC)
        cos(C) = (AC² + BC² - AB²) / (2 * AC * BC)
    */

    // Calculate cosines
    double cos_Val_A = (pow(AB, 2) + pow(AC, 2) - pow(BC, 2)) / (2 * AB * AC);
    double cos_Val_B = (pow(AB, 2) + pow(BC, 2) - pow(AC, 2)) / (2 * AB * BC);
    double cos_Val_C = (pow(AC, 2) + pow(BC, 2) - pow(AB, 2)) / (2 * AC * BC);

    // Convert to angles in degrees
    double angle_A = acos(cos_Val_A) * 180 / PI;
    double angle_B = acos(cos_Val_B) * 180 / PI;
    double angle_C = acos(cos_Val_C) * 180 / PI;

    // Classify by angles
    if ((angle_A < 90) && (angle_B < 90) && (angle_C < 90))
    {
        angleType = acute;
    } 
    else if ((angle_A > 90) || (angle_B > 90) || (angle_C > 90)) 
    {
        angleType = obtuse;
    } 
    else if (fabs(angle_A - 90) < 1e-6 || fabs(angle_B - 90) < 1e-6 || fabs(angle_C - 90) < 1e-6)
    {
        angleType = right;
    }

    // Slopes of triangle sides
    double mABSlope = D2Slope(aX, aY, bX, bY);
    double mACSlope = D2Slope(aX, aY, cX, cY);
    double mBCSlope = D2Slope(bX, bY, cX, cY);

    // Slopes of altitudes (perpendicular to sides)
    double altmABslope = (mABSlope != 0) ? -1.0 / mABSlope : 0;
    double altmACslope = -1.0 / mACSlope;
    double altmBCSlope = -1.0 / mBCSlope;

    // Midpoints of triangle sides
    // midpoint of AB
    double rX = (aX + bX) / 2;
    double rY = (aY + bY) / 2;
    // midpoint of AC
    double sX = (aX + cX) / 2; 
    double sY = (aY + cY) / 2;
    
    // midpoint of BC
    double tX = (bX + cX) / 2; 
    double tY = (bY + cY) / 2; 

    double orthX, orthY, circumX, circumY;

    if (angleType == right)
    {
        // Orthocenter is at the right-angle vertex
        if (fabs(angle_A - 90.0) < 1e-6) 
        {
            orthX = aX; orthY = aY;
            circumX = (bX + cX) / 2.0;
            circumY = (bY + cY) / 2.0;
        } 
        else if (fabs(angle_B - 90.0) < 1e-6)
        {
            orthX = bX; orthY = bY;
            circumX = (aX + cX) / 2.0;
            circumY = (aY + cY) / 2.0;
        } 
        else 
        {
            orthX = cX; orthY = cY;
            circumX = (aX + bX) / 2.0;
            circumY = (aY + bY) / 2.0;
        }
    }
    else
    {
        // General case: compute orthocenter from altitudes
        double orthXNum = altmABslope * cX - altmACslope * bX + cY - bY;
        double orthXDen = altmABslope - altmACslope;

        if (fabs(mABSlope) < 1e-6)
        {
            // AB is horizontal → altitude from C is vertical
            orthX = cX;
            orthY = altmACslope * (orthX - bX) + bY;
        } 
        else 
        {
            orthX = orthXNum / orthXDen;
            orthY = altmABslope * (orthX - cX) + cY;
        }

        // Circumcenter from perpendicular bisectors
        double circumXNum = altmACslope * sX - altmABslope * rX + rY - sY;
        double circumXDen = altmACslope - altmABslope;

        if (fabs(mABSlope) < 1e-6) 
        {
            // AB is horizontal → perpendicular bisector is vertical
            circumX = rX;
            circumY = altmABslope * (circumX - rX) + rY;
        } 
        else if (fabs(aX - cX) < 1e-6)
        {
            // AC is vertical → bisector is horizontal
            circumY = sY;
            circumX = altmABslope * (circumY - rY) + rX;
        } 
        else 
        {
            circumX = circumXNum / circumXDen;
            circumY = altmABslope * (circumX - rX) + rY;
        }
    }

  



    system("cls");  
    cout << "You selected a triangle with the following vertices:\n"
        << "A = (" << triangle[0][0] << ", " << triangle[0][1] << "), "
        << "B = (" << triangle[1][0] << ", " << triangle[1][1] << "), "
        << "C = (" << triangle[2][0] << ", " << triangle[2][1] << ")\n";

    if (area < 1e-6) 
    {
        for (int i = 0; i < 5; i++) cout << endl;

        cout << "WARNING: The triangle vertices provided appear to be colinear or nearly colinear!\n";
        cout << "Triangles are defined as a shape formed by three points, where at least one point is not colinear with the others.\n";
        cout << "If you are seeing this message, you either provided an extremely small triangle (area < 1e-6),\n";
        cout << "or your vertices are colinear and you no longer have a valid triangle.\n";
        cout << "Either way, the results may not be accurate. So calculations will not be provided.\n";

        for (int i = 0; i < 5; i++) cout << endl;
    } 
    else
    {
        cout << endl;
        triangleGraphic(angleType);
        cout << endl;

        cout << "-- Length Metrics --\n\n";
        cout << "AB = " << AB << " units\n";
        cout << "AC = " << AC << " units\n";
        cout << "BC = " << BC << " units\n";
        cout << "Perimeter = " << perimeter << " units\n";
        cout << "Area = " << area << " square units\n\n";
        cout << "The height of the triangle from A is " << height_from_A << " units\n";
        cout << "The height of the triangle from B is " << height_from_B << " units\n";
        cout << "The height of the triangle from C is " << height_from_C << " units\n\n";

        cout << "-- Angle Metrics --\n\n";
        cout << "Angle A = " << angle_A << " degrees\n";
        cout << "Angle B = " << angle_B << " degrees\n";
        cout << "Angle C = " << angle_C << " degrees\n\n";
        cout << "cos(angle A) = " << cos_Val_A << "\n";
        cout << "cos(angle B) = " << cos_Val_B << "\n";
        cout << "cos(angle C) = " << cos_Val_C << "\n\n";

        cout << "-- Special Traits --\n\n";
        if (sideType == equilateral)
        {
            cout << "This is an equilateral triangle\n";
        } 
        else if (sideType == isosceles)
        {
            cout << "This is an isosceles triangle\n";
        } 
        else
        {
            cout << "This is a scalene triangle\n";
        }
        cout << endl;

        cout << "Angle bisector point D on side BC: (" << dAx << ", " << dAy << ")\n";
        cout << "Angle bisector point E on side AC: (" << eBx << ", " << eBy << ")\n";
        cout << "Angle bisector point F on side AB: (" << fCx << ", " << fCy << ")\n\n";

        cout << "Incenter: (" << Ix << ", " << Iy << ")\n";
        cout << "Centroid: (" << xg << ", " << yg << ")\n";
        cout << "Orthocenter: (" << orthX << ", " << orthY << ")\n";
        cout << "Circumcenter: (" << circumX << ", " << circumY << ")\n";
    }
}