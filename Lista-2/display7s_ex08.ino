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
}

void loop() {
  int c = 0;
  for (int i=3; i>=0; i--) {
      shiftOut(DATA, CLOCK, LSBFIRST, display[i]);
      shiftOut(DATA, CLOCK, LSBFIRST, vbuffer[c]);
      enviaPulso(LATCH);
      c++;
  }
}

void enviaPulso(int pino) {
  digitalWrite(pino, HIGH);
  digitalWrite(pino, LOW);
}