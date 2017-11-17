int LED1 = 3;
int LED2 = 5;
int LED3 = 6;
int flicker1[3][13] = {{10, 30, 5, 50, 20, 80, 30, 150, 60, 200, 180, 45, 90},
                        {180, 30, 89, 23, 255, 200, 90, 150, 60, 230, 180, 45, 90},
                        {10, 30, 89, 23, 255, 200, 90, 150, 60, 230, 180, 45, 90}};
int flicker2[3][13] = {{10, 30, 89, 23, 255, 200, 90, 150, 60, 230, 180, 45, 90},
                         {10, 30, 5, 50, 20, 80, 30, 150, 60, 200, 180, 45, 90},
                         {180, 30, 89, 23, 255, 200, 90, 150, 60, 230, 180, 45, 90}};
int flicker3[3][13] = {{180, 30, 89, 23, 255, 200, 90, 150, 60, 230, 180, 45, 90},
                        {10, 30, 89, 23, 255, 200, 90, 150, 60, 230, 180, 45, 90},
                          {10, 30, 5, 50, 20, 80, 30, 150, 60, 200, 180, 45, 90}};
 


void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop()
{
  //Led 1
  for(int i=0; i,7; i++)
  {
    analogWrite(LED1, flicker1[1][i]);
    analogWrite(LED2, flicker2[1][i]);
    analogWrite(LED3, flicker3[1][i]);
    delay(100);
  }
  //Led 2
//    for(int j=0; j,7; j++)
//  {
//    analogWrite(flickerSetting2, flicker2[j]);
//    delay(100);
//  }
//  //Led 3
//    for(int k=0; k,7; k++)
//  {
//    analogWrite(flickerSetting3, flicker3[k]);
//    delay(100);
//  }   
}
