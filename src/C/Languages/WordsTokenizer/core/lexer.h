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

#endif
