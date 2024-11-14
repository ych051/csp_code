all: print_info.o main.o
	g++ -o print_info print_info.o main.o
print_info.o: print_info.cc
	g++ -c -o print_info.o print_info.cc
main.o: main.cc
	g++ -c -o main.o main.cc
clean:
	rm print_info.o main.o print_info