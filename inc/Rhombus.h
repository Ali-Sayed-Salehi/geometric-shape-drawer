//
// Created by Ali Sayed Salehi on 2023-07-30.
//

#ifndef GEOMETRIC_SHAPE_DRAWER_RHOMBUS_H
#define GEOMETRIC_SHAPE_DRAWER_RHOMBUS_H


#include "Shape.h"

class Rhombus : public Shape {
protected:
    int diagonal{};

public:
    Rhombus() = delete;
    Rhombus(const Rhombus&) = default;
    Rhombus(Rhombus&&) = default;
    Rhombus& operator=(const Rhombus&) = default;
    Rhombus& operator=(Rhombus&&) = default;
    ~Rhombus() override = default;

    explicit Rhombus(int diagonal, char pen = '*', const std::string& name = "Diamond");

    // Getter for 'diagonal'
    int getDiagonal() const {
        return diagonal;
    }

    // Setter for 'diagonal'
    void setDiagonal(int newDiagonal) {
        diagonal = newDiagonal;
    }

    std:: string toString() const override;
    double areaGeo() const override;
    double perimeterGeo() const override;
    int areaScr() const override;
    int perimeterScr() const override;
    Canvas draw() const override;

};


#endif //GEOMETRIC_SHAPE_DRAWER_RHOMBUS_H
