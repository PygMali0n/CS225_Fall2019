#include "../cs225/HSLAPixel.h"
#include "../Point.h"

#include "ColorPicker.h"
#include "MyColorPicker.h"

using namespace cs225;

/**
 * Picks the color for pixel (x, y).
 * Using your own algorithm
 */
MyColorPicker::MyColorPicker(HSLAPixel color, HSLAPixel othercolor, unsigned space) {
  color_ = color;
  othercolor_ = othercolor;
  space_ = space;
}

HSLAPixel MyColorPicker::getColor(unsigned x, unsigned y) {
  /* @todo [Part 3] */
  if ((x + y) % space_ == 0) {
    return color_;
  } else {
    return othercolor_;
  }
}
