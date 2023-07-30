//
// Created by Ali Sayed Salehi on 2023-07-30.
//

#include <iostream>
#include "Shape.h"

int Shape::idCount = 0;

Shape::Shape(const std::string &name, char pen) : name(name), pen(pen) {
    idCount++;
    idNumber = idCount;
}

std::ostream &operator<<(std::ostream &os, const Shape &shape) {
    shape.print(os);
    return os;
}

void Shape::print(std::ostream &os) const {
    os << this -> toString() << std::endl;
}

