#include <SPI.h>

byte address = 0x00;
int D10= 10;
int num1 = 0;
int number1 = 0;

int D8= 8;
int num2 = 0;
int number2 = 0;

int D9 = 9;
int num3 = 0;
int number3 = 0;

void setup()
{
  Serial.begin(9600);
pinMode(A1, INPUT);
pinMode(A2, INPUT);
pinMode(A3, INPUT);
pinMode (D10, OUTPUT);
pinMode (D8, OUTPUT);
pinMode (D9, OUTPUT);
SPI.begin();
}

void loop()
{
    num1 = analogRead(A1);
    number1 = (num1*3);
    int i = number1-470;
    digitalPotWrite1(i);
    num2 = analogRead(A2);
    number2 = (num2*3);
    int j = number2-470;
    digitalPotWrite2(j);
    num3 = analogRead(A3);
    number3 = (num3*4);
    int k = number3-470;
    digitalPotWrite3(k);
    Serial.println(j);
    delay(100);
}


int digitalPotWrite1(int value)
{
  digitalWrite(D10, LOW);
  SPI.transfer(address);
  SPI.transfer(value);
  digitalWrite(D10, HIGH);
}

int digitalPotWrite2(int value)
{
  digitalWrite(D9, LOW);
  SPI.transfer(address);
  SPI.transfer(value);
  digitalWrite(D9, HIGH);
}

int digitalPotWrite3(int value)
{
  digitalWrite(D8, LOW);
  SPI.transfer(address);
  SPI.transfer(value);
  digitalWrite(D8, HIGH);
}
