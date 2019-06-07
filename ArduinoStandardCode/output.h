short outputFunction(short function, short board) {
  //    short function = getFunction();
  //    short board = getBoard();
  if (function == DW) {

    short pin = pinValidation(board);

    if (pin < 0)
      return pin;

    String value = valueValidation();
    if (isNumeric(value)) {
      byte valueInt = value.toInt();
      if (valueInt < 0)
        return valueInt;

      if (!(value == 0 || value == 1))
        return ValueNotSupported;

      digitalWrite(pin, value);
      return RequestCompleted;
    }
    return ValueNotSupported;
  }
  else if (function == AR) {

    short pin = pinValidation(board);

    if (pin < 0)
      return pin;

    String value = valueValidation();
    if (isNumeric(value)) {
      byte valueInt = value.toInt();
      if (valueInt < 0)
        return valueInt;

      if (value < 0 || value > 255)
        return ValueNotSupported;

      analogWrite(pin, value);
      return RequestCompleted;
    }
    return ValueNotSupported;

  }
}
