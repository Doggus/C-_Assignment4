CC=g++
LIBS=-lm

main: main.o Image.o
	$(CC) -o imageops main.o Image.o  -std=c++11

main.o: main.cpp
	$(CC) -c main.cpp -std=c++11

Image.o: Image.h Image.cpp
	$(CC) -c Image.cpp -std=c++11

run:
	./imageops


test: UnitTests.cpp
	$(CC) -o UnitTests UnitTests.cpp Image.cpp -std=c++11

runTest:
	./UnitTests
