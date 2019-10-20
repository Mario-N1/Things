cmake_minimum_required(VERSION 3.15)
project(WordsTokenizer C)

set(CMAKE_C_STANDARD 11)

include_directories(common)

add_executable(WordsTokenizer
        common/cursor.c
        common/cursor.h
        core/lexer.h
        core/lexer.c
        main.c)
