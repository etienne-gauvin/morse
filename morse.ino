#include <avr/pgmspace.h>
#include "morseencrypt.h"
#include "morsetransmit.h"

unsigned long time = 0;
unsigned long lastTime = 0;

MorseSentence sentence;
MorseTransmission transmission;

// The sentence to transmit
char stringSentence[] = "NEVER GONNA LET YOU UP NEVER GONNA LET YOU DOWN NEVER GONNA RUN AROUND AND DESERT YOU";

void setup() {
  Serial.begin(9600);
  
  // Init the sentence
  sentence.from(stringSentence, sizeof(stringSentence) - 1);
  
  // Init the transmission
  transmission.sentence = & sentence;
  transmission.timeUnit = 250;
  transmission.dashOutputPin = LED_BUILTIN;
  transmission.dotOutputPin = LED_BUILTIN;
  transmission.init();
}

void loop() {

  time = millis();
  if (time < lastTime) {
    lastTime = 0;
  } else {
    transmission.loop(time - lastTime);
    lastTime = time;  
  }

  delay(1);
}
