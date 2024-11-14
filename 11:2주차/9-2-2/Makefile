all: sorted.o main.o
	g++ -o sorted_array sorted.o main.o
sorted.o: sorted.cc
	g++ -c -o sorted.o sorted.cc
main.o: main.cc
	g++ -c -o main.o main.cc
clean:
	rm sorted.o main.o sorted_array