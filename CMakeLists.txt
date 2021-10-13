cmake_minimum_required(VERSION 3.12)
project(IZ-1)

add_library(books STATIC books.c)

add_executable(main main.c)
target_link_libraries(main books)

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
add_executable(test_books test_books.cpp)
target_link_libraries(test_books ${GTEST_LIBRARIES} pthread books)