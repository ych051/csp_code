all: zebra.o main.o
	g++ -o zebra zebra.o main.o
zebra.o: zebra.cc
	g++ -c -o zebra.o zebra.cc
main.o: main.cc
	g++ -c -o main.o main.cc
clean:
	rm zebra.o main.o zebra