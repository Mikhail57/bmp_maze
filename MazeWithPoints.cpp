//
// Created by misha on 28.12.2018.
//

#include "MazeWithPoints.h"

const std::vector<Point> &MazeWithPoints::getEnterPoints() const {
    return enterPoints;
}

const std::vector<Point> &MazeWithPoints::getExitPoints() const {
    return exitPoints;
}

void MazeWithPoints::addEnterPoint(Point &point) {
    enterPoints.push_back(point);
}

void MazeWithPoints::addExitPoint(Point &point) {
    exitPoints.push_back(point);
}

MazeWithPoints::MazeWithPoints(Cell **array, int width, int height) : Maze(array, width, height) {}

MazeWithPoints::MazeWithPoints(Cell **array, int width, int height, const std::vector<Point> &enterPoints,
                               const std::vector<Point> &exitPoints) : Maze(array, width, height),
                                                                       enterPoints(enterPoints),
                                                                       exitPoints(exitPoints) {}
