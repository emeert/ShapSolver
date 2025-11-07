
# 📐 PointShapeSolver

**PointShapeSolver** is a modular C++ program that calculates geometric properties of 2D and 3D shapes using only vertex coordinates. It demonstrates how multidimensional arrays and mathematical formulas can transform raw spatial input into structured geometric consequence.

---

## 🎯 Purpose

This project explores:
- The use of **arrays** to store 2D and 3D vertex coordinates
- The power of **functions** to encapsulate geometric logic
- The application of **formulas** to calculate area, perimeter, volume, height, and center points
- A **menu-driven interface** that guides users through shape selection and vertex input

PointShapeSolver began as a simple exercise and evolved into a principled geometry engine — modeling spatial consequence through modular design.

---

## 🧱 Supported Shapes

### 🔹 2D Shapes  
All 2D shapes are defined by their vertices (ordered pairs).

| Shape     | Inputs                  | Properties Calculated                          |
|-----------|-------------------------|------------------------------------------------|
| Triangle  | 3 points (x, y)         | Side lengths, perimeter, area, heights, centroid |
| Square    | 4 points (x, y)         | Side lengths, area, perimeter, diagonals, center |
| Rectangle | 4 points (x, y)         | Side lengths, area, perimeter, diagonals, center |
| Circle    | 2 points (center + edge)| Radius, area, circumference                    |

### 🔸 3D Shapes  
All 3D shapes are defined by their vertices (ordered triples).

| Shape     | Inputs                  | Properties Calculated                          |
|-----------|-------------------------|------------------------------------------------|
| Cube      | 8 points (x, y, z)      | Edge length, volume, surface area              |
| Cone      | 2 points (center + tip) | Radius, height, volume, surface area           |
| Pyramid   | 5 points (base + apex)  | Base area, height, volume, surface area        |

---

## 🧮 Mathematical Formulas Used

| Property         | Formula |
|------------------|---------|
| Triangle Area    | Heron’s: \( A = \sqrt{s(s-a)(s-b)(s-c)} \) |
| Triangle Height  | \( h = \frac{2A}{\text{base}} \) |
| Square Area      | \( A = s^2 \) |
| Rectangle Area   | \( A = l \cdot w \) |
| Circle Area      | \( A = \pi r^2 \) |
| Circle Circumference | \( C = 2\pi r \) |
| Cube Volume      | \( V = s^3 \) |
| Cone Volume      | \( V = \frac{1}{3}\pi r^2 h \) |
| Pyramid Volume   | \( V = \frac{1}{3} \cdot \text{base area} \cdot h \) |

---

## 🧩 Features

- Modular functions for each shape
- Uses arrays to store vertex coordinates
- Menu-driven interface for user interaction
- Clear output formatting with labeled results
- Extensible design for adding more shapes or properties
- Degeneracy warnings for colinear or invalid input

---

## 🚀 How to Run

1. Clone the repository
2. Compile the program using a C++ compiler:
   ```bash
   g++ -o PointShapeSolver main.cpp
   ```
3. Run the executable:
   ```bash
   ./PointShapeSolver
   ```
4. Follow the prompts to select a shape and enter its vertices

---

## 🪪 License

This project is licensed under the MIT License — see the [LICENSE](./LICENSE) file for details.

---
