
enum Board{
    uno=1,
    nano,
    mega,
    boardMAX
  };
  
enum type {
  IP=1, // Incase of input based command
  OP,// Incase of output based command
  ST, // Incase of setting digital pins
  typeMAX
};

enum input { //function list
  DR=1, // DigitalRead
  AR, // AnalogRead
  inputMAX
};

enum output {  //function list
  DW=1, // DigitalWrite
  AW, // AnalogWrite
  outputMAX
};
enum set {  //function list
  PM=1, // pinMode
  setMAX
};
enum pinmode {
  Input=1,
  Output,
  Input_pullup
};

enum StatusCode {
  RequestCompleted = -1,
  
  //JSON Error
  JSONFormatWrong = RequestCompleted -1,
  //Board Errors
  BoardDoesnotExist = JSONFormatWrong-1,
  BoardNotProvided = BoardDoesnotExist -1,
  //Type Errors
  TypeDoesnotExist = BoardNotProvided-1,
  TypeNotProvided = TypeDoesnotExist -1,
  
  //Function Errors
  FunctionDoesnotExist = TypeNotProvided-1,
  FunctionNotProvided = FunctionDoesnotExist -1,
  
  //Pin Errors
  PinCantPerformGivenOperation = FunctionNotProvided-1,
  PinNotProvided = PinCantPerformGivenOperation -1,
  PinDoesnotExistOnBoard = PinNotProvided -1,
  
  //Value Errors
  ValueNotSupported = PinDoesnotExistOnBoard-1,
  ValueNotProvided = ValueNotSupported -1
};


const byte noOfFunctionByType[typeMAX]={inputMAX,outputMAX,setMAX};
const byte noOfDigitalPinsByBoard[boardMAX]={14,14,55};
const byte noOfAnalogPinsByBoard[boardMAX]={6,8,16};
//
//byte *pinAllowedByFunction[TYPEMAX];
//
//for(byte i=0;i<typeEND;i++)
//  pinAllowedByFunction[i]= new byte[noOfFunctionByType]
