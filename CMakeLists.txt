cmake_minimum_required(VERSION 3.24)
project(331_proj1)
set(CMAKE_CXX_STANDARD 17)

include_directories(lib)

# main
add_executable(main main.cpp lib/DoublyLinkedList.cpp)

# testing
add_executable(tests tests/test.cpp lib/DoublyLinkedList.cpp)

# ----Catch2----

# target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

# --- FTXUI --------------------------------------------------------------
include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(
        ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
        GIT_TAG V4.0.0
        )

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
    FetchContent_Populate(ftxui)
    add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# ------------------------------------------------------------------------------

target_link_libraries(main
        PRIVATE ftxui::screen
        PRIVATE ftxui::dom
        PRIVATE ftxui::component # Not needed for this example.
        )