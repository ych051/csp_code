all: my_string.o main.o
	g++ -o string my_string.o main.o
my_string.o: my_string.cc
	g++ -c -o my_string.o my_string.cc
main.o: main.cc
	g++ -c -o main.o main.cc
clean:
	rm my_string.o main.o string