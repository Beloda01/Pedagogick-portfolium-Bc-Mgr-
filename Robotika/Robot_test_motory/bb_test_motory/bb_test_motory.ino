// test zapojení motorů - VPŘED -> STOP -> VZAD -> STOP
// analog vstup A0-A3 => monitor
// vzdálenost 12->Trig 13->Echo => monitor
// motory 5/7 6/8 PWM/směr

int pTrig = 12;
int pEcho = 13;
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
  // sériový monitor
  Serial.begin(9600);
}

void loop() {
  Serial.println("Vpřed");
  digitalWrite(mLs, LOW);
  analogWrite(mLp, 255);
  digitalWrite(mRs, LOW);
  analogWrite(mRp, 255);
  delay(2000);
  Serial.println("Stop");
  digitalWrite(mLs, LOW);
  analogWrite(mLp, 0);
  digitalWrite(mRs, LOW);
  analogWrite(mRp, 0);
  delay(2000);
  Serial.println("Vzad");
  digitalWrite(mLs, HIGH);
  analogWrite(mLp, 0);
  digitalWrite(mRs, HIGH);
  analogWrite(mRp, 0);
  delay(2000);
  Serial.println("Stop");
  digitalWrite(mLs, LOW);
  analogWrite(mLp, 0);
  digitalWrite(mRs, LOW);
  analogWrite(mRp, 0);
  delay(2000);
}
