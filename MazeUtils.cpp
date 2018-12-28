//
// Created by Mikhail Mustakimov on 2018-12-27.
//

#include "MazeUtils.h"

MazeWithPoints * MazeUtils::generateMazeFromBmp(BMP &bmp, RGBPixel &startColor, RGBPixel &endColor) {
    Cell **arr;
    arr = new Cell *[bmp.getWidth()];
    for (int i = 0, end = bmp.getWidth(), s = bmp.getHeight(); i < end; i++) {
        arr[i] = new Cell[s];
    }

    RGBPixel black;
    black.red = 0;
    black.green = 0;
    black.blue = 0;

    std::set<Rect> starts;
    std::set<Rect> ends;

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
                    bool shouldSearch = true;
                    for (auto rect : starts) {
                        if (x >= rect.getTopLeft().x && x <= rect.getBottomRight().x &&
                            y >= rect.getTopLeft().y && y <= rect.getBottomRight().y) {
                            shouldSearch = false;
                            break;
                        }
                    }
                    if (shouldSearch) {
                        Point point(x, y);
                        Rect rect = BmpUtils().getEnclosingRect(bmp, point);
                        starts.insert(rect);
                    }
                } else if (pixel == endColor) {
                    bool shouldSearch = true;
                    for (auto rect : starts) {
                        if (x >= rect.getTopLeft().x && x <= rect.getBottomRight().x &&
                            y >= rect.getTopLeft().y && y <= rect.getBottomRight().y) {
                            shouldSearch = false;
                            break;
                        }
                    }
                    if (shouldSearch) {
                        Point point(x, y);
                        Rect rect = BmpUtils().getEnclosingRect(bmp, point);
                        ends.insert(rect);
                    }
                }
            }
        }
    }

    MazeWithPoints *maze = new MazeWithPoints(arr, bmp.getWidth(), bmp.getHeight());
    for (auto rect : starts) {
        std::cout << rect << std::endl;
        Point tl = rect.getTopLeft();
        Point br = rect.getBottomRight();

        int x = (tl.x + br.x) / 2;
        int y = (tl.y + br.y) / 2;

        Point point = Point(x, y);
        maze->addEnterPoint(point);
    }
    for (auto rect : ends) {
        std::cout << rect << std::endl;
        Point tl = rect.getTopLeft();
        Point br = rect.getBottomRight();

        int x = (tl.x + br.x) / 2;
        int y = (tl.y + br.y) / 2;

        Point point = Point(x, y);
        maze->addExitPoint(point);
    }

    return maze;
}
