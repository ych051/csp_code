all: classes.o main.o
	g++ -o classes classes.o main.o
classes.o: classes.cc
	g++ -c -o classes.o classes.cc
main.o: main.cc
	g++ -c -o main.o main.cc
clean:
	rm classes.o main.o classes