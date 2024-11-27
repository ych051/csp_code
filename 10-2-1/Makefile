all: my_vector.o main.o
	g++ -o MyVector my_vector.o main.o
my_vector.o: my_vector.cc
	g++ -c -o my_vector.o my_vector.cc
main.o: main.cc
	g++ -c -o main.o main.cc
clean:
	rm my_vector.o main.o MyVector