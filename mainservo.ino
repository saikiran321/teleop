#include <Servo.h> 
Servo myservo,myservo1;  // create servo object to control a servo 


char input[6];
int inp[3];
int inp2[3];
int res;

int powint(int x, int y)
{
  int val=x;
  for(int z=0;z<=y;z++)
  {
    if(z==0)
      val=1;
    else
      val=val*x;
  }
  return val;
}


void setup() {
  Serial.begin(9600);
  myservo.attach(6);
  myservo.write(90);
  myservo1.attach(10);
  myservo1.write(90);
  while (!Serial) ;    
}

void loop() {
  int value=0;
  int value1=0;
  int str_ln=0;
  if(Serial.available())
   {
   Serial.readBytes(input,6);
   for(int i=0;i<3;i++)
   {
   inp[i] = int(input[i])-'0';
   //Serial.println(inp[i]);
   value=value+ inp[i]*powint(10,2-i);
   }
   for(int i=3;i<6;i++)
   {
   inp2[i-3] = int(input[i])-'0';
   value1=value1+ inp2[i-3]*powint(10,5-i);
   //Serial.println(inp2[i-3]);
   }
   if(value >=0 && value <=180 &&value1>=0&& value1<=180)
   {
       Serial.println(value);
       Serial.println(value1);
       myservo.write(value);
       delay(10);
        myservo1.write(value1);
   }
   }

}
