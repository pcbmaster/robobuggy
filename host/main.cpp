/*///////////////////////////////////////// 
| Program to send control messages to the |
| Arduino and control the robot.          |
| Brett Monty 2013                        |
/////////////////////////////////////////*/

#include <stdlib.h>
#include "serialib.h"
#include <iostream>
#include <ncurses.h>

using namespace std;

int main(int argc, char* argv[]){
  if (argc < 2){
    cout << "No serial port defined! Exiting.\n";
    return -1;
  }
  else {
    initscr();
    timeout(128);
    noecho();
    char* port = argv[1];
    serialib s;
    int ret;
    char buf[128];
    ret = s.Open(port, 9600);
    if(ret != 1){
      printw("Failed to open port!\n");
      refresh();
      endwin();
      return ret;
    }
    printw("Port opened.\n");
    char in;
    /*
    while(in != '!'){
      s.WriteChar('?');
      in = s.Read(buf, 1, 150);
    }
    */
    while(in != 'q'){
      switch(getch()){
      case 'w': //up arrow key
	s.WriteChar('f');
	mvprintw(1,0,"Forward");
	break;
      case 's': //down arrow key
	s.WriteChar('b');
	mvprintw(1,0,"Backward");
	break;
      case 'd': //right arrow key
	s.WriteChar('r');
	mvprintw(1,0,"Forward Right");
	break;
      case 'a': //left arrow key
	s.WriteChar('l');
	mvprintw(1,0,"Forward Left");
	break;
      case ' ':
	s.WriteChar('h');
	mvprintw(1,0,"Brake");
	break;
      case 'q':
	s.WriteChar('b');
	s.WriteChar('l');
	mvprintw(1,0,"Backward Left");
	break;
      case 'e':
	s.WriteChar('b');
	s.WriteChar('r');
	mvprintw(1,0,"Backward Right");
	break;
      case 'p':
	in = 'q';
      default:
	mvprintw(1,0,"Idle      ");
      }
    }
      endwin();
      cout << "Exiting...\n";
  }
}
