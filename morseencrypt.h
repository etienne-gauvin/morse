#ifndef morseencrypt_h
#define morseencrypt_h

#include "Arduino.h"

class MorseCharacter {
  public:
    char character;
    int unitCount;
    bool units[6];
    MorseCharacter(char character, int unitCount, const char * units);
    static const MorseCharacter * from(char c);
};

struct MorseWord {
  int charCount;
  const MorseCharacter * characters[16];
};

class MorseSentence {
  public:
    int wordCount;
    MorseWord * words[16];
    void from(char* sentence, int length);
};

#endif
