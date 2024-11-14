all: reply_admin.o main.o
	g++ -o reply_admin reply_admin.o main.o
reply_admin.o: reply_admin.cc
	g++ -c -o reply_admin.o reply_admin.cc
main.o: main.cc
	g++ -c -o main.o main.cc
clean:
	rm reply_admin.o main.o reply_admin