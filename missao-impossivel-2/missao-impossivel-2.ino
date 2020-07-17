// Declaração dos pinos dos componentes
const int pinoLDR = A0;
const int pinoBuzzer = 9;
const int pinoBotao = 8; 

// Variáveis gerais
int leituraLDR = 0;
int leituraBotao;

void setup() {
  // Configura os pinos
  pinMode(pinoLDR, INPUT);
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pinoBotao, INPUT_PULLUP);

  Serial.begin(9600); // 9600bps
}

void loop() {
  // le o valor de tensão no pino do LDR
  leituraLDR = analogRead(pinoLDR);
  // le o estado do botao
  leituraBotao = digitalRead(pinoBotao);

  Serial.print("Leitura: ");
  Serial.print(leituraLDR);
  Serial.print("\t");
  
  
  // Se existir um obstáculo
  //Serial.print("Invasão : ");
  
  if (leituraLDR <= 512) {
    Serial.print("Invasão Detectada!");
    tone(pinoBuzzer, 1000); // aciona o buzzer
    
  } else if (leituraBotao == LOW) { // senão e o botão estiver pressionado
    noTone(pinoBuzzer); // desliga o buzzer
    Serial.print("Acionamento de reset concluido!");
  } else {
    Serial.print("Área Segura!"); 
  }
  Serial.println();
  
  delay(100); // aguarda 100 milissegundos para uma nova leitura
  
}
