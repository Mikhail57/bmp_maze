cmake_minimum_required(VERSION 3.13)
project(bmp_maze)

set(CMAKE_CXX_STANDARD 14)

add_executable(bmp_maze main.cpp BMP.cpp BMP.h PathFinder.cpp PathFinder.h Maze.cpp Maze.h MazeUtils.cpp MazeUtils.h MazeWithPoints.cpp MazeWithPoints.h BmpUtils.cpp BmpUtils.h Geometry.h Geometry.cpp)