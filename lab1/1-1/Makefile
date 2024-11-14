all: hello_world.o 
	g++ -o hello_world hello_world.o
hello_world.o: hello_world.cc
	g++ -c -o hello_world.o hello_world.cc
clean:
	rm hello_world.o hello_world