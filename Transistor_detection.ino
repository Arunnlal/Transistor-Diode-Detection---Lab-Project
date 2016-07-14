int pinD1Source = 7;
int pinD2Source = 8;
int pinD1Probe = A0;
int pinD2Probe = A1;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  pinMode(pinD1Source, OUTPUT);
  pinMode(pinD2Source, OUTPUT);
  pinMode(pinD1Probe, INPUT);
  pinMode(pinD2Probe, INPUT);
  Serial.begin(9600);

}

int value1;
int value2;
int value3;
int value4;


// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(pinD1Source, HIGH);
  digitalWrite(pinD2Source, LOW);
  delay(100);
  value1 = analogRead(pinD1Probe);
  value2 = analogRead(pinD2Probe);

  digitalWrite(pinD1Source, LOW);
  digitalWrite(pinD2Source, HIGH);
  //digitalWrite(pinD3Source, HIGH);
  delay(100);
  value3 = analogRead(pinD1Probe);
  value4 = analogRead(pinD2Probe);


  Serial.print(value1); Serial.print(" ");
  Serial.print(value2); Serial.print(" ");
  Serial.print(value3); Serial.print(" ");
  Serial.print(value4); Serial.print(" ");
  Serial.println();

  if (value1 > value2 && value3 < value4)
  {
    Serial.println("The Transistor is PNP");
   }
   else if (value1 < value2 && value3 < value4)
  {
    Serial.println("The Transistor is NPN");
   }
   else 
   {Serial.println(" NO Transistor Detected");
   }
}
