//
// Created by Ali Sayed Salehi on 2023-07-30.
//

#include <sstream>
#include <iostream>
#include "RightTriangle.h"

RightTriangle::RightTriangle(int base, char pen, const std::string &name) :
        Triangle(name, pen){

    if (base >= 1) {
        this->base = base;
    } else {
        std::cerr << "Error: base must be greater than 1. Setting default value (1).\n";
        this->base = 1;
    }

    this->height = base;
}

std::string RightTriangle::toString() const {
    std::stringstream ss;
    ss << "\n Shape Information"
       << "\n-----------------"
       << "\n id: " << idNumber
       << "\n Shape name: " << name
       << "\n Pen character: " << pen
       << "\n Base: " << base
       << "\n Height: " << height
       << "\n Textual area: " << this -> areaScr()
       << "\n Geometric area: " << this -> areaGeo()
       << "\n Textual perimeter: " << this -> perimeterScr()
       << "\n Geometric perimeter: " << this -> perimeterGeo()
       << "\n Static type : " << typeid(this).name()
       << "\n Static type : " << typeid(*this).name() << std::endl;

    return ss.str();
}

double RightTriangle::areaGeo() const {
    return (height * base) / 2.0;
}

double RightTriangle::perimeterGeo() const {
    return (2 + sqrt(2)) * height;
}

int RightTriangle::areaScr() const {
    return height * (height + 1) / 2;
}

int RightTriangle::perimeterScr() const {
    if (height > 1 && base > 1){
        return 3 * (height - 1);
    } else {
        return 1;
    }
}

Canvas RightTriangle::draw() const {
    Canvas canvas(height, base);

    for (int i = 0; i < base; ++i) {
        for (int j = 0; j <= i; ++j) {
            canvas.put(i, j, pen); // Print stars for the right triangle
        }
    }
    return canvas;
}


