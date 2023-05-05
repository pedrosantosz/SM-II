#define DATA 2
#define LATCH 3
#define CLOCK 4

int vetor[] = {1,1,1,1,0,0,0,0};

void setup(){
  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  
  digitalWrite(CLOCK, 0); // (estado
  digitalWrite(LATCH, 0); //  inicial)
  
  desligaLeds();
  
  for(int i = 0; i <= 7; i++){
    digitalWrite(DATA, vetor[i]);
    pulso(CLOCK);
    pulso(LATCH);
  }
  
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