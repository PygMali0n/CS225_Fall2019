
#include "cs225/PNG.h"
#include "FloodFilledImage.h"
#include "Animation.h"

#include "imageTraversal/DFS.h"
#include "imageTraversal/BFS.h"

#include "colorPicker/RainbowColorPicker.h"
#include "colorPicker/GradientColorPicker.h"
#include "colorPicker/GridColorPicker.h"
#include "colorPicker/SolidColorPicker.h"
#include "colorPicker/MyColorPicker.h"

using namespace cs225;

int main() {

  // @todo [Part 3]
  // - The code below assumes you have an Animation called `animation`
  // - The code provided below produces the `myFloodFill.png` file you must
  //   submit Part 3 of this assignment -- uncomment it when you're ready.
  PNG png;
  png.readFromFile("faye.png");
  FloodFilledImage image(png);
  HSLAPixel p1(10 , 0.8, 0.5);
  HSLAPixel p2(200 , 0.1, 1);
  HSLAPixel p3(60, 1, 0.5);
  MyColorPicker s1(p2, p1, 30);
  MyColorPicker s2(p2, p3, 20);
  BFS bfs(png, Point(400, 400), 0.3);
  DFS dfs(png, Point(620, 450), 0.25);
  image.addFloodFill(bfs, s1);
  image.addFloodFill(dfs, s2);

  Animation animation = image.animate(4000);
  PNG lastFrame = animation.getFrame( animation.frameCount() - 1 );
  lastFrame.writeToFile("myFloodFill.png");
  animation.write("myFloodFill.gif");

  return 0;
}
