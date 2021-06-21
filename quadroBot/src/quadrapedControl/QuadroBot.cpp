#include "Arduino.h"
#include "QuadroBot.h"

QuadroBot::QuadroBot() {
  
}

QuadroBot::QuadroBot(Leg *_NLeg, Leg *_SLeg, Leg *_ELeg, Leg *_WLeg) {
  NLeg = _NLeg;
  SLeg = _SLeg;
  ELeg = _ELeg;
  WLeg = _WLeg;
  
  pitchRange = 30;
  yawRange = 30;
}

void QuadroBot::update() {
  int interval = 100;
  int now = millis();
      
  switch(state) {
    case laying :
      setAllYawPitch(0, -pitchRange);
      break;
    case sitting :
      setAllYawPitch(0, 0);
      break;
    case standing :
      setAllYawPitch(0, pitchRange);
      break;
    case rotating :
      // rotate has 3 states
      if (now > lastUpdate + interval) {
        animationTicker = (animationTicker + 1) % 3;
        lastUpdate = now;
      }
      
      if (animationTicker == 0) {
        n(NLeg, 1, 1);
        n(SLeg, 1, 1);
        n(ELeg, -1, 1);
        n(WLeg, -1, 1);
      } else if (animationTicker == 1) {
        n(NLeg, -1, 0);
        n(SLeg, -1, 0);
        n(ELeg, 1, 1);
        n(WLeg, 1, 1);
      } else if (animationTicker == 2) {
        n(NLeg, -1, 1);
        n(SLeg, -1, 1);
        n(ELeg, 1, 0);
        n(WLeg, 1, 0);
      }
      break;
    case walking :
      interval = 500;
      // walk has 5 states
      if (now > lastUpdate + interval) {
        animationTicker = (animationTicker + 1) % 4;
        lastUpdate = now;
      }
      
      if (animationTicker == 0) {
        n(NLeg, 1, 1);
        n(SLeg, -1, 1);
        n(ELeg, -1, 0);
        n(WLeg, 1, 0);
      } else if (animationTicker == 1) {
        n(NLeg, -1, 1);
        n(SLeg, 1, 1);
        n(ELeg, 1, 0);
        n(WLeg, -1, 0);
      } else if (animationTicker == 2) {
        n(NLeg, -1, 0);
        n(SLeg, 1, 0);
        n(ELeg, 1, 1);
        n(WLeg, -1, 1);
      } else if (animationTicker == 3) {
        n(NLeg, 1, 0);
        n(SLeg, -1, 0);
        n(ELeg, -1, 1);
        n(WLeg, 1, 1);
      }
      break;
  }
}

void QuadroBot::n(Leg *leg, int yb, int pb) {
  leg->writeYawPitch(yb*yawRange, pb*pitchRange);
}

void QuadroBot::setAllYawPitch(int yaw, int pitch) {
  NLeg->writeYawPitch(yaw, pitch);
  SLeg->writeYawPitch(yaw, pitch);
  ELeg->writeYawPitch(yaw, pitch);
  WLeg->writeYawPitch(yaw, pitch);
}


void QuadroBot::lay() {
  state = laying;
}
void QuadroBot::sit() {
  state = sitting;
}
void QuadroBot::stand() {
  state = standing;
}
void QuadroBot::rotate() {
  state = rotating;
  animationTicker = 0;
  lastUpdate = millis();
}
void QuadroBot::walk() {
  state = walking;
  animationTicker = 0;
  lastUpdate = millis();
}
