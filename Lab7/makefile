all: Lab07

CC = g++
target = Lab07

$(target): main.o function.o
	$(CC) main.o function.o -o $(target)

main.o: main.cpp func.h
	$(CC) -c main.cpp

function.o: function.cpp func.h
	$(CC) -c function.cpp

clean:
	rm *.o $(target)