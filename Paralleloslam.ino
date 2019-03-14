// Paralelloslam
// Programming & Hardware By Cosmos2000 & TK
// Inspired by sentryGun53
// Started 10-02-2019
// Last Modified 26-02-2019
// Version 1.0

#define pwrled A2
// parallel port pin# = arduino pin#
const int nStrobe = 2;
const int data_0 = 3;
const int data_1 = 4;
const int data_2 = 5;
const int data_3 = 6;
const int data_4 = 7;
const int data_5 = 8;
const int data_6 = 9;
const int data_7 = 10;
const int nAck = 11;
const int busy = 12;
const int cts = 13;

const int strobeWait = 2;   // microseconds to strobe for
byte serialinByte;

void setup() {
  Serial.begin(9600);
  pinMode(nStrobe, OUTPUT);      // is active LOW
  digitalWrite(nStrobe, HIGH);   // set HIGH
  pinMode(data_0, OUTPUT);
  pinMode(data_1, OUTPUT);
  pinMode(data_2, OUTPUT);
  pinMode(data_3, OUTPUT);
  pinMode(data_4, OUTPUT);
  pinMode(data_5, OUTPUT);
  pinMode(data_6, OUTPUT);
  pinMode(data_7, OUTPUT);
  pinMode(nAck, INPUT);     // is active LOW
  pinMode(busy, INPUT);
  pinMode(cts, OUTPUT);
  pinMode(pwrled, OUTPUT);
  delay(1000);
  digitalWrite(pwrled, HIGH);
//  resetPrinter(); // Resets printer to Emphasized mode, FORGET THIS!!
}

void loop() {
  if (Serial.available()) {
    if(digitalRead(busy) == LOW){
      serialinByte = Serial.read();
      printByte(serialinByte);
    }
  }
  if(digitalRead(busy) == HIGH){
    digitalWrite(cts, HIGH);
  } else {
    digitalWrite(cts, LOW);
  }
}

void printByte(byte inByte) {
  digitalWrite(data_0, inByte & 0x01);
  digitalWrite(data_1, inByte & 0x02);
  digitalWrite(data_2, inByte & 0x04);
  digitalWrite(data_3, inByte & 0x08);
  digitalWrite(data_4, inByte & 0x10);
  digitalWrite(data_5, inByte & 0x20);
  digitalWrite(data_6, inByte & 0x40);
  digitalWrite(data_7, inByte & 0x80);
  digitalWrite(nStrobe, LOW);       // strobe nStrobe to input data bits
  delayMicroseconds(strobeWait);
  digitalWrite(nStrobe, HIGH);
}

void resetPrinter() {
  printByte(27); // reset printer to emphasized mode.
  printByte('E'); // 27 is Escape & E= Dec 69 for Emphasized mode.
}
