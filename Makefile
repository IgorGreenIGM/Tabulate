### __MAKEFILE__ ###

CC = g++
CFLAGS = -Ofast -std=c++17
EXEC = ./bin/output.exe

all:$(EXEC)

$(EXEC): main.o Tabulate.o  
		$(CC) -o $(EXEC) $^ 

main.o:	src/main.cpp
		$(CC) -c $< $(CFLAGS)

Tabulate.o: src/Tabulate.cpp
		$(CC) -c $< $(CFLAGS)

clean:
		rm *.o

mrproper:
		rm -f $(EXEC)