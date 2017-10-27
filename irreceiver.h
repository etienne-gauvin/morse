#ifndef irreceiver_h
#define irreceiver_h

#include <stdint.h>
#include "Arduino.h"
#include <boarddefs.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
#include <IRremoteInt.h>
#include <IRremote.h>

class IRReceiver {
  public:
    static const int POWER =        0xFFA25D;
    static const int FUNC_STOP =    0xFFE21D;
    static const int FAST_BACK =    0xFF22DD;
    static const int PAUSE =        0xFF02FD;
    static const int FAST_FORWARD = 0xFFC23D;
    static const int DOWN =         0xFFE01F;
    static const int VOL_UP =       0xFF629D;
    static const int VOL_DOWN =     0xFFA857;
    static const int UP =           0xFF906F;
    static const int EQ =           0xFF9867;
    static const int ST_REPT =      0xFFB04F;
    static const int BUTTON_0 =     0xFF6897;
    static const int BUTTON_1 =     0xFF30CF;
    static const int BUTTON_2 =     0xFF18E7;
    static const int BUTTON_3 =     0xFF7A85;
    static const int BUTTON_4 =     0xFF10EF;
    static const int BUTTON_5 =     0xFF38C7;
    static const int BUTTON_6 =     0xFF5AA5;
    static const int BUTTON_7 =     0xFF42BD;
    static const int BUTTON_8 =     0xFF4AB5;
    static const int BUTTON_9 =     0xFF52AD;
    static const int REPEATED =     0xFFFFFFFF;

    void setup(int pin);
    const int getCommand();

  private:
    IRrecv irrecv = NULL;
    decode_results results;
};

#endif
