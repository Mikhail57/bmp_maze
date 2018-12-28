//
// Created by misha on 28.12.2018.
//

#ifndef BMP_MAZE_BMPUTILS_H
#define BMP_MAZE_BMPUTILS_H

#include <queue>
#include <set>

#include "Geometry.h"
#include "BMP.h"

class BmpUtils {
public:
    Rect getEnclosingRect(BMP &bmp, Point &point) const;
};


#endif //BMP_MAZE_BMPUTILS_H
