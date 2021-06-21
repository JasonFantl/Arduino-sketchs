#ifndef Leg_h
#define Leg_h

#include "Arduino.h"
#include "OffsetServo.h"

class Leg {
  private:
    OffsetServo *yawServo;
    OffsetServo *pitchServo;
   public:
    Leg();
    Leg(OffsetServo *_yawServo, OffsetServo *_pitchServo);
    void writeYaw(int yaw);
    void writePitch(int pitch);
    void writeYawPitch(int yaw, int pitch);
};

#endif
