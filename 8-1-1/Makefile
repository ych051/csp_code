all: integer_set.o main.o
	g++ -o integer_set integer_set.o main.o
integer_set.o: integer_set.cc
	g++ -c -o integer_set.o integer_set.cc
main.o: main.cc
	g++ -c -o main.o main.cc
clean:
	rm integer_set.o main.o integer_set