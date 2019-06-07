short input(short function, short board) {

  if (function == DR) {
     short pin = pinValidation(board);

    short value = digitalRead(pin);
    return String(value);
  }
  else if (function == AR) {
    int pin = Serial.readStringUntil('%').toInt() ;
    int value = Serial.readStringUntil('%').toInt() ;

    if (value < 0 || value > 255)
      Serial.print(ValueWrong);
    else
      digitalWrite(pin, value);
  }
}
