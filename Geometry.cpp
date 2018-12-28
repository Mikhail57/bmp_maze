//
// Created by misha on 28.12.2018.
//

#include "BmpUtils.h"
#include "Geometry.h"


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

Rect::Rect(int x1, int x2, int y1, int y2) : x1(x1), x2(x2), y1(y1), y2(y2) {}