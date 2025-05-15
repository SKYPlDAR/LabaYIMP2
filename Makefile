all: main

laba: main.o funcs.o
 g++ -o laba main.o funcs.o

main.o: main.cpp Z.h
 g++ -c main.cpp

funcs.o: funcs.cpp Z.h
 g++ -c funcs.cpp

clean:
 rm *.o

