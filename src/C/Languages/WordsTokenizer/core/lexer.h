#ifndef LEXER_H
#define LEXER_H

typedef enum {
    Word = 1,
    Number = 2,
    Dot = 3,
    Comma = 4,
    Colon = 5,
    Semicolon = 6,
    Question = 7,
    Exclamation = 8
} TokenKind;

typedef struct {
    TokenKind kind;
    char* start;
    int size;
} Token;

typedef struct {
    Token* all;
    int size;
} Tokens;

Tokens parse_tokens(char* source);

#endif
