all: vehicle.o main.o
	g++ -o vehicle vehicle.o main.o
vehicle.o: vehicle.cc
	g++ -c -o vehicle.o vehicle.cc
main.o: main.cc
	g++ -c -o main.o main.cc
clean:
	rm vehicle.o main.o vehicle