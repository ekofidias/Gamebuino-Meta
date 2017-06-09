#include <Gamebuino-Meta.h>


Image image = Image(16, 16, "RGB888.BMP");
Image imageIndex = Image(16, 16, "INDEX4.BMP");

void setup() {
	gb.begin();
	SerialUSB.begin(9600);
	//while (!SerialUSB);

	
	SerialUSB.println(image._width);
	SerialUSB.println(image._height);
	for (int i = 0; i < (image._width * image._height); i++) {
		SerialUSB.print(image._buffer[i], HEX);
	}
	gb.tft.drawImage(120, 8, image, 32, 32);

	if (!image.save("WRITE888.BMP")) {
		gb.tft.println("Couldn't write image WRITE888.BMP!");
		while(1);
	}

	delay(3000);
	gb.tft.setColor(BLACK);
	gb.tft.fillScreen();
	gb.tft.setColor(WHITE, BLACK);
	gb.tft.setCursor(0,0);

	//INDEX4 BITMAP

	SerialUSB.println(imageIndex._width);
	SerialUSB.println(imageIndex._height);
	gb.tft.drawImage(120, 8, imageIndex, 32, 32);

	if (!imageIndex.save("WRITE4.BMP")) {
			gb.tft.println("Couldn't write image WRITE4.BMP!");
			while(1);
	}
	
	//delay(3000);
	/*
	gb.tft.setColor(BLACK);
	gb.tft.fillScreen();
	gb.tft.setColor(WHITE, BLACK);
	gb.tft.setCursor(0,0);
	for (int i = 0; i < ((imageIndex._width + 1) * imageIndex._height / 2); i++) {
		if(!(i%((imageIndex._width + 1)/2))){
			gb.tft.print("\n");
		}
		gb.tft.print((((uint8_t*)imageIndex._buffer)[i]>>4)&0x0F, HEX);
		gb.tft.print((((uint8_t*)imageIndex._buffer)[i])&0x0F, HEX);
	}
	*/
}

void loop() {
	
}