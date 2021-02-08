int a[] = {10,5,7,6};
void setup() 
{
  Serial.begin(19200);// put your setup code here, to run once:

}

void loop() 
{
  for(int i = 0; i<4; ++i) 
  {
    for(int k = i+1; k<4; ++k)
    {
      if(a[k] < a[k+1])
      {
        int temp = a[k];
        a[k] = a[k+1];
        a[k + 1] = temp;
      }
    }
  }
  Serial.println(a[0]);
  delay(1000);
  Serial.println(a[1]);
  delay(1000);
  Serial.println(a[2]);
  delay(1000);
  Serial.println(a[3]);
  delay(9000);
  
  
  // put your main code here, to run repeatedly:
}
