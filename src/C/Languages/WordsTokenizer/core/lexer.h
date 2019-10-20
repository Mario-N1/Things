#ifndef LEXER_H
#define LEXER_H

typedef enum {
    Word
} TokenKind;

typedef struct {
    char* start;
    int size;
    TokenKind kind;
} Token;

typedef struct {
    Token* all;
    int size;
} Tokens;

Tokens* parse_tokens(char* source);

#endif
