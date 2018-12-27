//
// Created by Mikhail Mustakimov on 2018-12-27.
//

#include "MazeUtils.h"

Maze MazeUtils::generateMazeFromBmp(BMP &bmp) {
    Cell **arr;
    arr = new Cell *[bmp.getWidth()];
    for (int i = 0, end = bmp.getWidth(), s = bmp.getHeight(); i < end; i++) {
        arr[i] = new Cell[s];
    }

    RGBPixel black;
    black.red = 0;
    black.green = 0;
    black.blue = 0;

    for (int x = 0, endX = bmp.getWidth(); x < endX; x++) {
        for (int y = 0, endY = bmp.getHeight(); y < endY; y++) {
            if (bmp.getPixel(x, y) == black) {
                arr[x][y].value = -1;
                arr[x][y].visited = false;
            } else {
                arr[x][y].value = 0;
                arr[x][y].visited = false;
            }
        }
    }
    return {arr, bmp.getWidth(), bmp.getHeight()};
}
