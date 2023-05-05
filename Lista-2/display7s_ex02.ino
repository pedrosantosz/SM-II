#define DATA 5
#define CLOCK 7
#define LATCH 6

void setup() {
  pinMode(DATA, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);

  digitalWrite(CLOCK, LOW);
  digitalWrite(LATCH, LOW);

  shiftOut(DATA, CLOCK, LSBFIRST, B11011111);
  shiftOut(DATA, CLOCK, LSBFIRST, B10111110);
  enviaPulso(LATCH);
}

void loop() {
}

void enviaPulso(int pino) {
  digitalWrite(pino, HIGH);
  digitalWrite(pino, LOW);
}