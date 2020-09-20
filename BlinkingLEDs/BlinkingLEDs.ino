void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  analogWrite(9, random(0 ,255));
  analogWrite(10, random(0 ,255));
  analogWrite(11, random(0, 255));
  
  int pin = random(3,6);
  int outputLevel = random(0,2);
  switch (outputLevel) {
    case 0:
      digitalWrite(pin, LOW);
      break;
    case 1:
      digitalWrite(pin, HIGH);
      break;
  }

  int potVal = analogRead(A0);
  int delayValue = map(potVal, 0, 1023, 10, 1000);
  delay(delayValue);
}
