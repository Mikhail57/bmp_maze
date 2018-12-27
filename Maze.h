//
// Created by misha on 27.12.2018.
//

#ifndef BMP_MAZE_MAZE_H
#define BMP_MAZE_MAZE_H

class Cell {
public:
    short value = -1;
    bool visited = false;

    Cell();

    Cell(short value);

    Cell(short value, bool visited);
};

class Point {
public:
    int x;
    int y;

    Point(int x, int y);

    Point();
};

class Maze {
private:
    Cell **array;
    int width;
    int height;

    Point start;
    Point end;
public:
    Maze(Cell **array, int width, int height);

    Cell *operator[](int index);

    void setStartPoint(Point &start);

    void setEndPoint(Point &end);
};


#endif //BMP_MAZE_MAZE_H
