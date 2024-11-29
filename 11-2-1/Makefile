all: calendar.o main.o
	g++ -o calendar calendar.o main.o
calendar.o: calendar.cc
	g++ -c -o calendar.o calendar.cc
main.o: main.cc
	g++ -c -o main.o main.cc
clean:
	rm calendar.o main.o calendar