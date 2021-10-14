cmake_minimum_required(VERSION 3.12)
project(IZ-1)

#set(CMAKE_C_CLANG_TIDY "clang-tidy;-header-filter=.;-checks=*;")
set(CMAKE_C_CPPCHECK "cppcheck")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=memory")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")

add_library(books STATIC books.c)

add_executable(main main.c)
target_link_libraries(main books)

add_compile_options("--coverage")
enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
add_executable(test_books test_books.cpp)
target_link_libraries(test_books ${GTEST_LIBRARIES} pthread gcov books)