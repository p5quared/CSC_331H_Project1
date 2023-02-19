cmake_minimum_required(VERSION 3.25)
project(331_proj1)
set(CMAKE_CXX_STANDARD 17)

include_directories(lib)

# main
add_executable(main main.cpp lib/DoublyLinkedList.cpp)

# testing
add_executable(tests tests/test.cpp lib/DoublyLinkedList.cpp)

# ----Catch2----
find_package(Catch2 3 REQUIRED)
include(Catch)
catch_discover_tests(tests)

# ------------------------------------------------------------------------------

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)


# --- FTXUI --------------------------------------------------------------
include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
        # Important: Specify a GIT_TAG XXXXX here.
        )

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
    FetchContent_Populate(ftxui)
    add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# ------------------------------------------------------------------------------

project(main
        LANGUAGES CXX
        VERSION 1.0.0
        )

target_link_libraries(main
        PRIVATE ftxui::screen
        PRIVATE ftxui::dom
        PRIVATE ftxui::component # Not needed for this example.
        )