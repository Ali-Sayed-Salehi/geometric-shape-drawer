//
// Created by Ali Sayed Salehi on 2023-07-30.
//

#ifndef GEOMETRIC_SHAPE_DRAWER_TRIANGLE_H
#define GEOMETRIC_SHAPE_DRAWER_TRIANGLE_H


#include "Shape.h"

class Triangle : public Shape{
protected:

public:
    Triangle() = delete;
    Triangle(const Triangle&) = default;
    Triangle(Triangle&&) = default;
    Triangle& operator=(const Triangle&) = default;
    Triangle& operator=(Triangle&&) = default;
    ~Triangle() override = default;

    explicit Triangle(const std::string& name, char pen = '*');

};


#endif //GEOMETRIC_SHAPE_DRAWER_TRIANGLE_H
