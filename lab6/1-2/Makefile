all: animal.o main.o
	g++ -o animal animal.o main.o
animal.o: animal.cc
	g++ -c -o animal.o animal.cc
main.o: main.cc
	g++ -c -o main.o main.cc
clean:
	rm animal.o main.o animal