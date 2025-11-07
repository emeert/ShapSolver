#include "qaudrilateral.hpp"
#include "../common/d2Common.hpp"
#include <iostream>
#include <cmath>

using namespace std;


void renderSquare() {
    cout << "* * * *" << endl;
    cout << "*     *" << endl;
    cout << "*     *" << endl;
    cout << "* * * *" << endl;
    cout << endl;
}

void renderRectangle() {
    cout << "* * * * * *" << endl;
    cout << "*         *" << endl;
    cout << "*         *" << endl;
    cout << "* * * * * *" << endl;
    cout << endl;
}

void renderRhombus() {
    cout << "   * * * * *" << endl;
    cout << "  *       * " << endl;
    cout << " *       *  " << endl;
    cout << "* * * * *   " << endl;
    cout << endl;
}

void renderParallelogram() {
    cout << "    * * * * * * * *" << endl;
    cout << "   *             * " << endl;
    cout << "  *             *  " << endl;
    cout << " * * * * * * * *   " << endl;
    cout << endl;
}

void renderKite() {
    cout << "     *     " << endl;
    cout << "  *     *  " << endl;
    cout << "*         *" << endl;
    cout << " *       * " << endl;
    cout << "  *     *  " << endl;
    cout << "   *   *   " << endl;
    cout << "    * *    " << endl;
    cout << "     *     " << endl;
    cout << "Note: Pictured above is a generic kite shape only." << endl;
    cout << endl;
}

void renderTrapezoid() {
    cout << "   * * * * * * * *   " << endl;
    cout << "  *               *  " << endl;
    cout << " *                 * " << endl;
    cout << "* * * * * * * * * * *" << endl;
    cout << "Note: Pictured above is a generic trapezoid shape only." << endl;
    cout << endl;
}

void renderDart() {
    cout << "       *       " << endl;
    cout << "      * *      " << endl;
    cout << "     *   *     " << endl;
    cout << "    *     *    " << endl;
    cout << "   *   *   *   " << endl;
    cout << "  *  *   *  *  " << endl;
    cout << " * *       * * " << endl;
    cout << "*             *" << endl;
    cout << endl;
}

void renderCrossed() {
    cout << "*                  *" << endl;
    cout << "**                **" << endl;
    cout << "* *              * *" << endl;
    cout << "*  *            *  *" << endl;
    cout << "*   *          *   *" << endl;
    cout << "*    *        *    *" << endl;
    cout << "*     *      *     *" << endl;
    cout << "*      *    *      *" << endl;
    cout << "*       *  *       *" << endl;
    cout << "*        **        *" << endl;
    cout << "*        **        *" << endl;
    cout << "*       *  *       *" << endl;
    cout << "*      *    *      *" << endl;
    cout << "*     *      *     *" << endl;
    cout << "*    *        *    *" << endl;
    cout << "*   *          *   *" << endl;
    cout << "*  *            *  *" << endl;
    cout << "* *              * *" << endl;
    cout << "**                **" << endl;
    cout << "*                  *" << endl;
    cout << "Note: Your shape's orientation may be completely different than what's suggested in the graphic!" << endl;
    cout << endl;
}


void quadGraphic(int quadScore)
{
    switch (quadScore)
    {
        case complex_Shape:
            cout << "Your shape is complex_Shape!" << endl << endl;
            renderCrossed();
            break;

        case dart:
            cout << "Your shape is Simple!" << endl;
            cout << "Your shape is Concave!" << endl;
            cout << "Your shape is a Dart!" << endl << endl;
            renderDart();
            break;

        case trapezoid:
        case right_angled_trapezium:
        case isosceles_trapezium:
        case three_equal_sides_trapezium:
            cout << "Your shape is Simple!" << endl;
            cout << "Your shape is Convex!" << endl;
            if (quadScore == right_angled_trapezium)
                cout << "You made a Right-Angled Trapezoid!" << endl;
            else if (quadScore == isosceles_trapezium)
                cout << "You made an Isosceles Trapezoid!" << endl;
            else if (quadScore == three_equal_sides_trapezium)
                cout << "You made a Three Equal-Sided Trapezoid!" << endl;
            else
                cout << "You made a Trapezoid!" << endl;
            cout << endl;
            renderTrapezoid();
            break;

        case kite:
        case convex_kite:
        case right_kite:
            cout << "Your shape is Simple!" << endl;
            cout << "Your shape is Convex!" << endl;
            if (quadScore == convex_kite)
                cout << "You made a Convex Kite!" << endl;
            else if (quadScore == right_kite)
                cout << "You made a Right Kite!" << endl;
            else
                cout << "You made a Kite!" << endl;
            cout << endl;
            renderKite();
            break;

        case parallelogram:
            cout << "Your shape is Simple!" << endl;
            cout << "Your shape is Convex!" << endl;
            cout << "You made a Parallelogram!" << endl << endl;
            renderParallelogram();
            break;

        case rhombus:
            cout << "Your shape is Simple!" << endl;
            cout << "Your shape is Convex!" << endl;
            cout << "You made a Rhombus!" << endl << endl;
            renderRhombus();
            break;

        case rectangle:
            cout << "Your shape is Simple!" << endl;
            cout << "Your shape is Convex!" << endl;
            cout << "You made a Rectangle!" << endl << endl;
            renderRectangle();
            break;

        case square:
            cout << "Your shape is Simple!" << endl;
            cout << "Your shape is Convex!" << endl;
            cout << "You made a Square!" << endl << endl;
            renderSquare();
            break;

        default:
            cout << "No graphic has been rendered for this type of quadrilateral." << endl;
            break;
    }
}


