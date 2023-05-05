#define DATA 5
#define CLOCK 7
#define LATCH 6

byte display[] = { B11101111, B11011111, B10111111, B01111111 };
byte vbuffer[] = { B11101110, B10111110, B11111100, B01111000 };


void setup() {
  pinMode(DATA, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);

  digitalWrite(CLOCK, LOW);
  digitalWrite(LATCH, LOW);

  limpaDisplay();
}

void loop() {
  atualizaDisplay();
}

void enviaPulso(int pino) {
  digitalWrite(pino, HIGH);
  digitalWrite(pino, LOW);
}

void atualizaDisplay() {
  for (int i = 0; i <=3; i++) {
      shiftOut(DATA, CLOCK, LSBFIRST, display[i]);
      shiftOut(DATA, CLOCK, LSBFIRST, vbuffer[i]);
      enviaPulso(LATCH);
  }
}

void limpaDisplay() {
  for (int i = 0; i <= 3; i++)
    vbuffer[i] = B00000000;
}