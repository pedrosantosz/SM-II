#define DATA 2
#define CLOCK 4
#define LATCH 3

int posicao = 8;

void setup() {
  pinMode (DATA, OUTPUT);
  pinMode (CLOCK, OUTPUT);
  pinMode (LATCH, OUTPUT);
  digitalWrite (DATA, LOW);
  digitalWrite (CLOCK, LOW);
  digitalWrite (LATCH, LOW);
  desligaLeds ();
}

void loop() {
  if (posicao == 0)
    posicao = 8;

  for(int i = 1; i <= posicao; i++) {
    if (i == 1)
      digitalWrite(DATA, 1);
    else
      digitalWrite(DATA, 0);

    pulso(CLOCK);
  }
  
  pulso(LATCH);
  delay(250);
  posicao--;

  desligaLeds();
}

void desligaLeds() {
  digitalWrite (DATA, LOW);
  for (int i=0; i<8; i++){
    pulso (CLOCK);
  }
    pulso (LATCH);
}

void pulso (int pino){
  digitalWrite (pino, HIGH);
  digitalWrite (pino, LOW);
}
