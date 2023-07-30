//
// Created by Ali Sayed Salehi on 2023-07-30.
//

#include <iostream>
#include "Triangle.h"

Triangle::Triangle(int base, const std::string &name, char pen) : Shape(name, pen) {
    if (base >= 1) {
        this->base = base;
    } else {
        std::cerr << "Error: base must be greater than 1. Setting default value (1).\n";
        this->base = 1;
    }

}
