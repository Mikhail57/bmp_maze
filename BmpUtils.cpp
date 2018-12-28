//
// Created by misha on 28.12.2018.
//

#include "BmpUtils.h"

Rect BmpUtils::getEnclosingRect(BMP &bmp, Point &point) const {
    RGBPixel original = bmp[point];

    BMP copy(bmp);

    std::queue<Point> toVisit;

    toVisit.push(point);
    while (!toVisit.empty()) {
        Point p = toVisit.front();
        if (copy[p] != original) {

        }

        Point pUp(p.x, p.y + 1);
        Point pDown(p.x, p.y - 1);
        Point pLeft(p.x - 1, p.y);
        Point pRight(p.x + 1, p.y);
    }


    return Rect(0, 0, 0, 0);
}
