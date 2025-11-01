#include <iostream>
#include <cmath>
using namespace std; 

// A global constant we wil need. For converting radians to degrees. 
const double PI = acos(-1.0);



void menuPromt()
{
    cout << "****************" << endl;
    cout << "ShapeSolver 1.1" << endl;
    cout << "By Elijah Meert" << endl; 
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
 ** Future enhancements may include:
 * - Computation of special points (incenter, circumcenter, orthocenter)
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
   
    cout << "The centroid of such a triangle would be located at ("<< xg << "," << yg << ")" << endl;
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