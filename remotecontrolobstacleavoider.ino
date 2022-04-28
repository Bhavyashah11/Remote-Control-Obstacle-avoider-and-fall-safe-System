void forward(){
digitalWrite(8,LOW);
digitalWrite(9,HIGH);
digitalWrite(10,HIGH);
digitalWrite(11,LOW);
}
void skidright(){
digitalWrite(8,LOW);
digitalWrite(9,HIGH);
digitalWrite(10,LOW);
digitalWrite(11,HIGH);
}
void skidleft(){
digitalWrite(8,HIGH);//left wheel
digitalWrite(9,LOW);
digitalWrite(10,HIGH);//right
wheel
digitalWrite(11,LOW);
}
void reverse(){
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
digitalWrite(11,HIGH);
}
void pause(){
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
}
#include <IRremote.h>
int RECV_PIN = 4;
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup()
{
Serial.begin(9600);
irrecv.enableIRIn(); // Start the
receiver
pinMode(A4,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(8,OUTPUT);
pinMode(7,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
}
void loop() {
int ldr0 =analogRead(A4);
int ldr1=analogRead(A1);
int ldr2=analogRead(A2);
Serial.println(ldr0);
Serial.println(ldr1);
Serial.println(ldr2);
if (ldr1>100 || ldr0>>100)
{
reverse();
digitalWrite(7,HIGH);
delay(500);
digitalWrite(7,LOW);
// delay(500);
pause();
}
if(ldr2<500)
{
reverse();
digitalWrite(7,HIGH);
delay(500);
digitalWrite(7,LOW);
//delay(500);
pause();
}
if (irrecv.decode(&results)) {
Serial.println(results.value,
HEX);
irrecv.resume(); // Receive the
next value
}
delay(100);
if (results.value==0X1CE330CF)
//forward
{
forward();
results.value=0;
}
if (results.value==0X1CE3B04F)
//Backward
{
reverse();
results.value=0;
}
if (results.value==0X1CE36897)
//Right
{
skidright();
delay(450);
forward();
results.value=0;
}
if (results.value==0X1CE3E817)
//left
{
skidleft();
delay(450);
forward();
results.value=0;
}
if (results.value==0X1CE358A7)
//pause
{
pause();
results.value=0;
}
}