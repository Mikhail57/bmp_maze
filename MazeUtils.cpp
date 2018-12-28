//
// Created by Mikhail Mustakimov on 2018-12-27.
//

#include "MazeUtils.h"

MazeWithPoints & MazeUtils::generateMazeFromBmp(BMP &bmp, RGBPixel &startColor, RGBPixel &endColor) {
    Cell **arr;
    arr = new Cell *[bmp.getWidth()];
    for (int i = 0, end = bmp.getWidth(), s = bmp.getHeight(); i < end; i++) {
        arr[i] = new Cell[s];
    }

    RGBPixel black;
    black.red = 0;
    black.green = 0;
    black.blue = 0;

    std::vector<Point> startColorPoints;
    std::vector<Point> endColorPoints;

    for (int x = 0, endX = bmp.getWidth(); x < endX; x++) {
        for (int y = 0, endY = bmp.getHeight(); y < endY; y++) {
            const RGBPixel pixel = bmp.getPixel(x, y);
            if (pixel == black) { // Wall
                arr[x][y].value = -1;
                arr[x][y].visited = false;
            } else {
                arr[x][y].value = 0;
                arr[x][y].visited = false;
                if (pixel == startColor) {
                    startColorPoints.emplace_back(x, y);
                } else if (pixel == endColor) {
                    endColorPoints.emplace_back(x, y);
                }
            }
        }
    }



    MazeWithPoints maze(arr, bmp.getWidth(), bmp.getHeight());
    return maze;
}
