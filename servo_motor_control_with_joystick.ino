#include <Servo.h> 
Servo servo;   
int servoposition;
int VRX = A1;  
void setup()
{
Serial.begin(9600);
servo.attach(3);
}
 
void loop()
{ 
int VRXvalues = analogRead(VRX); 
Serial.print("VRX values= ");
Serial.print(VRXvalues);
Serial.println();
  if ((VRXvalues >= 0) && (VRXvalues <= 545))
   {  
servoposition = map(VRXvalues, 0, 545, 0,90); 
  servo.write(servoposition);
  delay(10);
  }
  else if ((VRXvalues>545) && (VRXvalues <= 560))
  {
   servo.write(90);
   delay(10);
  }
   else if ((VRXvalues > 560) && (VRXvalues <= 1023))
   { 
 servoposition= map(VRXvalues, 560, 1023, 90, 180);   
  servo.write(servoposition);
  delay(10);
  } 
}
