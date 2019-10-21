#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

int inline is_eol(char x) {
    return x == '\0';
}

int inline is_digit(char x) {
    return x >= '0' && x <= '9';
}

int inline is_letter(char x) {
    return x >= 'a' && x <= 'z' ||
           x >= 'A' && x <= 'Z';
}

void inline append(Tokens* tokens, Token token) {
    int size = sizeof(token);

    tokens->size += 1;
    tokens->all = realloc(tokens->all, sizeof(tokens->all) + size);

    *(tokens->all) = token;
}

Token inline parse_number(char* current) {
    char* start = current;
    int size = 0;

    while (1) {
        char ch = *current;

        if (!is_digit(ch))
            break;

        current++;
        size++;
    }

    return (Token) {
        .kind = Number,
        .start = start,
        .size = size
    };
}

Token inline parse_word(char *current) {
    char* start = current;
    int size = 0;

    while (1) {
        char ch = *current;

        if (!is_digit(ch))
            break;

        current++;
        size++;
    }

    return (Token) {
        .kind = Number,
        .start = start,
        .size = size
    };
}

#define parse_all(func, as) \
do {                        \
    size++;                 \
    current++;              \
    ch = *current;          \
} while (func(ch));         \
token = (Token) {           \
    .kind = as,             \
    .start = start,         \
    .size = size            \
};                          \
append(&tokens, token);     \

Tokens parse_tokens(char* source) {
    Tokens tokens = {
        .all = 0,
        .size = 0
    };

    char* current = source;
    char* start = current;

    char ch;
    int size;
    Token token;

    while (1) {
        start = current;
        ch = *start;
        size = 0;

        if (is_eol(ch)) {
            return tokens;
        }
        else if (is_digit(ch)) {
            parse_all(is_digit, Number);
        } else if (is_letter(ch)) {
            parse_all(is_letter, Word);
        } else {
          current++;
        }
    }

    return tokens;
}
