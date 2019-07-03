short setFunction(int function, int board) {
  if (function == PM) {
    short pin = pinValidation(board);
    Serial.print("pin=");
    Serial.println(pin);
    if (pin < 0)
      return pin;

    String value = valueValidation();
    if (isNumeric(value)) {
      byte valueInt = value.toInt();
      if (valueInt < 0)
        return valueInt;

      if (valueInt == Input)
        pinMode(pin, INPUT);
      else if (valueInt == Output) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
      }
      else if (valueInt == Input_pullup)
        pinMode(pin, INPUT_PULLUP);
      else
        return ValueNotSupported;

      return RequestCompleted;
    }
  }
}
// Serial.print(typeCheck);
