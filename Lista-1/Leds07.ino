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
  digitalWrite(DATA, 1);
  pulso(CLOCK);
  pulso(LATCH);
  delay(1000);
  
  digitalWrite(DATA, 0);
  pulso(CLOCK);
  pulso(LATCH);
  delay(1000);
}

void desligaLeds() {
  digitalWrite(DATA, 0);
  for (int i = 1; i <= 8; i++) {
    pulso(CLOCK);
  }
  pulso(LATCH);
}

void pulso(int pino){
  digitalWrite(pino, 1);
  digitalWrite(pino, 0);
}
