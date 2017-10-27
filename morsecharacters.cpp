#include "morseencrypt.h"

const MorseCharacter * MORSE_CHARACTERS[40] = {
  
  // CHAR_A
  new MorseCharacter(65, 2, ".-"),
  
  // CHAR_B
  new MorseCharacter(66, 4, "-..."),
  
  // CHAR_C
  new MorseCharacter(67, 4, "-.-."),
  
  // CHAR_D
  new MorseCharacter(68, 3, "-.."),
  
  // CHAR_E
  new MorseCharacter(69, 1, "."),
  
  // CHAR_F
  new MorseCharacter(70, 4, "..-."),
  
  // CHAR_G
  new MorseCharacter(71, 3, "--."),
  
  // CHAR_H
  new MorseCharacter(72, 4, "...."),
  
  // CHAR_I
  new MorseCharacter(73, 2, ".."),
  
  // CHAR_J
  new MorseCharacter(74, 4, ".---"),
  
  // CHAR_K
  new MorseCharacter(75, 3, "-.-"),
  
  // CHAR_L
  new MorseCharacter(76, 4, ".-.."),
  
  // CHAR_M
  new MorseCharacter(77, 2, "--"),
  
  // CHAR_N
  new MorseCharacter(78, 2, "-."),
  
  // CHAR_O
  new MorseCharacter(79, 3, "---"),
  
  // CHAR_P
  new MorseCharacter(80, 4, ".--."),
  
  // CHAR_Q
  new MorseCharacter(81, 4, "--.-"),
  
  // CHAR_R
  new MorseCharacter(82, 3, ".-."),
  
  // CHAR_S
  new MorseCharacter(83, 3, "..."),
  
  // CHAR_T
  new MorseCharacter(84, 1, "-"),
  
  // CHAR_U
  new MorseCharacter(85, 3, "..-"),
  
  // CHAR_V
  new MorseCharacter(86, 4, "...-"),
  
  // CHAR_W
  new MorseCharacter(87, 3, ".--"),
  
  // CHAR_X
  new MorseCharacter(88, 4, "-..-"),
  
  // CHAR_Y
  new MorseCharacter(89, 4, "-.--"),
  
  // CHAR_Z
  new MorseCharacter(90, 4, "--.."),
  
  // CHAR_0
  new MorseCharacter(48, 5, "-----"),
  
  // CHAR_1
  new MorseCharacter(49, 5, ".----"),
  
  // CHAR_2
  new MorseCharacter(50, 5, "..---"),
  
  // CHAR_3
  new MorseCharacter(51, 5, "...--"),
  
  // CHAR_4
  new MorseCharacter(52, 5, "....-"),
  
  // CHAR_5
  new MorseCharacter(53, 5, "....."),
  
  // CHAR_6
  new MorseCharacter(54, 5, "-...."),
  
  // CHAR_7
  new MorseCharacter(55, 5, "--..."),
  
  // CHAR_8
  new MorseCharacter(56, 5, "---.."),
  
  // CHAR_9
  new MorseCharacter(57, 5, "----."),
  
  // CHAR_.
  new MorseCharacter(46, 6, ".-.-.-"),
  
  // CHAR_QUES.ON_MARK
  new MorseCharacter(63, 6, "..--.."),
  
  // CHAR_EXCLAMA.ON_MARK
  new MorseCharacter(33, 6, "-.-.--"),
  
  // CHAR_AT
  new MorseCharacter(64, 6, ".--.-.")
};

MorseCharacter * getMorseCharacter(int index) {
  return MORSE_CHARACTERS[index];
}

