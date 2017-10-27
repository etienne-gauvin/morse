#include "irreceiver.h"

void IRReceiver::setup(int pin) {
  this->irrecv = IRrecv(pin);
  this->irrecv.enableIRIn();
  
}

const int IRReceiver::getCommand()
{
  if (this->irrecv.decode(& this->results)) {
    const int command = this->results.value;
    this->irrecv.resume();
    return command;
  } else {
    return 0;
  }
}


