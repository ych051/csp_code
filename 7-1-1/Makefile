all: magic_square.o main.o
	g++ -o magic_square magic_square.o main.o
magic_square.o: magic_square.cc
	g++ -c -o magic_square.o magic_square.cc
main.o: main.cc
	g++ -c -o main.o main.cc
clean:
	rm magic_square.o main.o magic_square