all: Program
Program: main.o Book.o BookList.o
	g++ main.o Book.o BookList.o -o Program

main.o: main.cpp
	g++ -c main.cpp

Linked_List.o: Linked_List.cpp
	g++ -c Linked_List.cpp


Circular_Buffer.o: Circular_Buffer.cpp
	g++ -c Circular_Buffer.cpp

clean:
	rm -rf *o Program
