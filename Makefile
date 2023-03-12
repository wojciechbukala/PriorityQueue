APP= PriorityQueue
TEST= PriorityQueue_test

FLAGS= -c -g -Iinc -Wall -pedantic -iquote headers


__start__: ./PriorityQueue
	./PriorityQueue

test: ./PriorityQueue_test
	./PriorityQueue_test

./PriorityQueue: obj obj/main.o
./PriorityQueue_test: obj obj/test.o 

obj:
	mkdir obj

./${APP}: obj obj/main.o obj/Node.o obj/Queue.o
	g++ -o ./${APP} obj/main.o obj/Node.o obj/Queue.o

./${TEST}: obj obj/test.o obj/Node.o obj/Queue.o
	g++ -o ./${TEST} obj/test.o obj/Node.o obj/Queue.o


obj/main.o: project/main.cpp headers/Node.hpp headers/Queue.hpp
	g++  ${FLAGS} -o obj/main.o project/main.cpp

obj/test.o: project/test.cpp headers/Node.hpp headers/Queue.hpp
	g++  ${FLAGS} -o obj/test.o project/test.cpp

obj/Node.o: project/Node.cpp
	g++  ${FLAGS} -o obj/Node.o project/Node.cpp

obj/Queue.o: project/Queue.cpp
	g++  ${FLAGS} -o obj/Queue.o project/Queue.cpp

clean:
	rm -f obj/* ./${APP} ./${TEST}


help:
	@echo
	@echo " make        - compile and run your code"
	@echo " make clean  - delete products of compilation"
	@echo " make help   - displays help information"
	@echo