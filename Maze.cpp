//
// Created by misha on 27.12.2018.
//

#include "Maze.h"

Maze::Maze(Cell **array, int width, int height) : array(array), width(width), height(height) {}

Cell *Maze::operator[](int index) {
    return array[index];
}

void Maze::setStartPoint(Point &start) {
    this->start = start;
}

void Maze::setEndPoint(Point &end) {
    this->end = end;
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
