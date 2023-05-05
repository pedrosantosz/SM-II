// INCOMPLETA E LOGICA ERRADA

#define DATA 5
#define CLOCK 7
#define LATCH 6

byte display[] = { B11101111, B11011111, B10111111, B01111111 };
byte vBuffer[] = { B11101110, B10111110, B11111100, B01111000 };
byte vNumeros[] = { B11111100, B01100000, B11011010, B11110010, B01100110, B10110110, B10111110, B11100000, B11111110, B11110110};


void setup() {
  pinMode(DATA, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);

  digitalWrite(CLOCK, LOW);
  digitalWrite(LATCH, LOW);

}

void loop() {
    exibeDecimal(1234);
    atualizaDisplayComDelay(1000);
}

void enviaPulso(int pino) {
  digitalWrite(pino, HIGH);
  digitalWrite(pino, LOW);
}

void atualizaDisplay() {
  for (int i = 0; i <=3; i++) {
      shiftOut(DATA, CLOCK, LSBFIRST, display[i]);
      shiftOut(DATA, CLOCK, LSBFIRST, vBuffer[i]);
      enviaPulso(LATCH);
  }
}

void limpaDisplay() {
  for (int i = 0; i <= 3; i++)
    vBuffer[i] = B00000000;
}

void exibeJoga() {
  vBuffer[0] = B11101110;
  vBuffer[1] = B10111110;
  vBuffer[2] = B11111100;
  vBuffer[3] = B01111000;
}

void atualizaDisplayComDelay(unsigned long duracao) {
  unsigned long tempoFinal;

  tempoFinal = millis() + duracao;
  while (millis() < tempoFinal)
    atualizaDisplay();
}

void exibeUnidade(byte valor) {
  int unidade = valor%10;
  vBuffer[0] = vNumeros[unidade];

  for(int i = 1; i <= 3; i++)
    vBuffer[i] = B00000000;
}

void exibeDecimal(byte valor) { //1234
  //unidade = valor % 10; // 1234 % 10 / 1 = 4
  //decimal = valor % 100 ) / 10; // 1234 % 100 / 10 ~= 3
  //centena = valor % 1000 / 100; // 1234 % 1000 / 100 ~= 2
  //milhar = valor % 10000 / 1000; // 1234 % 10000 / 1000 ~= 1 

  int x = 1;

  for (int i = 0; i <= 3; i++) {
    int resto = valor % (x * 10) / x;
    vBuffer[i] = vNumeros[resto];
    x = x * 10;
  }
}