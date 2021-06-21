#ifndef QuadroBot_h
#define QuadroBot_h

#include "Arduino.h"
#include "Leg.h"

enum moveState {
  laying, 
  sitting, 
  standing, 
  rotating,
  walking
};

class QuadroBot {
  private:
    Leg *NLeg;
    Leg *SLeg;
    Leg *ELeg;
    Leg *WLeg;
    
    moveState state;
    unsigned int animationTicker;
    unsigned int lastUpdate;
    
    void setAllYawPitch(int yaw, int pitch);
    void n(Leg *leg, int yb, int pb);
    
  public:
    QuadroBot();
    QuadroBot(Leg *_NLeg, Leg *_SLeg, Leg *_ELeg, Leg *_WLeg);
    
    void update();
    
    void lay();
    void sit();
    void stand();
    void walk();
    void rotate();
    
    int layHeight;
    int sitHeight;
    int standHeight;
    
    int yawRange;
    int pitchRange;

};

#endif

