all: setfunc.o main.o
	g++ -o simple_int_set setfunc.o main.o
setfunc.o: setfunc.cc
	g++ -c -o setfunc.o setfunc.cc
main.o: main.cc
	g++ -c -o main.o main.cc
clean:
	rm setfunc.o main.o simple_int_set