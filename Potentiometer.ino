int LED1 = 3;
int LED2 = 5;
int LED3 = 6;
int input = 0;
int breaker = 0; 
int POT = 2; 
int val = 0; 



void setup() {
  // put your setup code here, to run once:
{
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(POT, OUTPUT);
  digitalWrite(POT, HIGH); 
}
}

void loop() {
  // put your main code here, to run repeatedly:
  int input = Serial.read();
  if (input == 'a')
  {

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
      
}
