#include <SPI.h>
int LED1 = 3;
int LED2 = 5;
int LED3 = 6;
int breaker = 0; 
int POT = 2; 
int val = 0; 
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

int brightness = 0;
int fadeAmount = 50;
int brightness2 = 0;
int fadeAmount2 = 20;
int brightness3 = 0;
int fadeAmount3 = 30;

void setup()
{
  Serial.begin(9600);
  pinMode(A1, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode (D8, OUTPUT);
  pinMode (D9, OUTPUT);
  pinMode (D10, OUTPUT);
  digitalWrite(POT, HIGH); 
  SPI.begin();
}

void loop()
{
  int input = Serial.read();
  if (input == '1')
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
  }

  if (input == '2')
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
  }  

  while (input == '3')
  {
    int breaker = Serial.read(); 
    val = analogRead(A5); 
      digitalWrite(LED1, HIGH);
      delay(val);
    val = analogRead(A5); 
      digitalWrite(LED2, HIGH);
      delay(val);
    val = analogRead(A5); 
      digitalWrite(LED3, HIGH);
      delay(val);
    val = analogRead(A5); 
      digitalWrite(LED1, LOW);
      delay(val);
    val = analogRead(A5); 
      digitalWrite(LED2, LOW);
      delay(val);
    val = analogRead(A5); 
      digitalWrite(LED3, LOW);
      delay(val);
      
      if (breaker == 'e')
      {
        break;
      }

  }

  while (input == '4')
  {
    int breaker = Serial.read(); 
    analogWrite(LED1, brightness);
    brightness = brightness + fadeAmount;
    if (brightness <=0 || brightness >= 225) 
    {
      fadeAmount = -fadeAmount;
    }
    analogWrite(LED2, brightness2);
    brightness2 = brightness2 + fadeAmount2;
    if (brightness2 <=0 || brightness2 >= 225) 
    {
      fadeAmount2 = -fadeAmount2;
    }
    analogWrite(LED3, brightness3);
    brightness3 = brightness3 + fadeAmount3;
    if (brightness3 <=0 || brightness3 >= 225) 
    {
      fadeAmount3 = -fadeAmount3;
    }
    delay(20);

    if (breaker == 'e')
    {
      break;
    }    
  }
  while (input == '5')
  {
    num1 = analogRead(A1);
    number1 = (num1*4);
    int i = number1-730;
    digitalPotWrite1(i);
    num2 = analogRead(A2);
    number2 = (num2*4);
    int j = number2-730;
    digitalPotWrite2(j);
    num3 = analogRead(A3);
    number3 = (num3*4);
    int k = number3-730;
    digitalPotWrite3(k);
    delay(100);
  }
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
  digitalWrite(D8, LOW);
  SPI.transfer(address);
  SPI.transfer(value);
  digitalWrite(D8, HIGH);
}

int digitalPotWrite3(int value)
{
  digitalWrite(D9, LOW);
  SPI.transfer(address);
  SPI.transfer(value);
  digitalWrite(D9, HIGH);
}

