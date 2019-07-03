#include "libraries/ArduinoJson-v6.11.0.h"
#define SerialComm Serial

StaticJsonDocument<200> commandJson;

#include "enums.h"
#include "generic.h"
//#include "input.h"
#include "output.h"
#include "set.h"

void setup() {
  SerialComm.begin(115200);
}

void serialEvent() {
      char commandString[100];
      SerialComm.readString().toCharArray(commandString,100);
      //SerialComm.println(commandString);
      DeserializationError error = deserializeJson(commandJson,commandString) ;
      
          if (error) {
      //Serial.print(F("deserializeJson() failed: "));
      Serial.println(JSONFormatWrong);
    return;
  }
      SerialComm.print(start());
     
}
short start(){
  
     short board = boardValidation(commandJson["board"]) ;
      if (board < 0)
        return board;
        
      short type = typeValidation(commandJson["functionType"]) ;
      if (type < 0)
        return type;
      
      short function = functionValidation(type,commandJson["function"]) ;
      if (function < 0)
        return function;
        
      return triggerFunction(type, function, board);
  }
  
short triggerFunction(int type, int function, int board) {
  //      if (type == IP) {
  //        return inputFunction(function,board);
  //      }
  if (type == OP) {
    return outputFunction(function, board);
  }
  if (type == ST) {
    return setFunction(function, board);
  }
}

void loop(){}
