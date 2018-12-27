//
// Created by misha on 27.12.2018.
//

#include "PathFinder.h"

PathFinder::PathFinder(Maze &maze) : maze(maze) {}

std::vector<Point> PathFinder::wave() {
    std::queue<std::pair<Point, short>> toVisit;

    Point start = maze.getStartPoint();
    Point end = maze.getEndPoint();

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

        if (p == end) {
            found = true;
            break;
        }

        maze[p].visited = true;
        maze[p].value = d;

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
    while (p != start) {
        p = result.back();

        Point pUp(p.x, p.y - 1);
        Point pDown(p.x, p.y + 1);
        Point pLeft(p.x - 1, p.y);
        Point pRight(p.x + 1, p.y);

        if (maze[pUp].value == maze[p].value - 1) {
            result.push_back(pUp);
            continue;
        }
        if (maze[pDown].value == maze[p].value - 1) {
            result.push_back(pDown);
            continue;
        }
        if (maze[pLeft].value == maze[p].value - 1) {
            result.push_back(pLeft);
            continue;
        }
        if (maze[pRight].value == maze[p].value - 1) {
            result.push_back(pRight);
            continue;
        }
    }

    return result;
}
