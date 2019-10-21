#ifndef LEXER_H
#define LEXER_H

typedef enum {
    Word = 1,
    Number = 2,
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
