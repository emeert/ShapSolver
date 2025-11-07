#ifndef QAUDRILATERAL_HPP
#define QAUDRILATERAL_HPP

enum family
{
    quadrilateral,
    complex_Shape,
    simple,
    concave,
    convex,
    dart,
    tangential,
    trapezoid,
    cyclic,
    bicentric,
    kite,
    convex_kite,
    parallelogram,
    right_angled_trapezium,
    isosceles_trapezium,
    right_kite,
    rhombus,
    rectangle,
    three_equal_sides_trapezium,
    square
};

void quadGraphic(int quadScore);
void renderSquare();
void renderRectangle();
void renderRhombus();
void renderParallelogram();
void renderKite();
void renderTrapezoid();
void renderDart();
void renderCrossed();
void quadSolver();

#endif