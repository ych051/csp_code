all: my_clock.o main.o
	g++ -o my_clock my_clock.o main.o
my_clock.o: my_clock.cc
	g++ -c -o my_clock.o my_clock.cc
main.o: main.cc
	g++ -c -o main.o main.cc
clean:
	rm my_clock.o main.o my_clock