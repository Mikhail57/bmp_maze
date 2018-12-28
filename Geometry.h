//
// Created by misha on 28.12.2018.
//

#ifndef BMP_MAZE_GEOMETRY_H
#define BMP_MAZE_GEOMETRY_H

#include <exception>
#include <stdexcept>
#include <ostream>


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

class Rect {
private:
    int x1;
    int x2;
    int y1;
    int y2;
public:
    Rect(int x1, int x2, int y1, int y2);
};

#endif //BMP_MAZE_GEOMETRY_H
