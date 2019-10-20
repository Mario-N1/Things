#include <stdio.h>
#include "core/lexer.h"

int main(int args_count, char** args) {
    Tokens tokens = parse_tokens("A1B2C3");
    Token x = *(tokens.all);

    printf("%d", x.size);
    printf("%d", x.kind);

    return 0;
}
