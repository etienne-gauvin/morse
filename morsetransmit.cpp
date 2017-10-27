#include "morsetransmit.h"
#include "morseencrypt.h"
#include "morsecharacters.h"
#include "Arduino.h"

/**
 * Initialize properties and the pin(s) used for transmission.
 */
void MorseTransmission::init() {
  this->timeLeft = 0;
  
  pinMode(this->dotOutputPin, OUTPUT);

  if (this->dotOutputPin != this->dashOutputPin)
    pinMode(this->dashOutputPin, OUTPUT);
}

/**
 * Non-blocking loop controlling the transmission.
 */
void MorseTransmission::loop(int dt) {
  if (this->timeLeft - dt <= 0) {
    MorseWord * currentWord = this->sentence->words[this->currentWordIndex];
    const MorseCharacter * currentChar = currentWord->characters[this->currentCharIndex];
    
    switch (this->status) {
      case DOT_STATE:
      case DASH_STATE:

        // Next Unit
        if (this->currentUnitIndex + 1 < currentChar->unitCount) {
          this->currentUnitIndex++;
          this->status = UNIT_SPACE_STATE;
          this->timeLeft = this->timeUnit;
          Serial.print("");
        
        // Next Character
        } else {
          if (this->currentCharIndex + 1 < currentWord->charCount) {
            this->currentUnitIndex = 0;
            this->currentCharIndex++;
            this->status = CHAR_SPACE_STATE;
            this->timeLeft = this->timeUnit * 3;
            Serial.print(" ");
          
          // Next Word
          } else if (this->currentWordIndex + 1 < this->sentence->wordCount) {
            this->currentUnitIndex = 0;
            this->currentCharIndex = 0;
            this->currentWordIndex++;
            this->status = WORD_SPACE_STATE;
            this->timeLeft = this->timeUnit * 7;
            Serial.print("   ");
          
          // Restart Sentence
          } else {
            this->currentUnitIndex = 0;
            this->currentCharIndex = 0;
            this->currentWordIndex = 0;
            this->status = SENTENCE_SPACE_STATE;
            this->timeLeft = this->timeUnit * 20;
            Serial.println("");
            Serial.println("/");
          }
          
          Serial.print(this->sentence->words[this->currentWordIndex]->characters[this->currentCharIndex]->character);
          Serial.print(" ");
        }
        
        break;

      case TURNED_OFF_STATE:
      case PAUSED_STATE:
        break;

      default:
      case TURNED_ON_STATE:
        this->timeLeft = 0;
        Serial.print(this->sentence->words[this->currentWordIndex]->characters[this->currentCharIndex]->character);
        Serial.print(" ");
      
      case UNIT_SPACE_STATE:
      case CHAR_SPACE_STATE:
      case WORD_SPACE_STATE:
      case SENTENCE_SPACE_STATE:
    
        switch (currentChar->units[this->currentUnitIndex]) {
          case DOT:
            this->status = DOT_STATE;
            this->timeLeft = this->timeUnit;
            Serial.print(".");
            break;
          
          case DASH:
            this->status = DASH_STATE;
            this->timeLeft = this->timeUnit * 3;
            Serial.print("-");
            break;
        }
          
        break;

    }
  } else {
    this->timeLeft -= dt;
  }
  
  // Update pin(s) status
  if (this->status != this->previousStatus) {
    if (this->dotOutputPin == this->dashOutputPin) {
      switch (this->status) {
        case DOT_STATE:
        case DASH_STATE:
          digitalWrite(this->dotOutputPin, HIGH);
          break;
        default:
          digitalWrite(this->dotOutputPin, LOW);
      }
    } else {
      switch (this->status) {
        case DOT_STATE:
          digitalWrite(this->dotOutputPin, HIGH);
          digitalWrite(this->dashOutputPin, LOW);
          break;
        case DASH_STATE:
          digitalWrite(this->dashOutputPin, HIGH);
          digitalWrite(this->dotOutputPin, LOW);
          break;
        default:
          digitalWrite(this->dashOutputPin, LOW);
          digitalWrite(this->dotOutputPin, LOW);
      }
    }

    this->previousStatus = this->status;
  }
}

/**
 * Toggle the power
 */
void MorseTransmission::togglePower() {
  if (this->status == TURNED_OFF_STATE) {
    this->turnOn();  
  } else {
    this->turnOff();
  }
}

/**
 * Start the transmission
 * by the start of the sentence.
 */
void MorseTransmission::turnOn() {
  if (this->status == TURNED_OFF_STATE) {
    this->status = TURNED_ON_STATE;
    Serial.println("");
    Serial.println("TURNED_ON_STATE");
    
    this->currentUnitIndex = 0;
    this->currentCharIndex = 0;
    this->currentWordIndex = 0;
    
    digitalWrite(this->dashOutputPin, LOW);
  
    if (this->dotOutputPin != this->dashOutputPin)
      digitalWrite(this->dotOutputPin, LOW);
  }
}

/**
 * Stop completetly the transmission
 */
void MorseTransmission::turnOff() {
  this->status = TURNED_OFF_STATE;
    Serial.println("");
    Serial.println("TURNED_OFF_STATE");
}

/**
 * Toggle the play/pause state
 */
void MorseTransmission::togglePlayPause() {
  if (this->status == PAUSED_STATE) {
    this->play();
  } else {
    this->pause();
  }
}

/**
 * Pause the transmission
 */
void MorseTransmission::pause() {
  if (this->status != TURNED_OFF_STATE) {
    this->status = PAUSED_STATE;
    Serial.print(" [PAUSE] ");
  }
}

/**
 * Play the transmission
 * from the start of the current character.
 */
void MorseTransmission::play() {
  if (this->status == PAUSED_STATE) {
    this->status = CHAR_SPACE_STATE;
    this->timeLeft = 0;
    this->currentUnitIndex = 0;
    Serial.print(" [PLAY] ");
  }
}

