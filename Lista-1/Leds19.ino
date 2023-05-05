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
}

void loop(){
  
}

void pulso(int pino){
  digitalWrite(pino, 1);
  digitalWrite(pino, 0);
}

void desligaLeds() {
  shiftOut(DATA, CLOCK, MSBFIRST, 0);
  pulso(LATCH); // <--- importantíssimo
}