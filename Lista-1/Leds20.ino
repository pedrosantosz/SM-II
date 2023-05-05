#define DATA 2
#define LATCH 3
#define CLOCK 4

void setup(){
  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);

  digitalWrite(CLOCK, 0); // (estado
  digitalWrite(LATCH, 0); //  inicial)

  desligaLeds();

  for (int i = 10; i <= 20; i++) {
    desligaLeds();
    exibeBitLSB(i);
    delay(500);
  }
}

void loop(){

}

void pulso(int pino){
  digitalWrite(pino, 1);
  digitalWrite(pino, 0);
}

void desligaLeds() {
  shiftOut(DATA, CLOCK, LSBFIRST, B00000000);
  pulso(LATCH);
}

void exibeBitLSB(byte n) {
  if (bitRead(n, 0) == 0) {
    shiftOut(DATA, CLOCK, LSBFIRST, B00000000);
    pulso(LATCH);
  } else {
    shiftOut(DATA, CLOCK, LSBFIRST, B10000000);
    pulso(LATCH);
  }
}