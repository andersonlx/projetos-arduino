#include <RFremote.h>
SignalPatternParams params;

int frequencia = 2000; //Frequancia do Buzzer

const char *abrir = "11001011001001001001001001001011001011001011011001011011001011011001011"; //Abrir
const char *fechar = "11001011001001001001001001001011001011001011011001011011001011011011001"; //Fechar
const char *alarme = "11001011001001001001001001001011001011001011011001011011001011001011011"; // Alarme
const char *sigame = "11001011001001001001001001001011001011001011011001011011001001011011011"; // Siga-me

RFrecv rfrecv;

void setup()
{
  // Configura os pinos com os LEDs e Buzzer como saída
  pinMode(9, OUTPUT); // Luz Vermelha
  pinMode(10, OUTPUT); // Luz Verde
  pinMode(11, OUTPUT); // Buzzer
  pinMode(12, OUTPUT); // Luz Branca
  
  Serial.begin(9600);
  delay(500);
  Serial.println("Sistema de alarme iniciado!");

  // Parametros para localizar o serial do controle remoto
  params.spaceMin = 10300;
  params.spaceMax = 10500;
  params.dotMin = 200;
  params.dotMax = 400;
  params.traceMin = 900;
  params.traceMax = 1050;
  params.skipFirst = 1;
  params.skipLast = 1;

  rfrecv = RFrecv(&params);
  rfrecv.begin();
}

void loop()
{
  if (rfrecv.available()) {

    if (strncmp((char*)rfrecv.cmd, abrir, CMD_SIZE) == 0) {
      Serial.println("Luz verde acesa. | Alarme Desligado!");
      digitalWrite(11, LOW); // desliga buzzer
      digitalWrite(9, LOW); // apaga a luz vermelha
      digitalWrite(10, HIGH); // acende a luz verde

      for (int bip = 1; bip <= 1;) {
        tone(11, frequencia); // gera frequencia de 2000Hz no buzzer
        delay(200);
        noTone(11); // para a frequencia no buzzer
        delay(200);
        bip = bip + 1;
      } 
      digitalWrite(11, LOW); // desliga buzzer
    }
      
    else if (strncmp((char*)rfrecv.cmd, fechar, CMD_SIZE) == 0) {
      Serial.println("Luz vermelha acesa. | Alarme ligado!");
      digitalWrite(11, LOW); // desliga buzzer
      digitalWrite(9, HIGH); // acende a luz vermelha
      digitalWrite(10, LOW); // apaga a luz verde

      for (int bip = 1; bip <= 2;) {
        tone(11, frequencia); // gera frequencia de 2000Hz no buzzer
        delay(200);
        noTone(11); // para a frequencia no buzzer
        delay(200);
        bip = bip + 1;
      } 
      digitalWrite(11, LOW); // desliga buzzer
    }
   
    else if (strncmp((char*)rfrecv.cmd, sigame, CMD_SIZE) == 0) {
      Serial.println("Luz branca acesa. | Siga-me ativado por 10 segundos !");
      digitalWrite(11, LOW); // desliga buzzer
      digitalWrite(10, LOW); // desliga a luz verde
      digitalWrite(9, LOW); // desliga a luz vermelha
      digitalWrite(12, HIGH); // acende a luz branca
      
      delay(10000);
      digitalWrite(12, LOW); // apaga a luz branca
      digitalWrite(9, LOW); // desliga a luz vermelha
      digitalWrite(10, HIGH); // acende a luz verde
      Serial.println("Luz branca apagada. | Siga-me desativado!");
    } 
    
    else if (strncmp((char*)rfrecv.cmd, alarme, CMD_SIZE) == 0) {
      Serial.println("Alarme ativado. | Buzzer acionado luzes piscando!");

      for (int bip = 1; bip <= 10;) {
        tone(11, frequencia); // gera frequencia de 2000Hz no buzzer
        delay(200);
        noTone(11); // para a frequencia no buzzer
        delay(200);

        digitalWrite(10, HIGH); // acende luz verde
        digitalWrite(9, HIGH); // acende luz vermelha
        digitalWrite(12, HIGH); // acende luz branca
        delay(200);
        digitalWrite(10, LOW); // apaga luz verde
        digitalWrite(9, LOW); // apaga luz vermelha
        digitalWrite(12, LOW); // apaga luz bramca
        delay(200);
        
        bip = bip + 1;
      } 
      digitalWrite(11, LOW); // desliga buzzer
      
    } else {
      Serial.println("ERRO DE ACIONAMENTO, VERIFICAR LIGAÇÃO!");
    }
  }
}
