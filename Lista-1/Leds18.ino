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
  
  shiftOut(DATA, CLOCK, MSBFIRST, 240);
  pulso(LATCH);
  
}

void loop(){
  
}

void pulso(int pino){
  digitalWrite(pino, 1);
  digitalWrite(pino, 0);
}

void desligaLeds() {
  digitalWrite(DATA, 0);
  for(int i = 1; i <= 8; i++){
    pulso(CLOCK);
  }
  pulso(LATCH);
}