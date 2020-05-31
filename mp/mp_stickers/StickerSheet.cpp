#include "Image.h"
#include "StickerSheet.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

using cs225::PNG;
using cs225::HSLAPixel;

StickerSheet::StickerSheet(const Image & picture, unsigned max) {
  maxStickers = max;
  base = picture;
  stickers = new Image[maxStickers];
  ind = new int[maxStickers];
  xco = new int[maxStickers];
  yco = new int[maxStickers];
  for (unsigned i = 0; i < maxStickers; i++) {
    ind[i] = 0;
  }
}

StickerSheet::~StickerSheet() {
  delete[] stickers;
  delete[] xco;
  delete[] yco;
  delete[] ind;
}

StickerSheet::StickerSheet(const StickerSheet & other) {
  maxStickers = other.maxStickers;
  base = other.base;
  stickers = new Image[maxStickers];
  xco = new int[maxStickers];
  yco = new int[maxStickers];
  ind = new int[maxStickers];
  for (unsigned int i = 0; i < maxStickers; i++) {
      stickers[i] = other.stickers[i];
      xco[i] = other.xco[i];
      yco[i] = other.yco[i];
      ind[i] = other.ind[i];
  }
}

const StickerSheet & StickerSheet::operator=(const StickerSheet & other) {
  if (this != &other) {
    delete[] stickers;
    delete[] xco;
    delete[] yco;
    delete[] ind;
    maxStickers = other.maxStickers;
    base = other.base;
    stickers = new Image[maxStickers];
    xco = new int[maxStickers];
    yco = new int[maxStickers];
    ind = new int[maxStickers];
    for (unsigned int i = 0; i < maxStickers; i++) {
        stickers[i] = other.stickers[i];
        xco[i] = other.xco[i];
        yco[i] = other.yco[i];
        ind[i] = other.ind[i];
    }
    return *this;
  }
  return *this;
}


void StickerSheet::changeMaxStickers(unsigned max) {
  Image * newstickers = new Image[max];
  int* newxco = new int[max];
  int* newyco = new int[max];
  int* newind = new int[max];
  if (max >= maxStickers) {
    for (unsigned int i = 0; i < maxStickers; i++) {
      newstickers[i] = stickers[i];
      newxco[i] = xco[i];
      newyco[i] = yco[i];
      newind[i] = ind[i];
    }
    for (unsigned int i = maxStickers; i < max; i++) {
      newind[i] = 0;
    }
    delete[] stickers;
    delete[] xco;
    delete[] yco;
    delete[] ind;
    stickers = newstickers;
    xco = newxco;
    yco = newyco;
    ind = newind;
    maxStickers = max;
  } else {
    for (unsigned j = 0; j < max; j++) {
      newstickers[j] = stickers[j];
      newxco[j] = xco[j];
      newyco[j] = yco[j];
      newind[j] = ind[j];
    }
    delete[] stickers;
    delete[] xco;
    delete[] yco;
    delete[] ind;
    stickers = newstickers;
    xco = newxco;
    yco = newyco;
    ind = newind;
    maxStickers = max;
  }
}

int StickerSheet::addSticker(Image & sticker, unsigned x, unsigned y) {
  for (unsigned i = 0; i < maxStickers; i++) {
    if (ind[i] == 0) {
      stickers[i] = Image(sticker);
      xco[i] = x;
      yco[i] = y;
      ind[i] = 1;
      return i;
    }
  }
  return -1;
}
bool StickerSheet::translate(unsigned index, unsigned x, unsigned y) {
  if (ind[index] == 0 || index >= maxStickers) {
    return false;
  }
  xco[index] = x;
  yco[index] = y;
  return true;
}
void StickerSheet::removeSticker(unsigned index) {
  if (ind[index] == 1 && index < maxStickers) {
    Image * newstickers = new Image[maxStickers];
    for (unsigned i = 0; i < maxStickers; i++) {
      if (i == index) {
        xco[index] = 0;
        yco[index] = 0;
        ind[index] = 0;
      } else {
        newstickers[i] = stickers[i];
      }
    }
    delete[] stickers;
    stickers = newstickers;
  }
}
Image * StickerSheet::getSticker(unsigned index) {
  if (ind[index] == 0 || index >= maxStickers) {
    return NULL;
  }
  return &stickers[index];
}
Image StickerSheet::render() const {
  unsigned int maxWidth = base.width();
  unsigned int maxHeight = base.height();
  Image render = base;
  for (unsigned i = 0; i < maxStickers; i++) {
    if (ind[i] == 1) {
      if (stickers[i].width() + xco[i] > maxWidth) {
        maxWidth = stickers[i].width() + xco[i];
      }
      if (stickers[i].height() + yco[i] > maxHeight) {
        maxHeight = stickers[i].height() + yco[i];
      }
    }
  }
  render.resize(maxWidth, maxHeight);
  for (unsigned i = 0; i < maxStickers; i++) {
    if (ind[i] == 1) {
      for (unsigned j = xco[i]; j < xco[i] + stickers[i].width(); j++) {
        for (unsigned k = yco[i]; k < yco[i] + stickers[i].height(); k++) {
          HSLAPixel & spixel = stickers[i].getPixel(j - xco[i], k - yco[i]);
          HSLAPixel & pixel = render.getPixel(j, k);
          if (spixel.a == 0) {
            continue;
          } else {
            pixel = spixel;
          }
        }
      }
    }
  }
  return render;
}
