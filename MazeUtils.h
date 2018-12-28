//
// Created by Mikhail Mustakimov on 2018-12-27.
//

#ifndef BMP_MAZE_MAZEUTILS_H
#define BMP_MAZE_MAZEUTILS_H


#include "Maze.h"
#include "BMP.h"
#include "MazeWithPoints.h"

class MazeUtils {
public:
    MazeWithPoints & generateMazeFromBmp(BMP &bmp, RGBPixel &startColor, RGBPixel &endColor);
};


#endif //BMP_MAZE_MAZEUTILS_H
