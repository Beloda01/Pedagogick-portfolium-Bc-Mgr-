// test všech senzorů + serva, motory stojí
// analog vstup A0-A3 => monitor
// vzdálenost 12->Trig 13->Echo => monitor
// motory 5/7 6/8 PWM/směr
// servo 9

#include <Servo.h>

Servo myservo;

int pTrig = 12;
int pEcho = 13;
int pServo = 9;
long odezva, vzdalenost;
int mLs = 7; //směr levý
int mLp = 5; //výkon levý
int mRs = 8; //směr pravý
int mRp = 6; //výkon pravý

void setup() {
  // dálkoměr
  pinMode(pTrig, OUTPUT);
  pinMode(pEcho, INPUT);
  // motory
  pinMode(mLs, OUTPUT);
  pinMode(mLp, OUTPUT);
  pinMode(mRs, OUTPUT);
  pinMode(mRp, OUTPUT);
  // připojení serva
  myservo.attach(pServo);
  // sériový monitor
  Serial.begin(9600);
  //zastavení motorů  
  digitalWrite(mLs, LOW);
  analogWrite(mLp, 0);
  digitalWrite(mRs, LOW);
  analogWrite(mRp, 0);
}

void loop() {
  // načtení vzdálenosti
  
  digitalWrite(pTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pTrig, HIGH);
  delayMicroseconds(5);
  digitalWrite(pTrig, LOW);
  odezva = pulseIn(pEcho, HIGH, 5000);  // maximální délku pulzu v mikrosekundách (us)
  vzdalenost = int(odezva / 58.31);    // přepočet na cm
  
  // otočení serva podle vzdálenosti
  if (vzdalenost <= 18)
    myservo.write(vzdalenost*10);
    
  // načtení hodnot ze světelných čidel
  for (int i = 0; i < 4; i++) {
    Serial.print(analogRead(A0 + i));
    Serial.print(" - ");
    delay(2);
  };

  Serial.print(vzdalenost);
  Serial.println(" cm");
  delay(200);
}
