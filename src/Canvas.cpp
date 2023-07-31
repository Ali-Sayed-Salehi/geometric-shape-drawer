//
// Created by Ali Sayed Salehi on 2023-07-30.
//

#include <algorithm>
#include <iostream>
#include "Canvas.h"

Canvas::Canvas(int rows, int columns, char fillChar) :
    grid(rows, std::vector<char>(columns, fillChar)) {
}

bool Canvas::check(int r, int c) const {
    return ((r < this->getRows()) && (c < this->getColumns()));
}

void Canvas::resize(int rows, int cols) {
    grid.resize(rows, std::vector<char>(cols, ' '));
}

int Canvas::getRows() const {
    return grid.empty() ? 0 : static_cast<int>(grid.size());
}

int Canvas::getColumns() const {
    return grid.empty() ? 0 : static_cast<int>(grid[0].size());
}

Canvas Canvas::flip_horizontal() const {

    Canvas flippedCanvas = *this;
    auto newGrid = flippedCanvas.getGrid();
    for (auto& row : newGrid) {
        std::reverse(row.begin(), row.end());
    }
    flippedCanvas.setGrid(newGrid);
    return flippedCanvas;
}

Canvas Canvas::flip_vertical() const {
    Canvas flippedCanvas(*this);
    auto newGrid = flippedCanvas.getGrid();
    std::reverse(newGrid.begin(), newGrid.end());
    flippedCanvas.setGrid(newGrid);
    return flippedCanvas;
}

void Canvas::print(std::ostream & os) const {
    for (const auto& row : grid) {
        for (auto& element : row) {
            os << element << " ";
        }
        os << "\n";
    }
}

char Canvas::get(int r, int c) const {
    if (!this->check(r, c)) {
        throw std::out_of_range{ "Canvas index out of range" };
    }
    return grid[r][c];
}

void Canvas::put(int r, int c, char ch) {
    if (!this->check(r, c)) {
        throw std::out_of_range{ "Canvas index out of range" };
    }
    grid[r][c] = ch;
}

void Canvas::drawString(int r, int c, const std::string& text) {
    if (!this->check(r, c)) {
        throw std::out_of_range{ "Canvas index out of range" };
    }

    for (auto& ch: text){
        this->put(r, c, ch);

        // go to the next element in this->grid
        if ((c + 1) > this->getColumns() - 1) {
            c = 0;
            r++;
        } else {
            c++;
        }
    }
}

void Canvas::overlap(const Canvas &canvas, int r, int c) {
    if (!this->check(r, c)) {
        throw std::out_of_range{ "Canvas index out of range" };
    }

    for (auto& row : canvas.getGrid()){
        for (auto& element: row){
            if (element != ' ') put(r, c, element);

            // go to the next element in this->grid
            if ((c + 1) > this->getColumns() - 1) {
                c = 0;
                r++;
            } else {
                c++;
            }
        }
    }
}

std::ostream &operator<<(std::ostream &sout, const Canvas &can) {
    can.print(sout);
    return sout;
}
