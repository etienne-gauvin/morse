# Morse Communication on an Arduino

## Morse Characters

Characters `A-Z`, `0-1`, `.?!@` and spaces are supported.

## String to Morse

The sentence is (for now) defined in the [morse.ino](./morse.ino) file.
It is processed in [morseencrypt.cpp](./morseencrypt.cpp) to be turned into a `MorseSentence` object,
itself containing `MorseWords`, each word containing `MorseCharacters`,
and each character containing units that are _dots_ or _dash_.

## Morse Transmission

I'll use a laser to transmit the morse sequence, but a led perfectly fits for testing purposes.
The transmission is processed in [morsetransmit.cpp](morsetransmit.cpp) by the `MorseTransmission` class, using a `MorseSentence` object.
The method [MorseTransmission::loop()](./morsetransmit.cpp#L21) is non-blocking, and must be called in the main loop of the Arduino code.

The parameters of _MorseTransmission_ are:

* `int timeUnit`: the duration of a morse _dot_.
* `int dotOutputPin`: the pin turned on to display morse _dots_.
* `int dashtOutputPin`: the pin turned on to display morse _dashs_ (can be the same as `dotOutputPin`).

## To Do: Morse Reception

