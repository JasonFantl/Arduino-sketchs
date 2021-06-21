#include <Servo.h>

int inNumber = 0;
int servo = 0;
bool setServo = true;

Servo servos[8];  // create servo object to control a servo


void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps

  for (int i = 0; i < 8; i ++) {
    servos[i].attach(i + 2);
    servos[i].write(70);
  }
  Serial.println("default angles at 90 for all servos");

}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    inNumber = Serial.parseInt();

    if (inNumber != 0) {
      if (setServo) {
        servo = inNumber - 2; // servo pins start at 2, translates to index associated with pin
        Serial.print("attched to servo ");
        Serial.println(inNumber);
      } else {
        servos[servo].write(inNumber);
        Serial.print("set angle to ");
        Serial.println(inNumber);
      }
      setServo = !setServo;
    }
  }
}
