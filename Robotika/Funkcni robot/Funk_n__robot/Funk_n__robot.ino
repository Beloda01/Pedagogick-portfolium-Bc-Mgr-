#include <Servo.h>

int pTrig = 12;
int pEcho = 13;
long odezva, vzdalenost;
int mLs = 7;
int mLp = 5;
int mRs = 8;
int mRp = 6;

Servo myServo; // definujeme servo

void setup() {
  pinMode(pTrig, OUTPUT);
  pinMode(pEcho, INPUT);
  pinMode(mLs, OUTPUT);
  pinMode(mLp, OUTPUT);
  pinMode(mRs, OUTPUT);
  pinMode(mRp, OUTPUT);
  Serial.begin(9600);
  myServo.attach(9); // připojíme servo na pin 9
  myServo.write(0); // Natočit servo doprostřed
}

void loop() {
  digitalWrite(pTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pTrig, LOW);
  
  if (vzdalenost <= 15) { // pokud vzdálenost menší nebo rovna 15 cm
    Serial.println("Otoč se");
    digitalWrite(mLs, LOW);
    analogWrite(mLp, 255);
    digitalWrite(mRs, HIGH);
    analogWrite(mRp, 0); // pravy motor zastavit
    delay(900);
  
    while ((100.0 * (analogRead(A2) - 204.0) / (731.0 - 204.0)) < 50) { // jet po černé čáře zpět
      digitalWrite(mLs, LOW);
      analogWrite(mLp, 0);
      digitalWrite(mRs, LOW);
      analogWrite(mRp, 200);
    }
  
  } 
  else { // jinak pojedeme po cerné čáře
    while ((100.0 * (analogRead(A1) - 106.0) / (678.0 - 106.0)) < 50) {
      digitalWrite(mLs, LOW);
      analogWrite(mLp, 200);
      digitalWrite(mRs, LOW);
      analogWrite(mRp, 0);
    }

    while ((100.0 * (analogRead(A2) - 204.0) / (731.0 - 204.0)) < 50) {
      digitalWrite(mLs, LOW);
      analogWrite(mLp, 0);
      digitalWrite(mRs, LOW);
      analogWrite(mRp, 200);
    }
  }
}
  
