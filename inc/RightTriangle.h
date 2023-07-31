//
// Created by Ali Sayed Salehi on 2023-07-30.
//

#ifndef GEOMETRIC_SHAPE_DRAWER_RIGHTTRIANGLE_H
#define GEOMETRIC_SHAPE_DRAWER_RIGHTTRIANGLE_H


#include "Triangle.h"

class RightTriangle : public Triangle {
protected:
    int base{};
    int height{};

public:
    RightTriangle() = delete;
    RightTriangle(const RightTriangle&) = default;
    RightTriangle(RightTriangle&&) = default;
    RightTriangle& operator=(const RightTriangle&) = default;
    RightTriangle& operator=(RightTriangle&&) = default;
    ~RightTriangle() override = default;

    explicit RightTriangle(int base, char pen = '*', const std::string& name = "Ladder");

    // Getter for 'base'
    int getBase() const {
        return base;
    }

    // Setter for 'base'
    void setBase(int newBase) {
        base = newBase;
    }

    // Getter for 'height'
    int getHeight() const {
        return height;
    }

    // Setter for 'height'
    void setHeight(int newHeight) {
        height = newHeight;
    }

    std:: string toString() const override;
    double areaGeo() const override;
    double perimeterGeo() const override;
    int areaScr() const override;
    int perimeterScr() const override;
    Canvas draw() const override;

};


#endif //GEOMETRIC_SHAPE_DRAWER_RIGHTTRIANGLE_H
