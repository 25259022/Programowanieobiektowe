
output: main.o menu.o pliki.o tablica.o
	g++ main.o pliki.o tablica.o menu.o -o output
	doxygen

main.o: main.cpp
	g++ -c main.cpp
	
menu.o: menu.cpp menu.h
	g++ -c menu.cpp
	
pliki.o: pliki.cpp pliki.o
	g++ -c pliki.cpp
	
tablica.o: tablica.cpp tablica.o
	g++ -c tablica.cpp
	
clean:
	rm *.o