/*

### 🧱 Full Breakdown of `enum family`

| Enum                         | Type              | Renderable | Key Properties                                                                 |
|-----------------------------|-------------------|------------|--------------------------------------------------------------------------------|
| `quadrilateral`             | Generic container | ⚠️ No      | 4 sides, 4 angles, angle sum = 360°, no specific traits                        |
| `complex_Shape`                   | Structural trait  | ✅ Yes     | Self-intersecting, angle sum = 720°, bowtie shape                             |
| `simple`                    | Structural trait  | ⚠️ No      | No self-intersection, sides do not cross                                      |
| `concave`                   | Trait             | ⚠️ No      | At least one interior angle > 180°, one diagonal lies outside                 |
| `convex`                    | Trait             | ⚠️ No      | All interior angles < 180°, diagonals lie inside                              |
| `dart`                      | Shape             | ✅ Yes     | Concave, 2 equal adjacent sides, one reflex angle                             |
| `tangential`               | Trait             | 🚫 No      | All sides tangent to a single incircle, opposite angles sum to 180°           |
| `trapezoid`                 | Shape             | ✅ Yes     | One pair of parallel sides, other pair non-parallel                           |
| `cyclic`                    | Trait             | 🚫 No      | All vertices lie on a circle, opposite angles sum to 180°                     |
| `bicentric`                 | Trait             | 🚫 No      | Both cyclic and tangential, has incircle and circumcircle                     |
| `kite`                      | Shape             | ✅ Yes     | Two pairs of adjacent equal sides, one pair of equal opposite angles          |
| `convex_kite`               | Variant           | ✅ Yes     | Convex version of kite                                                        |
| `parallelogram`             | Shape             | ✅ Yes     | Opposite sides equal & parallel, opposite angles equal                        |
| `right_angled_trapezium`    | Variant           | ✅ Yes     | Trapezoid with one right angle                                                |
| `isosceles_trapezium`       | Variant           | ✅ Yes     | Trapezoid with equal non-parallel sides, equal base angles                    |
| `right_kite`                | Variant           | ✅ Yes     | Kite with one right angle                                                     |
| `rhombus`                   | Shape             | ✅ Yes     | 4 equal sides, opposite angles equal, diagonals perpendicular                 |
| `rectangle`                 | Shape             | ✅ Yes     | Opposite sides equal, 4 right angles, diagonals equal                         |
| `three_equal_sides_trapezium` | Variant         | ✅ Yes     | Trapezoid with three equal sides, asymmetrical angles                         |
| `square`                    | Shape             | ✅ Yes     | 4 equal sides, 4 right angles, diagonals equal & perpendicular                |

---

### 🧠 Summary

- ✅ **Renderable**: All canonical shapes and variants with visual identity
- ⚠️ **Textual-only**: Structural traits (`simple`, `concave`, `convex`) and generic container (`quadrilateral`)
- 🚫 **Unrenderable**: Mathematical traits (`cyclic`, `tangential`, `bicentric`)—resist ASCII containment

*/

void quadSolver()
{
    //for testing purposes only remove this later. 
   for (int i = 0; i < 20; i++)
   {
        quadGraphic(i);
   }
}