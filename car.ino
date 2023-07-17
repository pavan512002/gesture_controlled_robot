#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2 , 3) ; // RX | TX
int c = 0;

void setup() 
{
  pinMode(8, OUTPUT); //R+
  pinMode(9, OUTPUT); //R-
  pinMode(10, OUTPUT); //L+
  pinMode(11, OUTPUT); //L-
  
  Serial.begin(9600) ;
  Serial.println(" Arduino with HC -05 is ready to recieve ");

  BTSerial.begin(38400);
  Serial.print(" BTserial started at 38400 ");
  pinMode( LED_BUILTIN , OUTPUT ); //pin 13
}

void moveRobot(String motion)
{
  if(motion=="Forward")
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  }
  if(motion=="Left")
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
  }
  if(motion=="Right")
  {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  }
  if(motion=="Backward")
  {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
  }
  if(motion=="stop")
  {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
}

void loop ()
{
  // Keep reading from HC -06 and send to Arduino Serial Monitor
  if (BTSerial.available())
  {
    c = BTSerial.read() ;
    Serial.println(c);
    switch (c)
    {
      case '1':
      moveRobot("Forward"); break;
      case '2':
      moveRobot("Backward"); break; 
      case '3':
      moveRobot("Left"); break;
      case '4':
      moveRobot("Right"); break;
      case '5':
      moveRobot("stop"); break;
      default :
      moveRobot("stop");
    }
  }
}
