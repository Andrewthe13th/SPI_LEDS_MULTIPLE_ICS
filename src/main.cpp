#include <Arduino.h>

#define SS 10
#define MOSI 11
#define MISO 12
#define SCK 13

void setup() {
  // put your setup code here, to run once:
  pinMode(SS,OUTPUT);
  pinMode(MOSI,OUTPUT);
  pinMode(SCK,OUTPUT);
  //SPCR=0b01010010; // config
  SPCR=0b01110010; // LSB MODE, easier base
  SPSR |= (0b00000001); // set SPI2x bit
  pinMode(SS,HIGH);
}

void loop() {
  digitalWrite(SS,LOW);
  SPDR = 0b10001000;
  while(!(SPSR & (1 << SPIF))){};
  SPDR = 0b10001000;
  while(!(SPSR & (1 << SPIF))){};
  digitalWrite(SS,HIGH);
  delay(500);

  digitalWrite(SS,LOW);
  SPDR = 0b01000100;
  while(!(SPSR & (1 << SPIF))){};
  SPDR = 0b01000100;
  while(!(SPSR & (1 << SPIF))){};
  digitalWrite(SS,HIGH);
  delay(500);

  digitalWrite(SS,LOW);
  SPDR = 0b00100010;
  while(!(SPSR & (1 << SPIF))){};
  SPDR = 0b00100010;
  while(!(SPSR & (1 << SPIF))){};
  digitalWrite(SS,HIGH);
  delay(500);

  digitalWrite(SS,LOW);
  SPDR = 0b00010001;
  while(!(SPSR & (1 << SPIF))){};
  SPDR = 0b00010001;
  while(!(SPSR & (1 << SPIF))){};
  digitalWrite(SS,HIGH);
  delay(500);
}
