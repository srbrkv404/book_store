cmake_minimum_required(VERSION 3.10)

project(BookStore)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(book book.cpp)
add_library(book_store  book_store.cpp)
add_executable(main main.cpp)

target_link_libraries(main book book_store)