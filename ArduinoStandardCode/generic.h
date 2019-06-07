boolean isNumeric(String str) {
  unsigned int stringLength = str.length();

  if (stringLength == 0) {
    return false;
  }
  unsigned int i = 0;
  if(str.charAt(0)=='-')i++;
  for (; i < stringLength; ++i) {
    if (isDigit(str.charAt(i))) {
      continue;
    }
    return false;
  }
  return true;
}

void chrArraySubstring(const char chArray[], char substr[], int start, int last = 0) {
  if (last == 0)
    while (chArray[last] != '\0')last++;

  int k = 0;

  for (int i = start; i <= last; i++) {
    substr[k++] = chArray[i];
  }
  substr[k] = '\0';
}

short pinValidation(short board) {
  byte boardIndex = board - 1;
  char* pin = commandJson["pin"];
  // Serial.println(pin);
  if (pin[0] == 0)
    return PinNotProvided;

  if (isNumeric(pin)) {
    short pinInt = atoi(pin);
    if (noOfDigitalPinsByBoard[boardIndex] > pinInt)
      return pinInt;

    return  PinDoesnotExistOnBoard;
  }
  else if (pin[0] == 'A' || pin[0] == 'a') {
    char* substr = new char(sizeof(pin));
    chrArraySubstring(pin, substr, 1);
    if (isNumeric(substr)) {

      byte pinAnalog = atoi(substr);
      delete(substr);

      if (noOfAnalogPinsByBoard[boardIndex] > pinAnalog) {
        return (pinAnalog + noOfDigitalPinsByBoard[boardIndex]);
      }
    }
    return  PinDoesnotExistOnBoard;
  }
  return  PinDoesnotExistOnBoard;

}

String valueValidation() {
   char* value = commandJson["value"];
  if (value[0]== 0)
    return String(ValueNotProvided);

  return value;
}

short boardValidation(short board) {

  if (!board)
    return BoardNotProvided;

  if (board < boardMAX)
    return board ;
  return BoardDoesnotExist;
}

short typeValidation(short type) {

  if (!type)
    return TypeNotProvided;

  if (type < typeMAX)
    return type ;
  return TypeDoesnotExist;

}
short functionValidation(short type, short function) {


  if (!function)
    return FunctionNotProvided;

  if (function < noOfFunctionByType[type - 1])
    return function ;
  return FunctionDoesnotExist;

}

//short triggerFunction(int type, int function, int board) {
//  //      if (type == IP) {
//  //        return inputFunction(function,board);
//  //      }
//  if (type == OP) {
//    return outputFunction(function, board);
//  }
//  if (type == ST) {
//    return setFunction(function, board);
//  }
//}
