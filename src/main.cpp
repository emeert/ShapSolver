#include <iostream>
#include "shapes/triangle.hpp"
#include "common/d2Common.hpp"
#include "menu/menuSystem.hpp"
// Future: #include "square.hpp", "circle.hpp", etc.

int main() {
    menuPrompt();
    shapeSelectionMenu();

    int shapeChoice;
    std::cin >> shapeChoice;

    switch (shapeChoice) {
        case 1:
            triangleSolver();
            break;
        // case 2: squareSolver(); break;
        // case 3: rectangleSolver(); break;
        // case 4: circleSolver(); break;
        default:
            std::cout << "Invalid choice. Exiting." << std::endl;
    }

    std::cout << "\nPress Enter to exit...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}