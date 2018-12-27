//
// Created by misha on 27.12.2018.
//

#ifndef BMP_MAZE_PATHFINDER_H
#define BMP_MAZE_PATHFINDER_H


#include <vector>
#include <utility>
#include <queue>
#include "Maze.h"

class PathFinder {
    Maze maze;
public:
    explicit PathFinder(Maze &maze);

    std::vector<Point> wave();
};


#endif //BMP_MAZE_PATHFINDER_H
