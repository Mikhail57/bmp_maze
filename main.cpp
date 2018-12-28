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

    std::cout << "Generating maze..." << std::endl;
    RGBPixel startColor(36, 28, 237);
    RGBPixel endColor(76, 177, 34);
    MazeWithPoints maze = *MazeUtils().generateMazeFromBmp(file, startColor, endColor);
    std::cout << "End of maze generation" << std::endl;

    PathFinder pathFinder(maze);

    std::cout << "Enter points:" << std::endl;
    for (auto enter : maze.getEnterPoints()) {
        std::cout << enter << std::endl;
    }
    std::cout << "Exit points:" << std::endl;
    for (auto ending : maze.getExitPoints()) {
        std::cout << ending << std::endl;
    }
    std::cout.flush();

    std::vector<std::vector<Point>> results;

    for (auto enter : maze.getEnterPoints()) {
        for (auto exit : maze.getExitPoints()) {
            results.push_back(pathFinder.wave(enter, exit));
        }
    }

    long shortestResult = 0;
    for (int i = 1; i < results.size(); i++) {
        if (results[i].size() < results[shortestResult].size() && results[i].size() != 0) {
            shortestResult = i;
        }
    }

    std::vector<Point> result = results[shortestResult];
    RGBPixel blue;
    blue.blue = 255;
    blue.red = 255;
    blue.green = 0;

    if (result.empty()) {
        std::cout << "No path found..." << std::endl;
    } else {
        std::cout << "Shortest path: " << result.size() << std::endl;
    }

    for (auto elem : result) {
//        std::cout << elem << std::endl;
        file.setPixel(elem.x, elem.y, blue);
    }

    file.save(outputFilename);
    return 0;
}