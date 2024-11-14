all: print_member.o main.o
	g++ -o print_member print_member.o main.o
print_member.o: print_member.cc
	g++ -c -o print_member.o print_member.cc
main.o: main.cc
	g++ -c -o main.o main.cc
clean:
	rm print_member.o main.o print_member