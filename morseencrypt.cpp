#include <avr/pgmspace.h>
#include "morseencrypt.h"
#include "morsecharacters.h"
#include "Arduino.h"

/**
 * Creates a new character.
 * @param {char} character as an ASCII code
 * @param {int} unitCount the number of units in the parameter units
 * @param {const char *} units the morse code as a string of . and -
 */
MorseCharacter::MorseCharacter(char character, int unitCount, const char * units) {
  this->character = character;
  this->unitCount = unitCount;

  for (int i = 0; i < unitCount; i++) {
    this->units[i] = units[i] == '.';
  }
}

/**
 * Get a pointer to the MorseCharacter corresponding to a char.
 * @param {char} character
 * @return {const MorseCharacter *}
 */
const MorseCharacter * MorseCharacter::from(char c) {
  const int numberOfChars = 40;
  const MorseCharacter * rc = getMorseCharacter(39);

  for (int i = 0; i < numberOfChars; i++) {
    if (c == getMorseCharacter(i)->character) {
      rc = getMorseCharacter(i);
    }
  }

  return rc;
}

/**
 * Initialize the MorseSentence from a string.
 * @param {char *} sentence
 * @param {int} length
 */
void MorseSentence::from(char * sentence, int length) {
  this->words[0] = new MorseWord;
  this->words[0]->charCount = 0;
  this->wordCount = 1;

  for (int i = 0; i < length; i++) {
    if (sentence[i] == ' ') {
      this->wordCount++;
      this->words[this->wordCount - 1] = new MorseWord;
      this->words[this->wordCount - 1]->charCount = 0;
    } else {
      MorseWord * currentWord = this->words[this->wordCount - 1];
      currentWord->characters[currentWord->charCount] = MorseCharacter::from(sentence[i]);
      currentWord->charCount++;
    }
  }
}



