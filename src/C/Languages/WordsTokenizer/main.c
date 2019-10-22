#include <stdio.h>
#include "core/lexer.h"

int main() {
    Tokens tokens = parse_tokens("Abc 1 abc!.");

    print_tokens(tokens);

    return 0;
}
