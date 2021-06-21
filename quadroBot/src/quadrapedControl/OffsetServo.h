#ifndef OffsetServo_h
#define OffsetServo_h

#include "Arduino.h"
#include <Servo.h>

class OffsetServo {
  private:
    Servo *servo; // servo library only lets us have 12 instances, pointers lets us control when we actually instansiate
    int offset;
    bool reversed;

  public:
    OffsetServo();
    OffsetServo(int pin, int _offset, bool _reversed);
    
    void write(int pos);
};

#endif

