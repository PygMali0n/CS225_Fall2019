#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include <string>


void rotate(std::string inputFile, std::string outputFile) {
  // TODO: Part 2
  cs225::PNG inimage;
  if (inimage.readFromFile(inputFile)) {
    cs225::PNG outimage(inimage.width(), inimage.height());
    for (unsigned x = 0; x < inimage.width(); x++) {
      for (unsigned y = 0; y < inimage.height(); y++) {
        cs225::HSLAPixel & pixeli = inimage.getPixel(x, y);
        cs225::HSLAPixel & pixelo = outimage.getPixel(inimage.width() - 1 - x, inimage.height() - 1 - y);
        pixelo.h = pixeli.h;
        pixelo.l = pixeli.l;
        pixelo.s = pixeli.s;
        pixelo.a = pixeli.a;
      }
    }
    outimage.writeToFile(outputFile);
  }
  return;
}

cs225::PNG myArt(unsigned int width, unsigned int height) {
  cs225::PNG png(width, height);
  // TODO: Part 3
  for (unsigned x = 0; x < width; x++) {
    for (unsigned y = 0; y < height; y++) {
      cs225::HSLAPixel & pixel = png.getPixel(x, y);
      pixel.s = 1;
      pixel.a = 0.5;
      if (x == y) {
        pixel.l = 1;
      }
      if (x < y) {
        pixel.h = 60 * (float)x / (float)y;
        pixel.l = 0.75;
      } else if (x > y) {
        pixel.h = 90 * (float)y / (float)x + 180;
        pixel.l = (float)y / (float)x;
      }
    }
  }

  return png;
}
