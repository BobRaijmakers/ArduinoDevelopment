#include <SoftwareSerial.h>

SoftwareSerial mySerial(6,7);

char data;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }
  
  // put your setup code here, to run once:  
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  mySerial.begin(9600);
  data = '0';
}

void loop() {
  Serial.print("Loop data: ");
  Serial.print(data);
  if(data == '0') {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    analogWrite(9, 0);
    analogWrite(10, 0);
    analogWrite(11, 0);
  } else if(data == '1') {
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    analogWrite(9, random(0 ,255));
    analogWrite(10, random(0 ,255));
    analogWrite(11, random(0, 255));
    delay(1000);
  }
  if(mySerial.available() > 0) {
    Serial.print("Serial data: ");
    data = mySerial.read();
  }
  Serial.println("End loop");
}
