//
// Created by Ali Sayed Salehi on 2023-07-30.
//

#ifndef GEOMETRIC_SHAPE_DRAWER_SHAPE_H
#define GEOMETRIC_SHAPE_DRAWER_SHAPE_H


#include <cstddef>
#include <string>

class Shape {
protected:
    std::string name{};
    char pen{'*'};
    static int idCount;
    int idNumber{};

public:
    Shape() = delete;
    Shape(const Shape&) = default;
    Shape(Shape&&) = default;
    Shape& operator=(const Shape&) = default;
    Shape& operator=(Shape&&) = default;
    virtual ~Shape() = default;

    explicit Shape(const std::string& name, char pen = '*');

    // Getter for 'name'
    std::string getName() const {
        return name;
    }

    // Setter for 'name'
    void setName(const std::string& newName) {
        name = newName;
    }

    // Getter for 'pen'
    char getPen() const {
        return pen;
    }

    // Setter for 'pen'
    void setPen(char newPen) {
        pen = newPen;
    }

    // Getter for 'idNumber'
    int getIdNumber() const {
        return idNumber;
    }

    // Setter for 'idNumber'
    void setIdNumber(int newIdNumber) {
        idNumber = newIdNumber;
    }


    /*
     * returns a std::string representation of the Shape object invoking it
     */
    virtual std:: string toString() const = 0;

    void print(std::ostream& os) const;

    friend std::ostream& operator<<(std::ostream& os, const Shape& shape);

    /*
     * computes and returns the shape’s geometric area
     */
    virtual double areaGeo() const = 0;

    /*
     * computes and returns the shape’s geometric perimeter
     */
    virtual double perimeterGeo() const = 0;

    /*
     * computes and returns the shape’s screen area,
     * the number of characters forming the textual image of the shape
     */
    virtual int areaScr() const = 0;

    /*
     * computes and returns the shape’s screen perimeter,
     * the number of characters on the borders of the textual image of the shape
     */
    virtual int perimeterScr() const = 0;

    /*
     * draws a textual image of the shape on a Canvas object using the shape’s pen character
     */
    //virtual Canvas draw() const = 0;

};


#endif //GEOMETRIC_SHAPE_DRAWER_SHAPE_H
