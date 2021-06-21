hu//#include <Leg.h>
#include "src/quadrapedControl/QuadroBot.h"

QuadroBot bot;

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps

  // build the robot parts
  int commonAngle1 = 70;
  OffsetServo *NYservo = new OffsetServo(2, commonAngle1, true);
  OffsetServo *NPservo = new OffsetServo(3, commonAngle1, true);
  OffsetServo *EYservo = new OffsetServo(4, commonAngle1, true);
  OffsetServo *EPservo = new OffsetServo(5, 85, true);
  OffsetServo *WYservo = new OffsetServo(6, 75, true);
  OffsetServo *WPservo = new OffsetServo(7, 100, true);
  OffsetServo *SYservo = new OffsetServo(8, commonAngle1, true);
  OffsetServo *SPservo = new OffsetServo(9, commonAngle1, true);

  Leg *NLeg = new Leg(NYservo, NPservo);
  Leg *SLeg = new Leg(SYservo, SPservo);
  Leg *ELeg = new Leg(EYservo, EPservo);
  Leg *WLeg = new Leg(WYservo, WPservo);

  bot = QuadroBot(NLeg, SLeg, ELeg, WLeg);
}

void loop() {

  if (Serial.available() > 0) {
    // read the incoming byte:
    int inNumber = Serial.parseInt();

    switch (inNumber) {
      case 1 :
        bot.lay();
        break;
      case 2 :
        bot.sit();
        break;
      case 3 :
        bot.stand();
        break;
      case 4 :
        bot.walk();
        break;
      case 5 :
        bot.rotate();
        break;
    }
  }

  bot.update();
}
