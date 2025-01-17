#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

#define or else
#define is ==
#define when(x) x
#define to(x) x

#define iterate() size++; current++; ch = *current;
#define create_token(kind) token = (Token) { kind, start, size };

#define parse_all_as(kind, when_)\
    if (when_(ch)) {\
        while(1)\
        {\
            iterate();\
            if (is_separator(ch)) {\
                create_token(kind);\
                append(token, to(&tokens));\
                break;\
            }\
            if (!when_(ch)) {\
                return tokens;\
            }\
        };\
    }

#define parse_one_as(kind, when_)\
    if (when_) {\
        iterate();\
        create_token(kind);\
        append(token, to(&tokens));\
    }

#define skip(when_)\
    if (when_) {\
        current++;\
    }

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

void inline append(Token token, Tokens* tokens) {
    int size = sizeof(token);

    tokens->size += 1;
    tokens->all = realloc(tokens->all, sizeof(tokens->all) + size);

    *(tokens->all + tokens->size - 1) = token;
}

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

        or skip(when(ch == ' '))

        or parse_all_as(Number,      when(is_digit))
        or parse_all_as(Word,        when(is_letter))

        or parse_one_as(Dot,         when(ch is '.'))
        or parse_one_as(Comma,       when(ch is ','))
        or parse_one_as(Colon,       when(ch is ':'))
        or parse_one_as(Semicolon,   when(ch is ';'))
        or parse_one_as(Question,    when(ch is '?'))
        or parse_one_as(Exclamation, when(ch is '!'))

        or {
            current++;
        }
    }

    return tokens;
}

void print_token(Token token) {
    printf("kind: %d | ", token.kind);

    for (int i = 0; i < token.size; i++) {
        char ch = *(token.start + i);
        putchar(ch);
    }
}

void print_tokens(Tokens tokens) {
    for (int i = 0; i < tokens.size; i++) {
        Token token = *(tokens.all + i);

        printf("[ ");
        print_token(token);
        printf(" ]");

        if (i != tokens.size - 1)
            printf(" ");
    }
}

