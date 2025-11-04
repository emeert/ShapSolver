#include <iostream>
#include <cmath>
using namespace std; 

// A global constant we wil need. For converting radians to degrees. 
const double PI = acos(-1.0);



void menuPromt()
{
    cout << "****************" << endl;
    cout << "ShapeSolver 1.1" << endl;
    cout << "bY Elijah Meert" << endl; 
    cout << "****************" << endl;
}


void triangleGraphic(int triangle_Type)
{

    enum 
    { 
        acute, 
        obtuse, 
        right
    };

    switch(triangle_Type)
    {

        case acute:
        {   cout << "That is an acute triangle"<< endl;
            cout << endl;
            cout << "                   " << endl;
            cout << "         *         " << endl;
            cout << "        * *        " << endl; 
            cout << "       *   *       " << endl;
            cout << "      *     *      " << endl;
            cout << "     *       *     " << endl;  
            cout << "    *         *    " << endl; 
            cout << "   *           *   " << endl; 
            cout << "  *-------------*  " << endl;
        }
        break;

        case obtuse:
        {
            cout << "That is an obtuse triangle" << endl;
            cout << endl;
            cout << "                                 " << endl;
            cout << "         *                       " << endl;
            cout << "        *   *                    " << endl; 
            cout << "       *       *                 " << endl;
            cout << "      *           *              " << endl;
            cout << "     *               *           " << endl;  
            cout << "    *                   *        " << endl; 
            cout << "   *                       *     " << endl; 
            cout << "  * - - - - - - - - - - - -  *   " << endl;
        }
        break;


        case right:
        {
            cout << "That is a right triangle" << endl;
            cout << endl;
            cout << "                               " << endl;
            cout << "  *                            " << endl;
            cout << "  *   *                        " << endl; 
            cout << "  *       *                    " << endl;
            cout << "  *           *                " << endl;
            cout << "  *               *            " << endl;  
            cout << "  *                   *        " << endl; 
            cout << "  *                      *    " << endl; 
            cout << "  * - - - - - - - - - - - -  * " << endl;
        }
        break;


    }
    


}


/*

    First version will focus on 2d objects only 

    | Shape     | Inputs               | Properties Calculated |
    |-----------|----------------------|------------------------|
    | Triangle  | 3 points (x, y)       | Side lengths, perimeter, area, height |
    | Square    | 4 points (x,y)          | Area, perimeter        |
    | Rectangle | 4 points (x,y)        | Area, perimeter        |
    | Circle    | 2 points (x,y)               | Area, circumference    |

*/

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

    int angleType, sideType;

    enum 
    { 
        acute, 
        obtuse, 
        right,
        scalene,
        isosoceles,
        equilateral
    };


    
    //We generate 3 ordered pairs (x,y)
    double triangle[3][2];
    cout << "Enter your vertices" << endl;

    for(int i = 0; i < 3; i++)
    {
        //xi
        cout << "x"<< i <<"= "; 
        cin >> triangle[i][0];
        //yi
        cout << "y"<< i <<"= "; 
        cin >> triangle[i][1];
    }

    // Calculate the perimeter of the triangle
    double AB = D2length(triangle[0],triangle[1]);
    double AC = D2length(triangle[0],triangle[2]);
    double BC = D2length(triangle[1],triangle[2]);
    double perimeter = AB + AC + BC;

    if((AB == AC)&&(AB == BC))
    {
        sideType = equilateral;
    }
    else if (AB == AC)
    {
        sideType = isosoceles;
    }
    else
    {
        sideType = scalene;
    }

    

    //Calculate the area using herons formula. 
    double s = perimeter/2; 

    double area = s*(s-AB)*(s-AC)*(s-BC);
    area = sqrt(area);

    // Determine the triangle heights reverse solving the area 
    double height_from_C = (2 * area)/AB;
    double height_from_B = (2 * area)/AC;
    double height_from_A = (2 * area)/BC;

    //Determine the coordinates of the centroid
    double xg = (triangle[0][0]+triangle[1][0]+triangle[2][0])/3;
    double yg = (triangle[0][1]+triangle[1][1]+triangle[2][1])/3;




    //Determine the coordinates of the angle Bisector
    /*
    2. Use the Angle Bisector Theorem:
        The internal angle bisector from vertex A meets side BC at a point D such that:
        BD/DC=AB/AC
        if A(x1,y1), B(x2,y2) and C(x3,y3)

        then the angle bisector from vertext A(x1,y1)

        dAx = (x2*AC_x3*AB)/(AC+AB)
        dAy = (y2*AC+y3*AB)/(AC+AB)  
    */
    
   
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

