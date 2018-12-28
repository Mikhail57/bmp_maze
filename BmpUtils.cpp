//
// Created by misha on 28.12.2018.
//

#include "BmpUtils.h"

#include <iostream>

inline bool isValidPoint(BMP &bmp, Point &point) {
    return point.x >= 0 && point.y >= 0 && point.x < bmp.getWidth() && point.y < bmp.getHeight();
}

Rect BmpUtils::getEnclosingRect(BMP &bmp, Point &point) const {
    RGBPixel original = bmp[point];
    RGBPixel other = original;
    other.blue += 10;

    BMP copy(bmp);

    std::queue<Point> toVisit;

    int x0 = copy.getWidth() - 1;
    int y0 = copy.getHeight() - 1;
    int x1 = 0;
    int y1 = 0;

    toVisit.push(point);
    while (!toVisit.empty()) {
        Point p = toVisit.front();
        toVisit.pop();

        if (!isValidPoint(copy, p)) {
            continue;
        }

        if (copy[p] != original) {
            continue;
        }

        if (p.x < x0) x0 = p.x;
        if (p.y < y0) y0 = p.y;
        if (p.x > x1) x1 = p.x;
        if (p.y > y1) y1 = p.y;

//        std::cout << copy[p] << std::endl;
        copy.setPixel(p.x, p.y, other);
//        std::cout << copy[p] << std::endl;


        toVisit.emplace(p.x, p.y + 1);
        toVisit.emplace(p.x, p.y - 1);
        toVisit.emplace(p.x - 1, p.y);
        toVisit.emplace(p.x + 1, p.y);
    }


    return {x0, y0, x1, y1};
}
