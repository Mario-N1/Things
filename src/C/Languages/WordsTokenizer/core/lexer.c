#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

int inline is_eol(char x) {
    return x == '\0';
}

int inline is_separator(char x) {
    return
        x == ' ' ||
        x == '.' ||
        x == ',' ||
        x == ';' ||
        x == ':' ||
        x == '!' ||
        x == '?' ||
        x == '\0';
}

int inline is_space(char x) {
    return x == ' ';
}

int inline is_digit(char x) {
    return x >= '0' && x <= '9';
}

int inline is_letter(char x) {
    return (x >= 'a' && x <= 'z') ||
           (x >= 'A' && x <= 'Z');
}

Token inline new(TokenKind kind, char* start, int size) {
    return (Token) {
        .kind = kind,
        .start = start,
        .size = size
    };
}

void inline append(Tokens* tokens, Token token) {
    int size = sizeof(token);

    tokens->size += 1;
    tokens->all = realloc(tokens->all, sizeof(tokens->all) + size);

    *(tokens->all) = token;
}

#define iterate() size++; current++; ch = *current;
#define create_token(kind) token = (Token) { kind, start, size };

#define parse(kind, _while, _until)\
while(1)\
{\
    iterate();\
    if (_until(ch)) {\
        create_token(kind);\
        append(&tokens, token);\
        break;\
    }\
    if (!_while(ch)) {\
        return tokens;\
    }\
};\

#define for_all(x) x
#define until(x) x

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
        } else if (is_space(ch)) {
            current++;
        } else if (is_digit(ch)) {
            parse(Number, for_all(is_digit), until(is_separator));
        } else if (is_letter(ch)) {
            parse(Word, for_all(is_letter), until(is_separator));
        } else {
          current++;
        }
    }

    return tokens;
}
