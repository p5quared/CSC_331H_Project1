cmake_minimum_required(VERSION 3.25)
project(331_proj1)
set(CMAKE_CXX_STANDARD 17)

include_directories(lib)

# main
add_executable(main main.cpp lib/Node.h lib/DoublyLinkedList.h lib/DoublyLinkedList.cpp)

# testing
add_executable(tests tests/test.cpp lib/DoublyLinkedList.cpp)

# ----Catch2----
find_package(Catch2 3 REQUIRED)
include(Catch)
catch_discover_tests(tests)

# ------------------------------------------------------------------------------

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)