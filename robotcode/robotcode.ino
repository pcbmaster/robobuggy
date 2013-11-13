enum { FORWARD=2, BACKWARD=3, LEFT=3, RIGHT=4 };

void setup(){
  pinMode(FORWARD, OUTPUT);
  pinMode(BACKWARD, OUTPUT);
  pinMode(LEFT, OUTPUT);
  pinMode(RIGHT, OUTPUT);
  Serial.begin(9600);
  Serial.write('!'); //Tell the Z2 that we are ready
}

void loop(){
  if(Serial.available()){
    char incoming = Serial.read();
    doMove(incoming);
  }
}

void doMove(char act){
  switch (act){
  case 'f': //Go forward
    allOff();
    digitalWrite(FORWARD, 1);
    digitalWrite(BACKWARD, 0);
    break;
  case 'b': //Go backward
    digitalWrite(FORWARD, 0);
    digitalWrite(BACKWARD, 1);
    break;
  case 'l': //steer left
    digitalWrite(LEFT, 1);
    digitalWrite(RIGHT, 0);
    break;
  case 'r': //steer right
    digitalWrite(LEFT, 0);
    digitalWrite(RIGHT, 1);
    break;
  case 'c': //center steering
    digitalWrite(LEFT, 0);
    digitalWrite(RIGHT, 0);
    break;
  case 'h': //halt
    digitalWrite(FORWARD, 0);
    digitalWrite(BACKWARD, 0);
    digitalWrite(LEFT, 0);
    digitalWrite(RIGHT, 0);
    break;
  default:
    break;
  }
}
