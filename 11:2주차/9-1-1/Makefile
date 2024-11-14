all: message.o main.o
	g++ -o message_book message.o main.o
message.o: message.cc
	g++ -c -o message.o message.cc
main.o: main.cc
	g++ -c -o main.o main.cc
clean:
	rm message.o main.o message_book