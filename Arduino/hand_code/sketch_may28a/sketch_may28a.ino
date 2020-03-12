#include <Servo.h>

Servo arr[5];
  
void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 5; i++) arr[i].attach(5 + i);
  for(int i = 0; i < 5; i++) arr[i].write(0);
  delay(2000);
  for(int i = 0; i < 5; i++) {arr[i].write(180);}
  delay(2000);
  for(int i = 0; i < 5; i++) {arr[i].write(0);}
  
}
void loop() {
  // put your main code here, to run repeatedly:

}
