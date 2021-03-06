//
// Created by misha on 27.12.2018.
//

#include "PathFinder.h"

PathFinder::PathFinder(Maze &maze) : maze(maze) {}

std::vector<Point> PathFinder::wave(const Point &startPoint, const Point &endPoint) {
    std::queue<std::pair<Point, short>> toVisit;

    Point start = startPoint;
    Point end = endPoint;

    toVisit.push(std::pair<Point, short>(start, 0));

    bool found = false;

    do {
        Point p = toVisit.front().first;
        short d = toVisit.front().second;
        toVisit.pop();

        if (!maze.isValidPoint(p))
            continue;

        if (maze[p].value == -1)
            continue;

        if (maze[p].visited)
            continue;

        maze[p].visited = true;
        maze[p].value = d;

        if (p == end) {
            found = true;
            break;
        }

        Point pUp(p.x, p.y - 1);
        Point pDown(p.x, p.y + 1);
        Point pLeft(p.x - 1, p.y);
        Point pRight(p.x + 1, p.y);

        toVisit.emplace(pUp, d + 1);
        toVisit.emplace(pDown, d + 1);
        toVisit.emplace(pLeft, d + 1);
        toVisit.emplace(pRight, d + 1);

    } while (!toVisit.empty() && !found);

    std::vector<Point> result;

    if (!found) {
        return result;
    }

    result.push_back(end);

    Point p;
    do {
        p = result.back();

        Point pUp(p.x, p.y - 1);
        Point pDown(p.x, p.y + 1);
        Point pLeft(p.x - 1, p.y);
        Point pRight(p.x + 1, p.y);

        if (maze.isValidPoint(pUp) && maze[pUp].value == maze[p].value - 1) {
            result.push_back(pUp);
            continue;
        }
        if (maze.isValidPoint(pDown) && maze[pDown].value == maze[p].value - 1) {
            result.push_back(pDown);
            continue;
        }
        if (maze.isValidPoint(pLeft) && maze[pLeft].value == maze[p].value - 1) {
            result.push_back(pLeft);
            continue;
        }
        if (maze.isValidPoint(pRight) && maze[pRight].value == maze[p].value - 1) {
            result.push_back(pRight);
            continue;
        }
    } while (p != start);

    return result;
}
