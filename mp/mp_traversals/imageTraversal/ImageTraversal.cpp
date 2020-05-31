#include <cmath>
#include <iterator>
#include <iostream>

#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 *
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );
}

/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator() {
  /** @todo [Part 1] */
  t = NULL;
  end_ = false;
}

ImageTraversal::Iterator::Iterator(const PNG & png, const Point & start, double tolerance, ImageTraversal* trav) {
  t = trav;
  png_ = png;
  start_ = start;
  current_ = start;
  tolerance_ = tolerance;
  for (unsigned i = 0; i < png_.width() * png_.height(); i++) {
    visit_.push_back(false);
  }
  end_ = false;
  path_.push_back(current_);
  visit_[current_.x + current_.y * png_.width()] = true;
}
/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
  Point right = Point(current_.x + 1,current_.y);
  Point down = Point(current_.x, current_.y + 1);
  Point up = Point(current_.x, current_.y - 1);
  Point left = Point(current_.x - 1, current_.y);
  if (validPoint(right)) t->add(right);
  if (validPoint(down)) t->add(down);
  if (validPoint(left)) t->add(left);
  if (validPoint(up)) t->add(up);

  if (t->empty()) {
    end_ = true;
    return *this;
  }

  Point next = t->pop();
  while (visit_[next.x + next.y * png_.width()]) {
    if (t->empty()) {
      end_ = true;
      return *this;
    }
    next = t->pop();
  }
  current_ = next;
  visit_[current_.x + current_.y * png_.width()] = true;
  path_.push_back(current_);
  return *this;
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return current_;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */
  if (end_ == other.end_) {
    return false;
  }
  return true;
}

void ImageTraversal::Iterator::setEnd() {
  end_ = true;
}

bool ImageTraversal::Iterator::validPoint(const Point & p) {
  if (p.x >= png_.width() || p.y >= png_.height() || p.x < 0 || p.y < 0) {
    return false;
  }
  HSLAPixel org = png_.getPixel(start_.x, start_.y);
  HSLAPixel thisp = png_.getPixel(p.x, p.y);
  if (calculateDelta(org, thisp) >= tolerance_) {
    return false;
  }
  return true;
}
