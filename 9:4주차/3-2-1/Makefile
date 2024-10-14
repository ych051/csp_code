all: accounts.o main.o
	g++ -o simple_account accounts.o main.o
accounts.o: accounts.cc
	g++ -c -o accounts.o accounts.cc
main.o: main.cc
	g++ -c -o main.o main.cc
clean:
	rm accounts.o main.o simple_account