#include <stdio.h>
#include "core/lexer.h"

int main(int args_count, char** args) {
    Tokens tokens = parse_tokens("Abc 1 abc!.");
    Token x = *(tokens.all);

    printf("%d", tokens.size);

    return 0;
}
