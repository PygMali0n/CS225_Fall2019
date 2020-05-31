#include "Image.h"
#include "StickerSheet.h"

int main() {

  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //
  Image base;
  base.readFromFile("meme.png");
  Image c;
  c.readFromFile("c.png");
  c.scale(0.25);
  Image c_;
  c_.readFromFile("c++.png");
  c_.scale(0.18);
  Image seg;
  seg.readFromFile("seg.png");
  seg.scale(0.35);

  StickerSheet sheet(base, 3);
  sheet.addSticker(c, 20, 20);
  sheet.addSticker(c_, 25, 280);
  sheet.addSticker(seg, 30, 550);
  Image out = sheet.render();
  out.writeToFile("output.png");

  return 0;
}
