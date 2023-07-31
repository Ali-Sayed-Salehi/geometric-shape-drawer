//
// Created by Ali Sayed Salehi on 2023-07-30.
//

#ifndef GEOMETRIC_SHAPE_DRAWER_RECTANGLE_H
#define GEOMETRIC_SHAPE_DRAWER_RECTANGLE_H


#include "Shape.h"

class Rectangle : public Shape {
protected:
    int height{};
    int width{};

public:
    Rectangle() = delete;
    Rectangle(const Rectangle&) = default;
    Rectangle(Rectangle&&) = default;
    Rectangle& operator=(const Rectangle&) = default;
    Rectangle& operator=(Rectangle&&) = default;
    ~Rectangle() override = default;

    Rectangle(int height, int width, char pen = '*', const std::string& name = "Door");

    // Getter for 'height'
    int getHeight() const {
        return height;
    }

    // Setter for 'height'
    void setHeight(int newHeight) {
        height = newHeight;
    }

    // Getter for 'width'
    int getWidth() const {
        return width;
    }

    // Setter for 'width'
    void setWidth(int newWidth) {
        width = newWidth;
    }

    std:: string toString() const override;
    double areaGeo() const override;
    double perimeterGeo() const override;
    int areaScr() const override;
    int perimeterScr() const override;
    Canvas draw() const override;
};


#endif //GEOMETRIC_SHAPE_DRAWER_RECTANGLE_H
