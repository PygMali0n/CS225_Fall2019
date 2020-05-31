/* Your code here! */
#pragma once

#include <vector>
#include "cs225/PNG.h"
#include "dsets.h"
using namespace std;
using cs225::PNG;

class SquareMaze {
  public:
    SquareMaze();
    bool canTravel(int x, int	y, int dir)	const;
    PNG * drawMaze() const;
    PNG * drawMazeWithSolution();
    PNG * drawCreativeMaze();
    void makeMaze(int	width, int height);
    void setWall(int x,int y,int dir,bool exists);
    vector<int> solveMaze();
  private:
    int width_;
    int height_;
    DisjointSets mazeSet;
    vector<bool> downWalls;
    vector<bool> rightWalls;
};
