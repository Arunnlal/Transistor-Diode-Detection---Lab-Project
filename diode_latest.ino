

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
  delay(100);
  value3 = analogRead(pinD1Probe);
  value4 = analogRead(pinD2Probe);

  Serial.print(value1); Serial.print(" ");
  Serial.print(value2); Serial.print(" ");
  Serial.print(value3); Serial.print(" ");
  Serial.print(value4); Serial.print(" ");
  Serial.println();

  if (value1 <= 700 && value2 <= 500)
  {
    if (value1 > value2)
    {
      if (value3 <= 10 && value4 <= 1030)
      {
        if (value3 < value4)
        {
          Serial.println("The diode is forward biased");
        }
      }
    }
  }

 else if (value1 <= 1030 && value2 <= 10)
  {
    if (value1 > value2)
    {
      if (value3 <= 500 && value4 <= 700)
      {
        if (value3 < value4)
        {
          Serial.println("The diode is reverse biased");
        }
      }
    }
  }

  if (value1 <= 1030 && value2 <= 10)
  {
    if (value1 > value2)
    {
      if (value3 <= 10 && value4 <= 1030)
      {
       if (value3 < value4)
        {
          Serial.println("No diode is connected");
        }
      }
    }
  }

}