//Finding the Incenter using a weighted average method 
/*
    Ix = (a*aX +b*bX+c*cX)/(a+b+c)
    Iy = (a*aY+b*bY+c*cY)/(a+b+c)

    where 
    a = length of side BC
    b = length of side AC 
    c = Length of side AB

    aX and aY are as defined above the coordinates of vertex A so A(x,y) = (aX,aY)
    bX and bY are as defined above the coordinates of vetex B so B(x,y) = (bX, bY)
    cX and cY are as defined above the coordinates of vertex C so C(x,y) = (cX, cY)
*/

// a+b+c is the perimeter 
// a is also BC 
double a = BC;
// b is also AC
double b = AC; 
// c is also AB
double c = AB; 

//Incenter 
double Ix = (a*aX + b*bX + c*cX)/perimeter;
double Iy = (a*aY+ b*bY+ c*cY)/perimeter;



        /*
            A
            *
            * *
            *   *
            *     *
            *       *
            B---------C

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
    
         // calculate for cos A using the Law of Cosines
        double cos_Val_A = (pow(AB, 2) + pow(AC, 2) - pow(BC, 2)) / (2 * AB * AC);
        double angle_A = acos(cos_Val_A)*180/PI;
        

     
        // calculate cos B using the Law of Cosines
        double cos_Val_B = (pow(AB, 2) + pow(BC, 2) - pow(AC, 2)) / (2 * AB * BC);
        double angle_B = acos(cos_Val_B)*180/PI;

        // Calculate cos C using the Law of Cosines
        double cos_Val_C = (pow(AC, 2) + pow(BC, 2) - pow(AB, 2)) / (2 * AC * BC);
        double angle_C = acos(cos_Val_C)*180/PI;


       
       

        if((angle_A < 90)&&(angle_B < 90)&& (angle_C < 90))
        {   
            angleType = acute;

        }
        else if ((angle_A > 90)|| (angle_B > 90) ||(angle_C > 90))
        {
            angleType = obtuse;
        }
        else if (fabs(angle_A - 90) < 1e-6 || fabs(angle_B - 90) < 1e-6 || fabs(angle_C - 90) < 1e-6)
        {   
            angleType = right;
        }




    //Orthocenter 
    // The orthocenter is the intersection of the altitudes of the triangle. 
    //Slope of AB
    double mABSlope = D2Slope(aX,aY,bX,bY);
    double altmABslope;
    //Slope of  Altitude from vertex C perpendicular to AB
    if(mABSlope != 0)
    {
        altmABslope = -1.0/mABSlope; 
    }
    
    //Slope of AC
    double mACslope = D2Slope(aX,aY,cX,cY);
    //Slope of  Altitude from vertex B perpendicular to AC
    double altmACslope = -1.0/mACslope; 

    //Slope of BC
    double mBCSlope = D2Slope(bX,bY,cX,cY);
    //Slope of  Altitude from vertex B perpendicular to AC
    double altmBCSlope = -1.0/mBCSlope; 

    // We pick two of these to solve thier intersection 
    /*

    y = m1(x-x1)+y1 
    y = m2(x-x2)+y2
    ....

    An elaborate calculation later gives us 
        x = (m1x1 -m2x2+y2-y1)/(m1 -m2)

        we can take m1 and m2 to be slopes of the altitudes and x1,y1 and x2,y2 to be the leading vertex of each altitude. 
    
        The leading vertex of the Altitude that is perpendicular to AB is C with slope altABSlope
        x1 = cX , y1 = cY  m1 = altABSlope

        The leading vertex of the Altitude that is perpendicular to AC is B with slope altACSlope

        x2 = bX, y2 = bY m2 = altmACslope

        so 
        x = (altmABslope*cX -altACSlope*bX + cY-bY)/(altABSlope -altACSlope)

        to make calculation slightly easier 
        OxNum = (altmABslope*cX -altACSlope*bX + cY-bY)
        OxDen = (altABSlope -altACSlope)

        Ox = OxNum/OxDen

        
    */


          //circumcenter 

        /*
            The circumcenter is the intersection of the perpendicular bisectors 

            The perpendicular bisectors are the perpendicular lines that pass throught the midpoints of the triangles sides. 

            lets call the midpoints of each side of triangle ABC  r, s, t respectfully. 

            then r  is the midpoint of AB , s is the midpoint of AC and t is the midpoint of BC 

            rX = (aX+bX)/2
            ry = (aY+bY)/2
        */
       
       //r  is the midpoint of AB
       double rX = (aX+bX)/2;
       double rY = (aY+bY)/2;

       //s is the midpoint of AC 
       double sX = (aX+cX)/2;
       double sY = (aY+cY)/2;

       //t is the midpoint of BC
       double tX = (bX+cX)/2;
       double tY = (bY + cY)/2;

       //we use AC and AB for our intersection. 
        double circumXNum; 
        double circumXDen;
        double circumX; 
        double circumY;
        
    
       

        double orthX, orthY;

        if (angleType == right) 
        {
            // Orthocenter is at the right-angle vertex
            if (fabs(angle_A - 90.0) < 1e-6)
            {
                orthX = aX;
                orthY = aY;
                // Circumcenter is midpoint of hypotenuse BC
                circumX = (bX + cX) / 2.0;
                circumY = (bY + cY) / 2.0;
            } 
            else if (fabs(angle_B - 90.0) < 1e-6)
            {
                orthX = bX;
                orthY = bY;
                // Circumcenter is midpoint of hypotenuse AC
                circumX = (aX + cX) / 2.0;
                circumY = (aY + cY) / 2.0;
            } 
            else 
            {
                orthX = cX;
                orthY = cY;
                // Circumcenter is midpoint of hypotenuse AB
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
                // General case
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
            }else if (fabs(aX-cX)< 1e-6)
            {
                // AC is vertical → bisector is horizontal
                circumX = altmABslope * (circumY - rY) + rX;
                circumY = sY;
            }
            else
            {
                circumX = circumXNum / circumXDen;
                circumY = altmABslope * (circumX - rX) + rY;
            }
            
        }


  



      

    cout << "You selected a triangle with the following vertices:  A = ("<< triangle[0][0] << "," << triangle[0][1]<< "), B = (" << triangle[1][0] 
    << "," << triangle[1][1]<< "), C = ("<< triangle[2][0] 
    << "," << triangle[2][1]<< ")" << endl; 

   


