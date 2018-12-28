//
// Created by misha on 27.12.2018.
//

#include "Maze.h"
#include "Geometry.h"

Maze::Maze(Cell **array, int width, int height) : array(array), width(width), height(height) {}

Cell *Maze::operator[](int index) {
    return array[index];
}

int Maze::getWidth() const {
    return width;
}

int Maze::getHeight() const {
    return height;
}

bool Maze::isValidPoint(const Point &p) {
    return (p.x >= 0 && p.x < width && p.y >= 0 && p.y < height);
}

Cell &Maze::operator[](const Point index) {
    return array[index.x][index.y];
}

Cell::Cell(short value, bool visited) : value(value), visited(visited) {}

Cell::Cell() {
    value = -1;
    visited = false;
}

Cell::Cell(short value) : value(value) {
    visited = false;
}

