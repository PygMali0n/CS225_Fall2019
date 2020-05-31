#include <cmath>

#include "Image.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

using cs225::PNG;
using cs225::HSLAPixel;

void Image::lighten() {
  for (unsigned int i = 0; i < this->width(); i++) {
    for (unsigned int j = 0; j < this->height(); j++) {
      HSLAPixel & pixel = this->getPixel(i, j);
      if (pixel.l + 0.1 <= 1.0) {
        pixel.l = pixel.l + 0.1;
      } else {
        pixel.l = 1.0;
      }
    }
  }
}
void Image::lighten(double amount) {
  for (unsigned int i = 0; i < this->width(); i++) {
    for (unsigned int j = 0; j < this->height(); j++) {
      HSLAPixel & pixel = this->getPixel(i, j);
      if (pixel.l + amount <= 1.0) {
        pixel.l = pixel.l + amount;
      } else {
        pixel.l = 1.0;
      }
    }
  }
}
void Image::darken() {
  for (unsigned int i = 0; i < this->width(); i++) {
    for (unsigned int j = 0; j < this->height(); j++) {
      HSLAPixel & pixel = this->getPixel(i, j);
      if (pixel.l - 0.1 >= 0) {
        pixel.l = pixel.l - 0.1;
      } else {
        pixel.l = 0;
      }
    }
  }
}
void Image::darken(double amount) {
  for (unsigned int i = 0; i < this->width(); i++) {
    for (unsigned int j = 0; j < this->height(); j++) {
      HSLAPixel & pixel = this->getPixel(i, j);
      if (pixel.l - amount >= 0) {
        pixel.l = pixel.l - amount;
      } else {
        pixel.l = 0;
      }
    }
  }
}
void Image::saturate() {
  for (unsigned int i = 0; i < this->width(); i++) {
    for (unsigned int j = 0; j < this->height(); j++) {
      HSLAPixel & pixel = this->getPixel(i, j);
      if (pixel.s + 0.1 <= 1.0) {
        pixel.s = pixel.s + 0.1;
      } else {
        pixel.s = 1;
      }
    }
  }
}
void Image::saturate(double amount) {
  for (unsigned int i = 0; i < this->width(); i++) {
    for (unsigned int j = 0; j < this->height(); j++) {
      HSLAPixel & pixel = this->getPixel(i, j);
      if (pixel.s + amount <= 1.0) {
        pixel.s = pixel.s + amount;
      } else {
        pixel.s = 1;
      }
    }
  }
}
void Image::desaturate() {
  for (unsigned int i = 0; i < this->width(); i++) {
    for (unsigned int j = 0; j < this->height(); j++) {
      HSLAPixel & pixel = this->getPixel(i, j);
      if (pixel.s - 0.1 >= 0) {
        pixel.s = pixel.s - 0.1;
      } else {
        pixel.s = 0;
      }
    }
  }
}
void Image::desaturate(double amount) {
  for (unsigned int i = 0; i < this->width(); i++) {
    for (unsigned int j = 0; j < this->height(); j++) {
      HSLAPixel & pixel = this->getPixel(i, j);
      if (pixel.s - amount >= 0) {
        pixel.s = pixel.s - amount;
      } else {
        pixel.s = 0;
      }
    }
  }
}
void Image::grayscale() {
  for (unsigned int i = 0; i < this->width(); i++) {
    for (unsigned int j = 0; j < this->height(); j++) {
      HSLAPixel & pixel = this->getPixel(i, j);
      pixel.s = 0;
    }
  }
}
void Image::rotateColor(double degree) {
  for (unsigned int i = 0; i < this->width(); i++) {
    for (unsigned int j = 0; j < this->height(); j++) {
      HSLAPixel & pixel = this->getPixel(i, j);
      pixel.h = (int) (pixel.h + degree + 360) % 360;
    }
  }
}
void Image::illinify() {
  for (unsigned i = 0; i < this->width(); i++) {
    for (unsigned j = 0; j < this->height(); j++) {
      HSLAPixel & pixel = this->getPixel(i, j);
      if (pixel.h < 113.5 || pixel.h > 293.5) {
        pixel.h = 11;
      }
      if (pixel.h > 113.5 && pixel.h < 293.5) {
        pixel.h = 216;
      }
    }
  }
}

void Image::scale(double factor) {
  if (factor <= 0) {
    return;
  }
  if (factor >= 1) {
    PNG * temp = new PNG(*this);
    this->resize((unsigned int) (factor * this->width()), (unsigned int) (factor * this->height()));
    for (unsigned int i = 0; i < this->width(); i++) {
      for (unsigned int j = 0; j < this->height(); j++) {
        HSLAPixel & pixel = this->getPixel(i, j);
        HSLAPixel & oldpixel = temp->getPixel((unsigned int)(i / factor), (unsigned int)(j / factor));
        pixel = oldpixel;
      }
    }
    delete temp;
  } else {
    PNG * temp = new PNG(*this);
    this->resize((unsigned int) (factor * this->width()), (unsigned int) (factor * this->height()));
    for (unsigned int i = 0; i < this->width(); i++) {
      for (unsigned int j = 0; j < this->height(); j++) {
        HSLAPixel & pixel = this->getPixel(i, j);
        HSLAPixel & oldpixel = temp->getPixel((unsigned) (i / factor), (unsigned) (j / factor));
        pixel = oldpixel;
      }
    }
    delete temp;
  }
}

void Image::scale(unsigned w, unsigned h) {
  double factor;
  if (w/float(this->width()) <= h/float(this->height())) {
    factor = w/float(this->width());
    scale(factor);
  } else {
    factor = h/float(this->height());
    scale(factor);
}
}
