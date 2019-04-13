//IRremote library from this link
// https://github.com/z3t0/Arduino-IRremote

#include<IRremote.h>  

IRsend irsend;
void setup() 
{
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
}

void loop() 
{
  int x= map(analogRead(A0),0,1023,0,10);
  int y= map(analogRead(A1),0,1023,0,10);

  if(x==0 && y==5)
  {
     irsend.sendNEC(0x80BF53AC,32);
  }
  else if(x==10 && y==5)
  {
      irsend.sendNEC(0x80BF4BB4,32);
  }
  else if(x==5 && y==0)
  {
     irsend.sendNEC(0x80BF9966,32);
  }
  else if(x==5 && y==10)
  {
    irsend.sendNEC(0x80BF837C,32);
  }
  else
  {
    irsend.sendNEC(0x70CA9977,32);
  }
  delay(500);
}
