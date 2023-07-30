//
// Created by Ali Sayed Salehi on 2023-07-30.
//

#include <sstream>
#include <typeinfo>
#include "Rectangle.h"

Rectangle::Rectangle(int height, int width, const std::string &name, char pen) :
    Shape(name, pen), height(height), width(width) {
}

std::string Rectangle::toString() const {
    std::stringstream ss;
    ss << "\nShape Information"
    << "\n-----------------"
    << "\nid: " << idNumber
    << "\n Shape name: " << name
    << "\n Pen character: " << pen
    << "\n Height: " << height
    << "\n Width: " << width
    << "\n Textual area: " << this -> areaScr()
    << "\n Geometric area: " << this -> areaGeo()
    << "\n Textual perimeter: " << this -> perimeterScr()
    << "\n Geometric perimeter: " << this -> perimeterGeo()
    << "\n Static type : " << typeid(this).name()
    << "\n Static type : " << typeid(*this).name() << std::endl;

    return ss.str();
}

double Rectangle::areaGeo() const {
    return height * width;
}

double Rectangle::perimeterGeo() const {
    return 2 * (height + width);
}

int Rectangle::areaScr() const {
    return height * width;
}

int Rectangle::perimeterScr() const {
    int perimeter{};
    if (height > 1 && width > 1) {
        perimeter = (2 * (height + width)) - 4;
    }
    if (height == 1 && width == 1) {
        perimeter = height * width;
    }
    return perimeter;
}

