int LED1 = 3;
int LED2 = 5;
int LED3 = 6;
int breaker = 0; 
int POT = 2; 
int val = 0; 


int brightness = 0;
int fadeAmount = 50;
int brightness2 = 0;
int fadeAmount2 = 20;
int brightness3 = 0;
int fadeAmount3 = 30;

void setup()
{
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

}

void loop()
{
  int input = Serial.read();
  if (input == 'a')
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
  }

  while (input == 'b')
  {
    int breaker = Serial.read(); 
    val = analogRead(A5); 
    Serial.println(val); 
      digitalWrite(LED1, HIGH);
      delay(val);
    val = analogRead(A5); 
    Serial.println(val); 
      digitalWrite(LED2, HIGH);
      delay(val);
    val = analogRead(A5); 
    Serial.println(val); 
      digitalWrite(LED3, HIGH);
      delay(val);
    val = analogRead(A5); 
    Serial.println(val); 
      digitalWrite(LED1, LOW);
      delay(val);
    val = analogRead(A5); 
    Serial.println(val); 
      digitalWrite(LED2, LOW);
      delay(val);
    val = analogRead(A5); 
    Serial.println(val); 
      digitalWrite(LED3, LOW);
      delay(val);
      
      if (breaker == 'e')
      {
        break;
      }

  }

  while (input == 'c')
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

}



