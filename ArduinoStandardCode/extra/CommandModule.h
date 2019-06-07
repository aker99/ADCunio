#include "generic.h"
//#include "input.h"
#include "output.h"
#include "set.h"

class CommandModule {
    byte type;
    byte function;
    byte board;
    
  public:
  
    CommandModule(byte type, byte function, byte board) {
      this->type = type;
      this->function = function;
      this->board = board;
    }
    
//    CommandModule() {      
//      byte board = SerialComm.readStringUntil('%').toInt() ;
//      byte type = SerialComm.readStringUntil('%').toInt() ;
//      byte function = SerialComm.readStringUntil('%').toInt() ;
//      this->type = type;
//      this->function = function;
//      this->board = board;
//    }
    
    int errorCheck() {

      if (board >= boardMAX)
        return FunctionWrong;

      if (type >= typeMAX)
        return TypeWrong;

      if (function >= noOfFunctionByType[type])
        return FunctionWrong;

      return RequestCompleted;
    }



    int getBoard(){
        return board;
      }
    int getType(){
        return type;
      }
    int getFunction(){
        return function;
      }
};
