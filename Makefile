FLAGS = -pedantic-errors -std=c++11

main: cards.o main.o
  g++ $(FLAGS) cards.o main.o -o main

cards.o: cards.cpp cards.h
	g++ $(FLAGS) -c cards.cpp

main.o: main.cpp cards.h
	g++ $(FLAGS) -c main.cpp

clean:
	rm -f main cards.o main.o main.tgz

tar:
	tar -czvf main.tgz *.cpp *.h

.PHONY: clean tar