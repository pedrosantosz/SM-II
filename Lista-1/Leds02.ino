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
  
  digitalWrite(DATA, 1);
  
  for(int i = 1; i <= 4; i++){
    digitalWrite(CLOCK, 1);
  	digitalWrite(CLOCK, 0);
  }
  
  digitalWrite(LATCH, 1);
}

void loop(){
  
}

void desligaLeds() {
  digitalWrite(DATA, 0);
  for (int i = 1; i <= 8; i++) {
    digitalWrite(CLOCK, 1);
    digitalWrite(CLOCK, 0);
  }
  digitalWrite(LATCH, 1);
  digitalWrite(LATCH, 0);
}
