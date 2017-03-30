#include <Gamebuino-Meta.h>


Image image = Image(16, 16, ColorMode::rgb565);
Image imageIndex = Image(16, 16, ColorMode::index);

void setup() {
  gb.begin();
  SerialUSB.begin(9600);
  //while (!SerialUSB);

  Gamebuino_Meta::Gamebuino_SD_GFX::debugOutput = &gb.tft;
  

  Gamebuino_Meta::Gamebuino_SD_GFX::readImage(image, "RGB888.BMP");
  SerialUSB.println(image._width);
  SerialUSB.println(image._height);
  for (int i = 0; i < (image._width * image._height); i++) {
    SerialUSB.print(image._buffer[i], HEX);
  }
  gb.tft.drawImage(120, 8, image, 32, 32);

  Gamebuino_Meta::Gamebuino_SD_GFX::writeImage(image, "WRITE888.BMP");

  delay(3000);
  gb.tft.setColor(BLACK);
  gb.tft.fillScreen();
  gb.tft.setColor(WHITE, BLACK);
  gb.tft.setCursor(0,0);

  //INDEX4 BITMAP

  Gamebuino_Meta::Gamebuino_SD_GFX::readImage(imageIndex, "INDEX4.BMP");
  SerialUSB.println(imageIndex._width);
  SerialUSB.println(imageIndex._height);
  gb.tft.drawImage(120, 8, imageIndex);

  Gamebuino_Meta::Gamebuino_SD_GFX::writeImage(imageIndex, "WRITE4.BMP");
  
}

void loop() {
  SerialUSB.println("Waiting...");
  delay(1000);
}