#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

void setup()
{
  Serial.begin(38400);
  mySerial.begin(38400);

  Serial.println("Arduino Sender");
}

void loop()
{
  if (Serial.available())
  {
    char sendChar = Serial.read();        // Read the character from Serial monitor
    mySerial.write(sendChar);             // Send the character to the receiver Arduino
  }
  if(mySerial.available())
  {
    char receivedChar = mySerial.read();
    Serial.write(receivedChar);
  }
  
}
