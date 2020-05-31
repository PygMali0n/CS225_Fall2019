/* Your code here! */
#include "maze.h"
#include <queue>

SquareMaze::SquareMaze(){}

bool SquareMaze::canTravel(int x, int	y, int dir)	const {
  if (dir == 0) {
    return !rightWalls[x+y*width_];
  } else if (dir == 1) {
    return !downWalls[x+y*width_];
  } else if (dir == 2) {
    if (x == 0) {
      return false;
    } else {
      return !rightWalls[x+y*width_-1];
    }
  } else {
    if (y==0) return false;
    return !downWalls[x+(y-1)*width_];
  }
}


PNG * SquareMaze::drawMaze() const {
  PNG * image = new PNG(width_*10+1, height_*10+1);
  for (int i = 0; i < height_*10+1; i++) {
    cs225::HSLAPixel & pixel = image->getPixel(0,i);
    pixel.h = 0;
    pixel.s = 0;
    pixel.l = 0;
  }
  for (int i = 0; i < width_*10+1; i++) {
    if (i == 0 || i > 9) {
      cs225::HSLAPixel & pixel = image->getPixel(i,0);
      pixel.h = 0;
      pixel.s = 0;
      pixel.l = 0;
    }
  }
  int x,y;
  for (int j = 0; j < width_*height_; j++) {
    x = j % width_;
    y = j / width_;
    if (rightWalls[j]) {
      for (unsigned k = 0; k < 11; k++) {
        cs225::HSLAPixel & pixel = image->getPixel((x+1)*10,y*10+k);
        pixel.h = 0;
        pixel.s = 0;
        pixel.l = 0;
      }
    }
    if (downWalls[j]) {
      for (unsigned k = 0; k < 11; k++) {
        cs225::HSLAPixel & pixel = image->getPixel(x*10+k, (y+1)*10);
        pixel.h = 0;
        pixel.s = 0;
        pixel.l = 0;
      }
    }
  }
  return image;
}

PNG * SquareMaze::drawMazeWithSolution() {
  PNG * image = drawMaze();
  vector<int> path = solveMaze();
  cs225::HSLAPixel red(0,1,0.5,1);
  int x = 5;
  int y = 5;
  for (unsigned step = 0; step < path.size(); step++) {
    if (path[step]==0) {
      for (int i = 0; i < 11; i++) {
        cs225::HSLAPixel & p = image->getPixel(x+i, y);
        p.s = red.s;
        p.h = red.h;
        p.l = red.l;
      }
      x+=10;
    }
    if (path[step]==1) {
      for (int i = 0; i < 11; i++) {
        cs225::HSLAPixel & p = image->getPixel(x, y+i);
        p.s = red.s;
        p.h = red.h;
        p.l = red.l;
      }
      y+=10;
    }
    if (path[step]==2) {
      for (int i = 0; i < 11; i++) {
        cs225::HSLAPixel & p = image->getPixel(x-i, y);
        p.s = red.s;
        p.h = red.h;
        p.l = red.l;
      }
      x-=10;
    }
    if (path[step]==3) {
      for (int i = 0; i < 11; i++) {
        cs225::HSLAPixel & p = image->getPixel(x, y-i);
        p.s = red.s;
        p.h = red.h;
        p.l = red.l;
      }
      y-=10;
    }
  }
  x-=5;
  y-=5;
  for (int k = 1; k <10; k++) {
    cs225::HSLAPixel & p = image->getPixel(x+k, y+10);
    p.l = 1;
  }
  return image;
}

PNG * SquareMaze::drawCreativeMaze() {
  PNG * image = drawMaze();
  unsigned midw = image->width()/2;
  unsigned midh = image->height()/2;
  for (unsigned i = 0; i < image->width(); i++) {
    for (unsigned j = 0; j < image->height(); j++) {
      if ((i-midw)*(i-midw)+(j-midh)*(j-midh) >= 200*200) {
        cs225::HSLAPixel & p = image->getPixel(i, j);
        p.l = 1;
      }
    }
  }
  return image;
}

void SquareMaze::makeMaze(int	width, int height) {
    width_ = width;
    height_ = height;
    int size = width * height;
    mazeSet.addelements(size);
    for (int i = 0; i < size; i++) {
      downWalls.push_back(true);
      rightWalls.push_back(true);
    }
    int x,y;
    while (mazeSet.size(0) < size) {
      x = rand() % width_;
      y = rand() % height_;
      if (rand() % 2 == 0) {
        if (x == width_ - 1) {
          continue;
        }
        if (mazeSet.find(x + y * width_) != mazeSet.find(x + y * width_+1)) {
          mazeSet.setunion(x + y * width_, x + y * width_+1);
          rightWalls[x + y*width_] = false;
        }
      } else {
        if (y == height_ - 1) {
          continue;
        }
        if (mazeSet.find(x + y * width_) != mazeSet.find(x+(y+1)*width_)) {
          mazeSet.setunion(x + y * width_, x+(y+1)*width_);
          downWalls[x+y*width_] = false;
        }
      }
    }
}


void SquareMaze::setWall(int x,int y,int dir,bool exists)	{
    if (exists) {
      if (dir==0) {
        rightWalls[x+y*width_] = true;
      } else if (dir==1) {
        downWalls[x+y*width_] = true;
      }
    } else {
      if (dir==0) {
        rightWalls[x+y*width_] = false;
      } else if (dir==1) {
        downWalls[x+y*width_] = false;
      }
    }
}

vector<int> SquareMaze::solveMaze() {
    queue<int> bfs;
    int cur, x, y;
    int size = width_ * height_;
    vector<int> pred;
    vector<int> dist;
    bfs.push(0);
    cur = 0;
    for (int i = 0; i < size; i++) {
      pred.push_back(-1);
      dist.push_back(0);
    }

    while (!bfs.empty()) {
      cur = bfs.front();
      bfs.pop();
      x = cur % width_;
      y = cur / height_;

      if (canTravel(x,y,0)) {
        if (pred[cur+1]==-1) {
          bfs.push(cur+1);
          pred[cur+1]=cur;
          dist[cur+1]=dist[cur]+1;
        }
      }
      if (canTravel(x,y,1)) {
        if (pred[cur+width_]==-1) {
          bfs.push(cur+width_);
          pred[cur+width_]=cur;
          dist[cur+width_]=dist[cur]+1;
        }
      }
      if (canTravel(x,y,2)) {
        if (pred[cur-1]==-1) {
          bfs.push(cur-1);
          pred[cur-1]=cur;
          dist[cur-1]=dist[cur]+1;
        }
      }
      if (canTravel(x,y,3)) {
        if (pred[cur-width_]==-1) {
          bfs.push(cur-width_);
          pred[cur-width_]=cur;
          dist[cur-width_]=dist[cur]+1;
        }
      }
    }

    vector<int> result;
    int dest = width_*(height_-1);
    for (int i = dest; i < size; i++) {
      if (dist[i] > dist[dest]) {
        dest = i;
      }
    }

    int path = dest;
    while (path!=0) {
      if (pred[path]==path-1) {
        result.push_back(0);
      } else if (pred[path]==path+1) {
        result.push_back(2);
      } else if (pred[path]==path-width_) {
        result.push_back(1);
      } else {
        result.push_back(3);
      }
      path = pred[path];
    }
    reverse(result.begin(), result.end());

    return result;

}
