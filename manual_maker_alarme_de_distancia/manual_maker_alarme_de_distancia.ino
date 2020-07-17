/*
  Este programa faz com o Arduino meça a distância
  em cm, e para cada distância diferente ative
  LEDs indicativos de zona de alerta
*/

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(0, OUTPUT);
  Serial.begin(9600);

  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
  tone(0, 523, 1000); // play tone 60 (C5 = 523 Hz)
  Serial.println(0.01723 * readUltrasonicDistance(5, 4));
  if (0.01723 * readUltrasonicDistance(5, 4) < 70) {
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
  } else {
    if (0.01723 * readUltrasonicDistance(5, 4) < 150) {
      digitalWrite(10, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(8, LOW);
    } else {
      digitalWrite(10, LOW);
      digitalWrite(9, LOW);
      digitalWrite(8, HIGH);
    }
  }
  delay(10); // Delay a little bit to improve simulation performance
}