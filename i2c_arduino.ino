// Arduino slave for RPi Master
// Connects to RPi via I2C

// include the wire library for I2C (for Arduino; built in)

#include<Wire.h>

// led light is on pin 13
const int led = 13;

void setup() {

  // Join I2C bus as slave with address 8
  // tells wire library we will be operating the arduino as a slave, not master 
  Wire.begin(0x8);

  // every time data is received, we call receiveEvent
  // so we wait for data all the time
  Wire.onReceive(receiveEvent);

  // set up led light as output and turn led off
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

}

void receiveEvent(int amount)  // amount of events
{
  while(Wire.available())
  {
    char x = Wire.read();      // read the wire
    digitalWrite(led, x);      // and write the value to the led (0 or 1) that will toggle light
  }
}

void loop() {
  
  delay(100);

}
