#ifndef morsetransmit_h
#define morsetransmit_h

#include "Arduino.h"
#include "morsecharacters.h"

#define TIME_UNIT 250

#define TURNED_OFF_STATE 0
#define DOT_STATE 1
#define DASH_STATE 2
#define UNIT_SPACE_STATE 3
#define CHAR_SPACE_STATE 4
#define WORD_SPACE_STATE 5
#define SENTENCE_SPACE_STATE 6
#define PAUSED_STATE 7
#define TURNED_ON_STATE 8

#define DOT true
#define DASH false

class MorseTransmission {
  public:
    int dotOutputPin = 4;
    int dashOutputPin = 5;
    int powerOutputPin = NULL;
    int pauseOutputPin = NULL;
    
    int timeUnit = TIME_UNIT;
    
    MorseSentence * sentence;
    
    void loop(int dt);
    void init();

    void togglePower();
    void togglePlayPause();
    
  private:
    bool isPaused = true;
    bool isPowerOff = true;
  
    void turnOff();
    void turnOn();
    
    void pause();
    void play();
    
    int previousStatus = NULL;
    int status = TURNED_OFF_STATE;
    
    int timeLeft = 0;
    
    int currentWordIndex = 0;
    int currentCharIndex = 0;
    int currentUnitIndex = 0;
};

#endif
