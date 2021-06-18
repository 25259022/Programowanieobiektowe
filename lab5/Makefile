
output: main.o menu.o file.o table.o
	g++ main.o file.o table.o menu.o -o output
	doxygen

main.o: main.cpp
	g++ -c main.cpp
	
menu.o: menu.cpp menu.h
	g++ -c menu.cpp
	
file.o: file.cpp file.o
	g++ -c file.cpp
	
table.o: table.cpp table.o
	g++ -c table.cpp
	
clean:
	rm *.o
