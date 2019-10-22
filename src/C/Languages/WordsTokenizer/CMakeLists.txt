cmake_minimum_required(VERSION 3.15)
project(WordsTokenizer C)

set(CMAKE_C_STANDARD 11)

include_directories(common)
include_directories(core)

file(GLOB SOURCES "common/*.c")
file(GLOB SOURCES "core/*.c")

add_executable(WordsTokenizer ${SOURCES} main.c)
