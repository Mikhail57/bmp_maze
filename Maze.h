//
// Created by misha on 27.12.2018.
//

#ifndef BMP_MAZE_MAZE_H
#define BMP_MAZE_MAZE_H

#include "Geometry.h"

class Cell {
public:
    short value = -1;
    bool visited = false;

    Cell();

    explicit Cell(short value);

    Cell(short value, bool visited);
};

class Maze {
private:
    Cell **array;
    int width;
    int height;

    bool isValidPoint(const Point &p);

public:
    Maze(Cell **array, int width, int height);

    Cell *operator[](int index);

    Cell &operator[](const Point index);

    int getWidth() const;

    int getHeight() const;


    friend class PathFinder;
};


#endif //BMP_MAZE_MAZE_H
