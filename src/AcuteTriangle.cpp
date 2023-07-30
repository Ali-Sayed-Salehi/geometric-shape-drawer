//
// Created by Ali Sayed Salehi on 2023-07-30.
//

#include <iostream>
#include <sstream>
#include "AcuteTriangle.h"

AcuteTriangle::AcuteTriangle(int base, int height, const std::string &name, char pen) :
    Triangle(name, pen) {

    if (base % 2 == 1) {
        this->base = base;
    } else {
        std::cerr << "Error: base must be odd. Setting the next odd value.\n";
        this->base = base + 1;
    }

    this->height = (base + 1) / 2;
}

std::string AcuteTriangle::toString() const {
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

double AcuteTriangle::areaGeo() const {
    return (height * base) / 2.0;
}

double AcuteTriangle::perimeterGeo() const {
    return base + std::sqrt((base * base) + (4 * height * height));
}

int AcuteTriangle::areaScr() const {
    return height * height;
}

int AcuteTriangle::perimeterScr() const {
    if (height > 1 && base > 1){
        return 4 * (height - 1);
    } else {
        return 1;
    }
}
