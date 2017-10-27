#include <avr/pgmspace.h>
#include "morseencrypt.h"
#include "morsetransmit.h"

char stringSentence[] = "NEVER GONNA LET YOU UP NEVER GONNA LET YOU DOWN NEVER GONNA RUN AROUND AND DESERT YOU";
MorseSentence sentence;
MorseTransmission transmission;

unsigned long time = 0;
unsigned long lastTime = 0;

void setup() {
  Serial.begin(9600);

  sentence.from(stringSentence, sizeof(stringSentence) - 1);

  transmission.sentence = & sentence;

  transmission.timeUnit = 250;
  
  transmission.dashOutputPin = LED_BUILTIN;
  transmission.dotOutputPin = LED_BUILTIN;

  transmission.init();
  
  Serial.println();
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
