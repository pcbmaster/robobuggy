CC = g++
CFLAGS = -I . -g
LFLAGS = -lncurses
EXE = robocommand

all:
	$(CC) $(CFLAGS) -c serialib.cpp -o serialib.o $(LFLAGS)
	$(CC) $(CFLAGS) main.cpp serialib.o -o $(EXE) $(LFLAGS)
