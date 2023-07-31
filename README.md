# geometric-shape-drawer
A program to draw basic geometric shapes on a canvas in the console. 
This program demonstrates the use of inheritance and polymorphism in c++.
Classes `Rectangle`, `Rhombus`, and `Triangle` are derived from `Shape` class, which is an abstract class.
The `AcuteTriangle` and `RightTriangle` classes are derived from the `Triangle` class.

This program also demonstrates the use of smart pointers. In the main driver, a vector of `unique_ptr`
to `Shape` objects is created, which is later used to print shape details.

## How to run
Simply run the main.cpp file. The drawHouse() method draws a house and 
prints the details of shapes to the console

## Sample output
```txt

 Shape Information
-----------------
 id: 1
 Shape name: Right half of roof
 Pen character: /
 Base: 20
 Height: 20
 Textual area: 210
 Geometric area: 200
 Textual perimeter: 57
 Geometric perimeter: 68.2843
 Static type : PK13RightTriangle
 Static type : 13RightTriangle

```
