#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_IDENTIFIER_LENGTH 50
#define MAX_CONSTANT_LENGTH 20

typedef enum {
    IDENTIFIER,
    CONSTANT,
    OPERATOR,
    INVALID
} TokenType;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool isValidIdentifierChar(char c) {
    return (isalnum(c) || c == '_');
}

TokenType getTokenType(char *token) {
    size_t len = strlen(token);
    if (len == 1 && isOperator(token[0])) {
        return OPERATOR;
    } else if (isdigit(token[0])) {
        bool isConstant = true;
        size_t i;
        for (i = 1; i < len; ++i) {
            if (!isdigit(token[i])) {
                isConstant = false;
                break;
            }
        }
        return isConstant ? CONSTANT : INVALID;
    } else if (isalpha(token[0]) || token[0] == '_') {
        size_t i;
        for (i = 1; i < len; ++i) {
            if (!isValidIdentifierChar(token[i])) {
                return INVALID;
            }
        }
        return IDENTIFIER;
    }
    return INVALID;
}

void processToken(char *token) {
    TokenType type = getTokenType(token);
    switch (type) {
        case IDENTIFIER:
            printf("Identifier: %s\n", token);
            break;
        case CONSTANT:
            printf("Constant: %s\n", token);
            break;
        case OPERATOR:
            printf("Operator: %s\n", token);
            break;
        default:
            printf("Invalid token: %s\n", token);
            break;
    }
}

void lexer(char *input) {
    char token[MAX_CONSTANT_LENGTH];
    size_t tokenIndex = 0;

    size_t i;
    for (i = 0; input[i] != '\0'; ++i) {
        if (isspace(input[i])) {
            if (tokenIndex > 0) {
                token[tokenIndex] = '\0';
                processToken(token);
                tokenIndex = 0;
            }
            continue;
        } else if (isOperator(input[i])) {
            if (tokenIndex > 0) {
                token[tokenIndex] = '\0';
                processToken(token);
                tokenIndex = 0;
            }
            token[0] = input[i];
            token[1] = '\0';
            processToken(token);
        } else {
            token[tokenIndex++] = input[i];
        }
    }

    if (tokenIndex > 0) {
        token[tokenIndex] = '\0';
        processToken(token);
    }
}

int main() {
    char input[] = "x = 10 + y * 5"; // Modify the input here
    lexer(input);
    return 0;
}
