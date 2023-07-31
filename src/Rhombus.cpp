//
// Created by Ali Sayed Salehi on 2023-07-30.
//

#include <iostream>
#include <sstream>
#include "Rhombus.h"

Rhombus::Rhombus(int diagonal, const std::string &name, char pen) : Shape(name, pen) {

    if (diagonal >= 1) {
        if (diagonal % 2 == 1) {
            this->diagonal = diagonal;
        } else {
            std::cerr << "Error: diagonal must be odd. Setting the next odd value.\n";
            this->diagonal = diagonal + 1;
        }
    } else {
        std::cerr << "Error: diagonal must be greater than 1. Setting default value (1).\n";
        this->diagonal = 1;
    }

}

std::string Rhombus::toString() const {
    std::stringstream ss;
    ss << "\n Shape Information"
       << "\n-----------------"
       << "\n id: " << idNumber
       << "\n Shape name: " << name
       << "\n Pen character: " << pen
       << "\n Diagonal: " << diagonal
       << "\n Textual area: " << this -> areaScr()
       << "\n Geometric area: " << this -> areaGeo()
       << "\n Textual perimeter: " << this -> perimeterScr()
       << "\n Geometric perimeter: " << this -> perimeterGeo()
       << "\n Static type : " << typeid(this).name()
       << "\n Static type : " << typeid(*this).name() << std::endl;

    return ss.str();
}

double Rhombus::areaGeo() const {
    return (diagonal * diagonal) / 2.0;
}

double Rhombus::perimeterGeo() const {
    return 2 * std::sqrt(2) * diagonal;
}

int Rhombus::areaScr() const {
    int n = std::floor(diagonal / 2.0);
    return (2 * n * (n + 1)) + 1;
}

int Rhombus::perimeterScr() const {
    if (diagonal > 1) {
        return 2 * (diagonal - 1);
    } else {
        return 1;
    }
}

Canvas Rhombus::draw() const {
    Canvas canvas(diagonal, diagonal);

    for (int i = 0; i < diagonal; ++i) {
        for (int j = 0; j < diagonal - i - 1; ++j) {
            canvas.put(i, j, ' '); // Print leading spaces
        }
        for (int j = 0; j < 2 * i + 1; ++j) {
            canvas.put(i, j, pen); // Print stars for the top half of the rhombus
        }
    }

    for (int i = diagonal - 2; i >= 0; --i) {
        for (int j = 0; j < diagonal - i - 1; ++j) {
            canvas.put(i, j, ' '); // Print leading spaces
        }
        for (int j = 0; j < 2 * i + 1; ++j) {
            canvas.put(i, j, pen); // Print stars for the bottom half of the rhombus
        }
    }

    return canvas;
}
