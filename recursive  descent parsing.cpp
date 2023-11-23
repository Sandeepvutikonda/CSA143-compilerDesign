#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *input;
int pos = 0;
char current_token;

void error() {
    printf("Syntax error\n");
    exit(EXIT_FAILURE);
}

void advance() {
    current_token = input[pos++];
}

void eat(char token) {
    if (current_token == token)
        advance();
    else
        error();
}

int factor() {
    if (isdigit(current_token)) {
        int value = current_token - '0';
        advance();
        return value;
    } else if (current_token == '(') {
        eat('(');
        int result = expr();
        eat(')');
        return result;
    } else {
        error();
        return -1; // Error value
    }
}

int term() {
    int result = factor();
    while (current_token == '*' || current_token == '/') {
        char op = current_token;
        if (op == '*') {
            eat('*');
            result *= factor();
        } else {
            eat('/');
            int denominator = factor();
            if (denominator != 0)
                result /= denominator;
            else
                error(); // Division by zero
        }
    }
    return result;
}

int expr() {
    int result = term();
    while (current_token == '+' || current_token == '-') {
        char op = current_token;
        if (op == '+') {
            eat('+');
            result += term();
        } else {
            eat('-');
            result -= term();
        }
    }
    return result;
}

int main() {
    input = "3+4*2-(5/1)"; // Input expression
    current_token = input[0];

    int result = expr();
    printf("Result: %d\n", result);

    return 0;
}
