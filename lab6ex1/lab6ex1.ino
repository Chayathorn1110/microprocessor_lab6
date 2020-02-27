#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const int buttonPin1 = 2;
const int buttonPin2 = 3;
int button1 = 0;
int button2 = 0;
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
void setup() {
  Serial.begin(9600);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c); //initialize I2C addr 0x3c

 
}

void loop() {
  button1 = digitalRead(buttonPin1);
  button2 = digitalRead(buttonPin2);
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("SW1");
  display.drawCircle(90, 10, 9, WHITE); //x,y,radius,color
  display.println("SW2");
  display.drawCircle(90, 34, 9, WHITE); //x,y,radius,color
  
 if (button1 == 0)
 {
  display.fillCircle(90, 10, 9, WHITE);

 }
 
 if (button2 == 0)
 {
  display.fillCircle(90, 34, 9, WHITE);
 }
  display.display();
}
