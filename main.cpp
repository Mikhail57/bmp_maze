#include <iostream>

#include "BMP.h"
#include "PathFinder.h"
#include "MazeUtils.h"

int main() {
    BMP file("dnk.bmp");

    Maze maze = MazeUtils().generateMazeFromBmp(file);

    PathFinder pathFinder(maze);

    std::vector<Point> result = pathFinder.wave();
    for (auto elem : result) {
        std::cout << elem << std::endl;
    }

    file.save("lol.bmp");
    return 0;
}