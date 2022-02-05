#include <Arduino.h>

const int ledR = 11;
const int ledB = 10;
const int ledG = 9;
const int TEMPO_MOD_VALORES = 1;
const int TEMPO_LED_ON = 1000 - TEMPO_MOD_VALORES;

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledG, OUTPUT);
}

struct Leds {
  int led, valor;

  void acessoLeds() {
    analogWrite(led, valor);
  }
};

void aleatorio(Leds *R, Leds *G, Leds *B) {
  static int contador = 0;
  while (contador < 20){
    static unsigned long tempoCorrente = millis();
    if ((millis() - tempoCorrente) < TEMPO_MOD_VALORES){
      R->led = ledR;
      G->led = ledB;
      B->led = ledG;
      R->valor = random(0, 255);
      G->valor = random(0, 255);
      B->valor = random(0, 255);
    }
    if ((millis() - tempoCorrente) > TEMPO_LED_ON) {
      tempoCorrente = millis();
      contador++;
    }
    R->acessoLeds();
    G->acessoLeds();
    B->acessoLeds();
  }
}

void full(Leds *R, Leds *G, Leds *B) {
  static int contador = 0;
  while (contador < 20) {
    static unsigned long tempoCorrente = millis();
    if ((millis() - tempoCorrente) < TEMPO_MOD_VALORES){
      R->led = ledR;
      G->led = ledB;
      B->led = ledG;
      R->valor = 255;
      G->valor = 255;
      B->valor = 255;
    }
    if ((millis() - tempoCorrente) > TEMPO_LED_ON) {
      tempoCorrente = millis();
      contador++;
    }
    R->acessoLeds();
    G->acessoLeds();
    B->acessoLeds();
  }
  
}

Leds R;
Leds G;
Leds B;

void loop() {
 
  aleatorio(&R, &G, &B);
}