int frequencia = 20;

void setup() {
  pinMode(10, OUTPUT); // configura o pino co o buzzer como saida

}

void loop() {
  tone(10, frequencia); // gera frequencia de 2000Hz no buzzer
  delay(1000);
  noTone(10); // para a frequencia no buzzer
  delay(1000);

}
