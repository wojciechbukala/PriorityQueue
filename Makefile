APP_1 = Receiver
TEST_1= Receiver_test
APP_2 = Sender
TEST_2= Sender_test

FLAGS= -c -g -Iinc -Wall -pedantic -iquote headers


__start__: ./Receiver
	./Receiver

receiver: ./Receiver
	./Receiver

test_r: ./Receiver_test
	./Receiver_test

sender: ./Sender
	./Sender

test_s: ./Sender_test
	./Sender_test

./Receiver: r_obj r_obj/main.o
./Receiver_test: r_obj r_obj/test.o 
./Sender: s_obj s_obj/main.o
./Sender_test: s_obj s_obj/test.o

r_obj:
	mkdir r_obj

s_obj:
	mkdir s_obj

./${APP_1}: r_obj r_obj/main.o 
	g++ -o ./${APP_1} r_obj/main.o 

./${APP_2}: s_obj s_obj/main.o 
	g++ -o ./${APP_2} s_obj/main.o 

./${TEST_1}: r_obj r_obj/test.o
	g++ -o ./${TEST_1} r_obj/test.o

./${TEST_2}: s_obj s_obj/test.o
	g++ -o ./${TEST_2} s_obj/test.o


r_obj/main.o: receiver/main.cpp headers/Node.hpp headers/PQueue.hpp
	g++  ${FLAGS} -o r_obj/main.o receiver/main.cpp

r_obj/test.o: receiver/test.cpp headers/Node.hpp headers/PQueue.hpp
	g++  ${FLAGS} -o r_obj/test.o receiver/test.cpp

s_obj/main.o: sender/main.cpp
	g++  ${FLAGS} -o s_obj/main.o sender/main.cpp

s_obj/test.o: sender/test.cpp headers/Stack_node.hpp headers/Stack.hpp
	g++  ${FLAGS} -o s_obj/test.o sender/test.cpp


clean:
	rm -f r_obj/* ./${APP_1} ./${TEST_1} ./${TEST_2} ./${APP_2}


help:
	@echo
	@echo " make        - compile and run your code"
	@echo " make test   - compile and run test"
	@echo " make clean  - delete products of compilation"
	@echo " make help   - displays help information"
	@echo