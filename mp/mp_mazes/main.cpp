#include <iostream>
#include "dsets.h"
#include "maze.h"
#include "cs225/PNG.h"

using namespace std;

int main()
{
    // Write your own main here
    SquareMaze maze;
    maze.makeMaze(50,50);
    PNG * create = maze.drawCreativeMaze();
    create->writeToFile("creative.png");
    delete create;
    return 0;
}
