#include <Arduino.h>
#include <FollowerRobot.h>

void setup()
{
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
}
void loop()
{
  
  
  if(!digitalRead(LS) && !digitalRead(RS))  
  {
       // FORWARD
    analogWrite(LM1, HIGH_SPEED_MOTOR);
    digitalWrite(LM2, LOW);
    analogWrite(RM1, HIGH_SPEED_MOTOR);
    digitalWrite(RM2, LOW);
  }
  
  if((digitalRead(LS)) && !digitalRead(RS))     
  {
      // Left turn
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    analogWrite(RM1, LOW_SPEED_MOTOR);
    digitalWrite(RM2, LOW);
  }
  
  if(!digitalRead(LS) && (digitalRead(RS)))     
  {
        // turn right
    analogWrite(LM1, LOW_SPEED_MOTOR);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }
  
  if((digitalRead(LS)) && (digitalRead(RS)))    
  {       //Stop
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }
}