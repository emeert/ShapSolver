#include "menuSystem.hpp"
#include <iostream>

void menuPrompt() {
    std::cout << "****************" << std::endl;
    std::cout << "PointShapeSolver 1.1" << std::endl;
    std::cout << "bY Elijah Meert" << std::endl;
    std::cout << "****************" << std::endl;
}

void shapeSelectionMenu() {
    std::cout << "\nSelect a shape to analyze:" << std::endl;
    std::cout << "1. Triangle" << std::endl;
    std::cout << "2. Qaudrilateral" << std::endl;
    std::cout << "3. Pentagon" << std::endl;
    std::cout << "4. Hexagon" << std::endl;
    std::cout << "5. Circle" << std::endl;
    std::cout << "6. N-GON" << std::endl;
    std::cout << "Enter your choice: ";
}

void diagnosticMenu() {
    std::cout << "\nChoose a diagnostic mode:" << std::endl;
    std::cout << "1. Basic Properties" << std::endl;
    std::cout << "2. Advanced Geometry" << std::endl;
    std::cout << "3. Special Points" << std::endl;
    std::cout << "Enter your choice: ";
}