//
// Created by Mikhail Mustakimov on 2018-12-27.
//

#include "MazeUtils.h"

Maze &MazeUtils::generateMazeFromBmp(BMP &bmp, RGBPixel &startColor, RGBPixel &endColor) {
    Cell **arr;
    arr = new Cell *[bmp.getWidth()];
    for (int i = 0, end = bmp.getWidth(), s = bmp.getHeight(); i < end; i++) {
        arr[i] = new Cell[s];
    }

    RGBPixel black;
    black.red = 0;
    black.green = 0;
    black.blue = 0;

    int startPoint[4] = {bmp.getWidth() - 1, bmp.getHeight() - 1, 0, 0};
    int endPoint[4] = {bmp.getWidth() - 1, bmp.getHeight() - 1, 0, 0};

    for (int x = 0, endX = bmp.getWidth(); x < endX; x++) {
        for (int y = 0, endY = bmp.getHeight(); y < endY; y++) {
            const RGBPixel pixel = bmp.getPixel(x, y);
            if (pixel == black) { // Wall
                arr[x][y].value = -1;
                arr[x][y].visited = false;
            } else {
                if (pixel == startColor) { // Start point
                    if (x < startPoint[0])
                        startPoint[0] = x;
                    if (y < startPoint[1])
                        startPoint[1] = y;
                    if (x > startPoint[2])
                        startPoint[2] = x;
                    if (y > startPoint[3])
                        startPoint[3] = y;
                } else if (pixel == endColor) { // End Point
                    if (x < endPoint[0])
                        endPoint[0] = x;
                    if (y < endPoint[1])
                        endPoint[1] = y;
                    if (x > endPoint[2])
                        endPoint[2] = x;
                    if (y > endPoint[3])
                        endPoint[3] = y;
                }
                arr[x][y].value = 0;
                arr[x][y].visited = false;
            }
        }
    }

    Maze maze(arr, bmp.getWidth(), bmp.getHeight());
    Point start = Point((startPoint[0] + startPoint[2]) / 2, (startPoint[1] + startPoint[3]) / 2);
    Point end = Point((endPoint[0] + endPoint[2]) / 2, (endPoint[1] + endPoint[3]) / 2);
    maze.setStartPoint(start);
    maze.setEndPoint(end);
    return maze;
}
