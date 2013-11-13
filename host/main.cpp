/*///////////////////////////////////////// 
| Program to send control messages to the |
| Arduino and control the robot.          |
| Brett Monty 2013                        |
/////////////////////////////////////////*/

#include <stdlib.h>
#include "seriallib.h"
#include <iostream>
#include <conio>

int main(int argc, char* argv[]){
  if (argc < 1){
    cout << "No serial port defined! Exiting.\n";
    return -1;
  }
  else {
    char* port = argv[1];
    seriallib s;
    int ret;
    char buf[128];
    ret = s.Open(port, 9600);
    if(ret != 1){
      cout << "Failed to open " + port + "!\n";
      return ret;
    }
    cout << "Port " + port + " opened.\n";
  }
}
