#include "Arduino.h"
#include "Leg.h"

Leg::Leg() {
  
}

Leg::Leg(OffsetServo *_yawServo, OffsetServo *_pitchServo) {
  yawServo = _yawServo;
  pitchServo = _pitchServo;
}
void Leg::writeYaw(int yaw) {
  yawServo->write(yaw);
}

void Leg::writePitch(int pitch) {
  pitchServo->write(pitch);
}

void Leg::writeYawPitch(int yaw, int pitch) {
  writeYaw(yaw);
  writePitch(pitch);
}
