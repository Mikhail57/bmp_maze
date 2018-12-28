//
// Created by misha on 27.12.2018.
//

#include <exception>
#include <stdexcept>
#include "Maze.h"

Maze::Maze(Cell **array, int width, int height) : array(array), width(width), height(height) {}

Cell *Maze::operator[](int index) {
    return array[index];
}

void Maze::setStartPoint(Point &start) {
    if (!isValidPoint(start))
        throw std::invalid_argument("Start point should be valid");
    this->start = start;
}

void Maze::setEndPoint(Point &end) {
    if (!isValidPoint(end))
        throw std::invalid_argument("End point should be valid");
    this->end = end;
}

const Point &Maze::getStartPoint() const {
    return start;
}

const Point &Maze::getEndPoint() const {
    return end;
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

Point::Point(int x, int y) : x(x), y(y) {}

Point::Point() {
    x = 0;
    y = 0;
}

bool Point::operator==(const Point &rhs) const {
    return x == rhs.x &&
           y == rhs.y;
}

bool Point::operator!=(const Point &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Point &point) {
    os << "Point(x: " << point.x << " y: " << point.y << ")";
    return os;
}
