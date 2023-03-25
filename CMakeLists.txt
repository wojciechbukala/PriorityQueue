cmake_minimum_required(VERSION 3.10)
project(PriorityQueue)

#set(CMAKE_CXX_STANDARD `17)

set(R receiver)
set(S sender)

set(SRC 
    receiver/Node.cpp
    receiver/PQueue.cpp
)

set(FLAGS -c -g -Iinc -Wall -pedantic -iquote headers)

add_executable(${R} receiver/main.cpp)
target_include_directories(${R} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)

add_executable(${S} sender/main.cpp)
target_include_directories(${S} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)


target_compile_options(${R} PRIVATE ${FLAGS})
target_compile_options(${S} PRIVATE ${FLAGS})