if (area < 1e-6)
{
    for (int i = 0; i < 5; i++) {
        cout << endl;
    }

    cout << "WARNING: The triangle vertices provided appear to be colinear or nearly colinear!" << endl;
    cout << "Triangles are defined as a shape formed by three points, where at least one point is not colinear with the others." << endl;
    cout << "If you are seeing this message, you either provided an extremely small triangle (area < 1e-6)," << endl;
    cout << "or your vertices are colinear and you no longer have a valid triangle." << endl;
    cout << "Either way, the results may not be accurate. So calculations will not be provided" << endl;

    for (int i = 0; i < 5; i++) {
        cout << endl;
    }
}
else
{
    cout << endl;
    triangleGraphic(angleType);
    cout << endl;

    cout <<"-- Length Metrics --"<< endl;
    cout << endl;

    cout <<"AB = "<< AB << " units" << endl;
    cout <<"AC = "<< AC << " units" << endl;
    cout <<"BC = "<< BC << " units" << endl;
    cout << endl;
    cout << "Perimeter = " << perimeter << " units" << endl;
    cout << endl;
    cout << "Area = "<< area << " square units" <<  endl;
    cout << endl;
    cout << "The height of the triangle from A is height = " << height_from_A << " units" << endl;
    cout << "The height of the triangle from B is height = " << height_from_B << " units" << endl; 
    cout << "The height of the triangle from C is height = " << height_from_C << " units" << endl; 
    cout << endl;

    cout << "-- Angle Metrics -- " << endl;
    cout << endl;
    cout << "The measure of Angle_A = " << angle_A <<" degrees."<< endl;
    cout << "The measure of Angle_B = " << angle_B <<" degrees."<< endl;
    cout << "The measure of Angle_C = " << angle_C <<" degrees."<< endl;
    cout << endl;   
    cout << "cos(angle_A): " << cos_Val_A << endl;
    cout << "cos(angle_B): " << cos_Val_B << endl;
    cout << "cos(angle_C): " << cos_Val_C << endl;
    cout << endl;

    cout << "-- Special Traits --" << endl;
    cout << endl;

    if(sideType == equilateral)
    {
        cout << "This is a equilateral Triangle" << endl;
    }
    else if(sideType == isosoceles)
    {
        cout << "This is a isoceles Triangle" << endl;
    }
    else 
    {
        cout << "This is a scalene Triangle" << endl;
    }
    cout << endl;
   


    //Angle Bisectors
    cout << "Angle bisector point D on side BC would be located at ("<< dAx << "," << dAy << ")" << endl;
    cout << endl;
    cout << "Angle bisector point E on side AC would be located at ("<< eBx << "," << eBy << ")" << endl;
    cout << endl;
    cout << "Angle bisector point F on side AB would be located at ("<< fCx << "," << fCy << ")" << endl;
    cout << endl;


    cout << "The incenter of such a triangle would be located at ("<< Ix << "," << Iy << ")" << endl;
    cout << endl;

    cout << "The centroid of such a triangle would be located at ("<< xg << "," << yg << ")" << endl;
    cout << endl;

    cout << "The orthocenter of such a triangle would be located at (" << orthX << ", " << orthY << ")" << endl;
    cout << endl;

    cout << "The circumcenter of such a triangle would be located at (" << circumX << ", " << circumY << ")" << endl;
    cout << endl;

}
    

}


int main()
{


    menuPromt();

    //Note We will be moving this into a function where the user selects what they would like to do. 
    // It is only placed in main for testing purposes. 
    triangleSolver();




    
    return 0; 
}