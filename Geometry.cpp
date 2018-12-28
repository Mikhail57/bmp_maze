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

Rect::Rect(int x1, int y1, int x2, int y2) : x0(x1), x1(x2), y0(y1), y1(y2) {}

bool Rect::operator==(const Rect &rhs) const {
    return x0 == rhs.x0 &&
           x1 == rhs.x1 &&
           y0 == rhs.y0 &&
           y1 == rhs.y1;
}

bool Rect::operator!=(const Rect &rhs) const {
    return !(rhs == *this);
}

Point Rect::getTopLeft() const {
    return {x0, y0};
}

Point Rect::getBottomRight() const {
    return {x1, y1};
}

bool Rect::operator<(const Rect &rhs) const {
    if (x0 < rhs.x0)
        return true;
    if (rhs.x0 < x0)
        return false;
    if (x1 < rhs.x1)
        return true;
    if (rhs.x1 < x1)
        return false;
    if (y0 < rhs.y0)
        return true;
    if (rhs.y0 < y0)
        return false;
    return y1 < rhs.y1;
}

bool Rect::operator>(const Rect &rhs) const {
    return rhs < *this;
}

bool Rect::operator<=(const Rect &rhs) const {
    return !(rhs < *this);
}

bool Rect::operator>=(const Rect &rhs) const {
    return !(*this < rhs);
}

std::ostream &operator<<(std::ostream &os, const Rect &rect) {
    os << "Rect(x0: " << rect.x0 << " x1: " << rect.x1 << " y0: " << rect.y0 << " y1: " << rect.y1 << ")";
    return os;
}
