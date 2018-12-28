//
// Created by misha on 28.12.2018.
//

#ifndef BMP_MAZE_MAZEWITHPOINTS_H
#define BMP_MAZE_MAZEWITHPOINTS_H

#include <vector>
#include "Maze.h"
#include "Geometry.h"


class MazeWithPoints : public Maze {
private:
    std::vector<Point> enterPoints;
    std::vector<Point> exitPoints;
public:

    MazeWithPoints(Cell **array, int width, int height);

    MazeWithPoints(Cell **array, int width, int height, const std::vector<Point> &enterPoints,
                   const std::vector<Point> &exitPoints);

    const std::vector<Point> &getEnterPoints() const;

    const std::vector<Point> &getExitPoints() const;

    void addEnterPoint(Point &point);

    void addExitPoint(Point &point);
};


#endif //BMP_MAZE_MAZEWITHPOINTS_H
