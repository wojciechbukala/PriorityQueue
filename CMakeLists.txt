cmake_minimum_required(VERSION 3.10)
project(PriorityQueue)

set(CMAKE_CXX_STANDARD 17)

set(R receiver)
set(S sender)

set(SRC 
    receiver/Node.cpp
    receiver/PQueue.cpp
)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
set(FLAGS -c -g -Iinc -Wall -pedantic -iquote headers)


add_executable(${R} receiver/main.cpp)
target_include_directories(${R} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)

add_executable(${S} sender/main.cpp)
target_include_directories(${S} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)

enable_testing()

add_executable(
  priority_queue_test
  test/test_priority_queue.cpp
)
target_link_libraries(
  priority_queue_test
  GTest::gtest_main
)
target_include_directories(
    priority_queue_test PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
)

add_executable(
  test_time
  test/test_chrono.cpp
)

target_include_directories(
    test_time PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
)

include(GoogleTest)
gtest_discover_tests(priority_queue_test)



target_compile_options(${R} PRIVATE ${FLAGS})
target_compile_options(${S} PRIVATE ${FLAGS})

