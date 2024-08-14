const int flexPin1 = A2;			// Pin connected to voltage divider output
const int flexPin2 = A3;
const int flexPin3 = A4;

// Change these constants according to your project's design
const float VCC = 5;			// voltage at Ardunio 5V line
const float R_DIV = 47000.0;	// resistor used to create a voltage divider
const float flatResistance = 22000.0;	// resistance when flat
const float bendResistance = 700000.0;	// resistance at 90 deg

void setup() {
	Serial.begin(9600);
	pinMode(flexPin1, INPUT);
  pinMode(flexPin2, INPUT);
  pinMode(flexPin3, INPUT);
}

void loop() {
	// Read the ADC, and calculate voltage and resistance from it
	int ADCflex1 = analogRead(flexPin1);
	float Vflex1 = ADCflex1 * VCC / 1023.0;
	float Rflex1 = R_DIV * (VCC / Vflex1 - 1.0);
	Serial.println("Resistance1: " + String(Rflex1) + " ohms");
  float angle1 = map(Rflex1, flatResistance, bendResistance, 0, 90.0);
	Serial.println("Bend1: " + String(angle1) + " degrees");
	Serial.println();

  int ADCflex2 = analogRead(flexPin2);
	float Vflex2 = ADCflex2 * VCC / 1023.0;
	float Rflex2 = R_DIV * (VCC / Vflex2 - 1.0);
	Serial.println("Resistance2: " + String(Rflex2) + " ohms");
  float angle2 = map(Rflex2, flatResistance, bendResistance, 0, 90.0);
	Serial.println("Bend2: " + String(angle2) + " degrees");
	Serial.println();
  

	delay(500);
}