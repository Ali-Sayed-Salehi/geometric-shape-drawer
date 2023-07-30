//
// Created by Ali Sayed Salehi on 2023-07-30.
//

#ifndef GEOMETRIC_SHAPE_DRAWER_TRIANGLE_H
#define GEOMETRIC_SHAPE_DRAWER_TRIANGLE_H


#include "Shape.h"

class Triangle : public Shape{
protected:
    int base{};

public:
    Triangle() = delete;
    Triangle(const Triangle&) = default;
    Triangle(Triangle&&) = default;
    Triangle& operator=(const Triangle&) = default;
    Triangle& operator=(Triangle&&) = default;
    virtual ~Triangle() = default;

    explicit Triangle(int base, const std::string& name, char pen = '*');

    // Getter for 'base'
    int getBase() const {
        return base;
    }

    // Setter for 'base'
    void setBase(int newBase) {
        base = newBase;
    }

};


#endif //GEOMETRIC_SHAPE_DRAWER_TRIANGLE_H
