#include <iostream>

#include "BMP.h"
#include "PathFinder.h"
#include "MazeUtils.h"

int main(int argc, char **argv) {
    std::string inputFilename("maze.bmp");
    std::string outputFilename("result.bmp");
    if (argc == 2) {
        inputFilename = std::string(argv[1]);
    } else if (argc == 3) {
        inputFilename = std::string(argv[1]);
        outputFilename = std::string(argv[2]);
    } else if (argc > 3) {
        std::cerr << "Wrong number of arguments.\n"
                     "You should use this program like this: ./maze <input>.bmp <output>.bmp\n"
                     "Input image should be 24-bit bmp image without compression and pallet";
        exit(1);
    }

    BMP file(inputFilename);

    RGBPixel startColor(36, 28, 237);
    RGBPixel endColor(76, 177, 34);
    MazeWithPoints maze = MazeUtils().generateMazeFromBmp(file, startColor, endColor);

    PathFinder pathFinder(maze);

    std::vector<Point> result = pathFinder.wave(maze.getEnterPoints()[0], maze.getExitPoints()[0]);
    RGBPixel blue;
    blue.blue = 255;
    blue.red = 255;
    blue.green = 0;

    if (result.empty()) {
        std::cout << "No path found...";
    }

    for (auto elem : result) {
//        std::cout << elem << std::endl;
        file.setPixel(elem.x, elem.y, blue);
    }

    file.save(outputFilename);
    return 0;
}