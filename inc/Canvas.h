//
// Created by Ali Sayed Salehi on 2023-07-30.
//

#ifndef GEOMETRIC_SHAPE_DRAWER_CANVAS_H
#define GEOMETRIC_SHAPE_DRAWER_CANVAS_H


#include <vector>

class Canvas {
public:
    // all special members are defaulted because ’grid’,
    // a 2D std::vector, is self-sufficient and efficient,
    // designed to handle the corresponding special operations efficiently
    Canvas() = default;
    virtual ~Canvas() = default;
    Canvas(const Canvas&) = default;
    Canvas(Canvas&&) = default;
    Canvas& operator=(const Canvas&) = default;
    Canvas& operator=(Canvas&&) = default;

    /*
     * creates this canvas’s (rows x columns) grid filled with blank characters
     */
    Canvas(int rows, int columns, char fillChar = ' ');

protected:
    /*
     * a 2D vector representing a canvas
     */
    std::vector<std::vector<char>> grid{};

    /*
     * fill or clear character
     */
    char fillChar{ ' ' };

    /*
     * validates row r and column c, 0-based
     */
    bool check(int r, int c) const;

    /*
     * resizes this Canvas’s dimensions
     */
    void resize(int rows, int cols);

public:
    char getFillChar() const {
        return fillChar;
    }
    void setFillChar(char ch) {
        fillChar = ch;
    }

    std::vector<std::vector<char>> getGrid() const {
        return grid;
    }

    void setGrid(std::vector<std::vector<char>>& newGrid) {
        grid = newGrid;
    }


    /*
     * returns height of this Canvas object
     */
    int getRows() const;

    /*
     * returns width of this Canvas object
     */
    int getColumns() const;

    /*
     * flips this canvas horizontally
     */
    Canvas flip_horizontal() const;

    /*
     * flips this canvas vertically
     */
    Canvas flip_vertical() const;

    /*
     * prints this Canvas to ostream
     */
    void print(std::ostream& os) const;

    /*
     * returns char at row r and column c, 0-based
     * throws std::out_of_range{ "Canvas index out of range" } if r or c is invalid
     */
    char get(int r, int c) const;

    /*
     * puts ch at row r and column c, 0-based;
     * the only function used by a shape’s draw function;
     * throws std::out_of_range{ "Canvas index out of range" } if r or c is invalid.
     */
    void put(int r, int c, char ch);

    /*
     * draws text starting at row r and col c on this canvas
     */
    void drawString(int r, int c, const std::string& text);

    /*
     * copies the non-fill characters of "can" onto the invoking Canvas object;
     * maps can’s origin to row r and column c on the invoking Canvas object
     */
    void overlap(const Canvas& canvas, int r, int c);

    friend std::ostream& operator<< (std::ostream& sout, const Canvas& can);

};


#endif //GEOMETRIC_SHAPE_DRAWER_CANVAS_H
