#include <Servo.h>
#define FINGERCOUNT 3
#define HANDDELAY 200

Servo pointer, middle, index;

void setup() {
  // put your setup code here, to run once:
  pointer.attach(8);
  middle.attach(9);
  index.attach(10);
  
  pointer.write(0);
  middle.write(0);
  index.write(0);

  delay(HANDDELAY);
  
  pointer.write(100);

  delay(HANDDELAY);
  
  middle.write(100);

  delay(HANDDELAY);
  
  index.write(100);

  delay(2000);
  
  pointer.write(0);

  middle.write(0);
  
  index.write(0);

}

void loop() {
  // put your main code here, to run repeatedly:

}
