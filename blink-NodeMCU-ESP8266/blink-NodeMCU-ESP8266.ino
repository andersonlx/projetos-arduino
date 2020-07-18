const int pino_led = D7; // pino onde o LED está conectado

void setup() {
  // configura o pino com o LED como saída
  pinMode(pino_led, OUTPUT); // pino 13
}

void loop() {
  digitalWrite(pino_led, HIGH); // acende o LED
  delay(500); // aguarda 1 segundo
  digitalWrite(pino_led, LOW); // apaga o LED
  delay(500); // aguarda 1 segundo
}
