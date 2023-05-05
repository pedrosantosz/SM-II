#define DATA 2
#define LATCH 3
#define CLOCK 4

int estado = 1;

void setup(){
  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  
  digitalWrite(CLOCK, 0); // (estado
  digitalWrite(LATCH, 0); //  inicial)

  desligaLeds();
}

void loop(){
  digitalWrite(DATA, estado);
  
  // Dá 8 pulsos ligando ou desligando 1 led de cada vez
  // em um intervalo de 250ms entre cada um.
  // O código repete mas o estado começa a inverter depois
  // do laço for
  
  for (int i=1; i<=8; i++) {
    pulso(CLOCK);
    pulso(LATCH);
    delay(250);
  }
  
 estado =  !estado;
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
