cmake_minimum_required(VERSION 3.25)
project(331_proj1)
set(CMAKE_CXX_STANDARD 20)

# Assemble Library
add_library(linkedList STATIC ${CMAKE_SOURCE_DIR}/lib/DoublyLinkedList.cpp)
target_include_directories(linkedList PUBLIC ${CMAKE_SOURCE_DIR}/lib/include)

# Setup main
add_executable(main main.cpp)
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/lib/include)
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/lib)
target_link_libraries(main PRIVATE linkedList)

# Setup Testing
add_executable(tests ${CMAKE_SOURCE_DIR}/tests/test.cpp)
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/lib/include)
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/lib)

find_package(Catch2 3 REQUIRED)
include(Catch)
catch_discover_tests(tests)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(tests PRIVATE linkedList)
