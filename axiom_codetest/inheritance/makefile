CC = g++
DEPS = Fruit.hpp
TARGET = Fruit

Fruit: main.o Fruit.o
	$(CC) -o $(TARGET) main.o Fruit.o

main.o: main.cpp
	$(CC) -c main.cpp

Fruit.o: Fruit.cpp
	$(CC) -c Fruit.cpp

clean:
	rm -f *.o

