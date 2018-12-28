#include <iostream>

#include "BMP.h"
#include "PathFinder.h"
#include "MazeUtils.h"

int main() {
    BMP file("dnk.bmp");

    RGBPixel startColor(36, 28, 237);
    RGBPixel endColor(76, 177, 34);
    Maze maze = MazeUtils().generateMazeFromBmp(file, startColor, endColor);

//    Point start = Point(135, 687);
//    Point end = Point(1254, 523);
//    maze.setStartPoint(start);
//    maze.setEndPoint(end);

    PathFinder pathFinder(maze);

    std::vector<Point> result = pathFinder.wave();
    RGBPixel blue;
    blue.blue = 255;
    blue.red = 255;
    blue.green = 0;

//    file.setPixel(file.getWidth() - 1, file.getHeight() - 1, blue);
//    for (int i = 0; i < file.getHeight(); i++) {
//        file.setPixel(file.getWidth() - 1, i, blue);
//    }
    for (auto elem : result) {
        std::cout << elem << std::endl;
        file.setPixel(elem.x, elem.y, blue);
    }

    file.save("lol.bmp");
    return 0;
}