//
// Created by Ali Sayed Salehi on 2023-07-30.
//

#ifndef GEOMETRIC_SHAPE_DRAWER_ACUTETRIANGLE_H
#define GEOMETRIC_SHAPE_DRAWER_ACUTETRIANGLE_H


#include "Triangle.h"

class AcuteTriangle : public Triangle {
protected:
    int base{};
    int height{};

public:
    AcuteTriangle() = delete;
    AcuteTriangle(const AcuteTriangle&) = default;
    AcuteTriangle(AcuteTriangle&&) = default;
    AcuteTriangle& operator=(const AcuteTriangle&) = default;
    AcuteTriangle& operator=(AcuteTriangle&&) = default;
    ~AcuteTriangle() override = default;

    explicit AcuteTriangle(int base, int height, const std::string& name = "Wedge", char pen = '*');

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
    //Canvas draw() const;
};


#endif //GEOMETRIC_SHAPE_DRAWER_ACUTETRIANGLE_H
