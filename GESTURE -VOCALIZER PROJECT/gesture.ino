#include <AnalogReader.h>
#include <BTHC05.h>
#include <Flex.h>

int flexPin1 = A2;
int flexPin2 = A3;
int flexPin3 = A4;
int value1; 
int value2;
int value3;
int val1; 
int val2;
int val3;

void setup()
{
  Serial.begin(9600);
  pinMode(flexPin1,INPUT);
  pinMode(flexPin2,INPUT);
  pinMode(flexPin3,INPUT);
}

void loop()
{
  val1 = analogRead(flexPin1);
  val2 = analogRead(flexPin2);  
  val3 = analogRead(flexPin3);  
  
  Serial.print("value1:");
  Serial.println(value1);
  Serial.print("value2:");
  Serial.println(value2);
  Serial.print("value3:");
  Serial.println(value3);
  
  delay(1500);
}   
