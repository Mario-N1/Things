#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

int inline is_eol(char x) {
    return x == '\0';
}

int inline is_digit(char x) {
    return x >= '0' && x <= '9';
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

Tokens parse_tokens(char* source) {
    Tokens tokens = {
        .all = 0,
        .size = 0
    };

    char* current = source;

    while (1) {
        char ch = *current;

        if (is_eol(ch)) {
            return tokens;
        }

        if (is_digit(ch)) {
            Token number = parse_number(current);
            append(&tokens, number);
        }

        current++;
    }

    return tokens;
}
