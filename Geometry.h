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
    int x0;
    int x1;
    int y0;
    int y1;
public:
    Rect(int x1, int y1, int x2, int y2);

    Point getTopLeft() const;
    Point getBottomRight() const;

    friend std::ostream &operator<<(std::ostream &os, const Rect &rect);

    bool operator==(const Rect &rhs) const;

    bool operator!=(const Rect &rhs) const;

    bool operator<(const Rect &rhs) const;

    bool operator>(const Rect &rhs) const;

    bool operator<=(const Rect &rhs) const;

    bool operator>=(const Rect &rhs) const;
};

#endif //BMP_MAZE_GEOMETRY_H
