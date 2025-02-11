#pragma once

#include "ColorPicker.h"
#include "../cs225/HSLAPixel.h"
#include "../Point.h"

using namespace cs225;

/**
 * A color picker class using your own color picking algorithm
 */
class MyColorPicker : public ColorPicker {
public:
  MyColorPicker(HSLAPixel color, HSLAPixel othercolor, unsigned space);

  HSLAPixel getColor(unsigned x, unsigned y);

private:
  HSLAPixel color_;
  HSLAPixel othercolor_;
  unsigned space_;
};
