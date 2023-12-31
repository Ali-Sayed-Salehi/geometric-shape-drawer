//
// Created by Ali Sayed Salehi on 2023-07-30.
//

#include <iostream>
#include <sstream>
#include "Rhombus.h"

Rhombus::Rhombus(int diagonal, char pen, const std::string &name) : Shape(name, pen) {

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
       << "\n Dynamic type : " << typeid(*this).name() << std::endl;

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

    int midRow = diagonal / 2;

    for (int i = 0; i < diagonal; ++i) {
        for (int j = 0; j < diagonal; ++j) {
            if (i <= midRow) {
                if (j >= midRow - i && j <= midRow + i) {
                    canvas.put(i, j, '*');
                }
            } else {
                if (j >= midRow - (diagonal - 1 - i) && j <= midRow + (diagonal - 1 - i)) {
                    canvas.put(i, j, '*');
                }
            }
        }
    }

    return canvas;
}
