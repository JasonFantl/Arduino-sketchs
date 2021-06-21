#include "Arduino.h"
#include "Leg.h"

OffsetServo::OffsetServo(int pin, int _offset, bool _reversed) {
  servo = new Servo();
  servo->attach(pin);
  offset = _offset;
  reversed = _reversed;

  
  servo->write(offset);
}

OffsetServo::OffsetServo() {

}

void OffsetServo::write(int pos) {
  if (servo == NULL) {
    return;
  }
  
  int offsetPos = offset;
  if (reversed) {
    offsetPos -= pos;
  }
  else {
    offsetPos += pos;
  }
  
  if (offsetPos < 0) {
    offsetPos = 0;
  } else if (offsetPos >= 180) {
    offsetPos = 179;
  }
  
  servo->write(offsetPos);
}

