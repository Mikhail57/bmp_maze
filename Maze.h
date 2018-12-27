//
// Created by misha on 27.12.2018.
//

#ifndef BMP_MAZE_MAZE_H
#define BMP_MAZE_MAZE_H

#include <ostream>

class Cell {
public:
    short value = -1;
    bool visited = false;

    Cell();

    explicit Cell(short value);

    Cell(short value, bool visited);
};

class Point {
public:
    int x;
    int y;

    Point(int x, int y);

    Point();

    friend std::ostream &operator<<(std::ostream &os, const Point &point);

    bool operator==(const Point &rhs) const;

    bool operator!=(const Point &rhs) const;
};

class Maze {
private:
    Cell **array;
    int width;
    int height;

    Point start;
    Point end;

    bool isValidPoint(const Point &p);

public:
    Maze(Cell **array, int width, int height);

    Cell *operator[](int index);

    Cell &operator[](const Point index);


    void setStartPoint(Point &start);

    void setEndPoint(Point &end);


    const Point &getStartPoint() const;

    const Point &getEndPoint() const;

    int getWidth() const;

    int getHeight() const;


    friend class PathFinder;
};


#endif //BMP_MAZE_MAZE_H
