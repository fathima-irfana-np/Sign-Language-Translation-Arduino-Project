#include <Arduino.h>
#include "Flex.h"

// Pin Definitions
#define FLEX_5V1_1_PIN_SIG	A0
#define FLEX_5V2_2_PIN_SIG	A1
#define FLEX_5V3_3_PIN_SIG	A2

// Global variables and defines
// object initialization
Flex flex_5v1_1(FLEX_5V1_1_PIN_SIG);
Flex flex_5v2_2(FLEX_5V2_2_PIN_SIG);
Flex flex_5v3_3(FLEX_5V3_3_PIN_SIG);

// define vars for testing menu
const int timeout = 10000;       //define timeout of 200 sec
char menuOption = 0;
long time0;
const float VCC = 5;			// voltage at Ardunio 5V line
const float R_DIV = 10000.0;	// resistor used to create a voltage divider
const float flatResistance = 25000.0;	// resistance when flat
const float bendResistance = 100000.0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup()
{
  // Setup Serial which is useful for debugging
  // Use the Serial Monitor to view printed messages
  Serial.begin(9600);
  pinMode(FLEX_5V1_1_PIN_SIG, INPUT);
  pinMode(FLEX_5V2_2_PIN_SIG, INPUT);
  pinMode(FLEX_5V3_3_PIN_SIG, INPUT);
  while (!Serial){
    // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    delay(2000);
  }
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{   
    // Flex Sensor 4.5'' #1 - Test Code
    // Read Flex sensor value.
  int flex_5v1_1Val = flex_5v1_1.read();
  Serial.print(F("flex_5v1_1Val: "));
  Serial.println(flex_5v1_1Val);
  int ADCflex = analogRead(FLEX_5V1_1_PIN_SIG);
  float Vflex = ADCflex * VCC / 1023.0;
  float Rflex = R_DIV * (VCC / Vflex - 1.0);
  Serial.println("Resistance: " + String(Rflex) + " ohms");

	// Use the calculated resistance to estimate the sensor's bend angle:
	float angle = map(Rflex, flatResistance, bendResistance, 0, 90.0);
	Serial.println("Bend: " + String(angle) + " degrees");
	Serial.println();
  delay(500);
    
   
    // Flex Sensor 4.5'' #2 - Test Code
    // Read Flex sensor value.
  int flex_5v2_2Val = flex_5v2_2.read();
  Serial.print(F("flex_5v2_2: ")); 
  Serial.println(flex_5v2_2Val);
  int ADflex = analogRead(FLEX_5V2_2_PIN_SIG);
	float Vlex = ADCflex * VCC / 1023.0;
	float Rlex = R_DIV * (VCC / Vflex - 1.0);
	Serial.println("Resistance: " + String(Rflex) + " ohms");

	// Use the calculated resistance to estimate the sensor's bend angle:
	float angle1 = map(Rflex, flatResistance, bendResistance, 0, 90.0);
	Serial.println("Bend: " + String(angle) + " degrees");
	Serial.println();
  delay(500);
    
    
    // Flex Sensor 4.5'' #3 - Test Code
    // Read Flex sensor value.
  int flex_5v3_3Val = flex_5v3_3.read();
  Serial.print(F("flex_5v3_3: ")); 
  Serial.println(flex_5v3_3Val);
  int ACflex = analogRead(FLEX_5V3_3_PIN_SIG);
	float Vflex = ADCflex * VCC / 1023.0;
	float Rflex = R_DIV * (VCC / Vflex - 1.0);
	Serial.println("Resistance: " + String(Rflex) + " ohms");

	// Use the calculated resistance to estimate the sensor's bend angle:
	float angle2 = map(Rflex, flatResistance, bendResistance, 0, 90.0);
	Serial.println("Bend: " + String(angle) + " degrees");
	Serial.println();
  delay(500);
  
  if (millis() - time0 > timeout)
  {
    time0 = millis();
    return;
  }  
}