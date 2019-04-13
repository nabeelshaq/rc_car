// IRremote library from this link
// https://github.com/z3t0/Arduino-IRremote
#include <IRremote.h>

int REC = 11;
IRrecv irrecv(REC);

decode_results results;

void setup() {
  
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
  
}

void loop() {
  
   if (irrecv.decode(&results)) 
   {
     unsigned long x=results.value;
     irrecv.resume();
     Serial.println(x);
     
     if(x==2160022444) {
          digitalWrite(10,HIGH);
          digitalWrite(9,LOW );
          digitalWrite(12,LOW );
          digitalWrite(13,HIGH );
     }
     else if(x==2160020404) {
          digitalWrite(10,LOW);
          digitalWrite(9,HIGH );
          digitalWrite(12,HIGH );
          digitalWrite(13,LOW );
     }
     else if(x==2160034684) {
          digitalWrite(10,LOW );
          digitalWrite(9,LOW);
          digitalWrite(12,LOW );
          digitalWrite(13,HIGH);       
      }
     else if(x==2160040294) {
          digitalWrite(10,HIGH );
          digitalWrite(9,LOW);
          digitalWrite(12,LOW );
          digitalWrite(13,LOW);
     }
     else{
          digitalWrite(10,LOW );
          digitalWrite(9,LOW);
          digitalWrite(12,LOW );
          digitalWrite(13,LOW);
     }
     
   }
   
}
