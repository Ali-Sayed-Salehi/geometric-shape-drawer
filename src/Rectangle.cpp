//
// Created by Ali Sayed Salehi on 2023-07-30.
//

#include <sstream>
#include <typeinfo>
#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle(int height, int width, const std::string &name, char pen) :
    Shape(name, pen) {

    if (height >= 1) {
        this->height = height;
    } else {
        std::cerr << "Error: height value must be greater than 1. Setting default value (1).\n";
        this->height = 1;
    }

    if (width >= 1) {
        this->width = width;
    } else {
        std::cerr << "Error: width value must be greater than 1. Setting default value (1).\n";
        this->width = 1;
    }

}

std::string Rectangle::toString() const {
    std::stringstream ss;
    ss << "\n Shape Information"
    << "\n-----------------"
    << "\n id: " << idNumber
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

Canvas Rectangle::draw() const {
    Canvas canvas(height, width);
    for (int i =0; i < canvas.getGrid().size(); ++i){
        for(int j = 0; j < canvas.getGrid()[i].size(); ++j){
            canvas.put(i, j, pen);
        }
    }
    return canvas;
}

