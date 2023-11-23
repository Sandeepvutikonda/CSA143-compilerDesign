#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 100

int isOperator(char ch);
int getPrecedence(char op);
double performOperation(double operand1, double operand2, char op);
double parseExpression(char *expression);

int main() {
    char expression[100];
    printf("Enter an arithmetic expression: ");
    scanf("%s", expression);
    double result = parseExpression(expression);
    printf("Result: %lf\n", result);

    return 0;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int getPrecedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0; 
}

double performOperation(double operand1, double operand2, char op) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0) {
                return operand1 / operand2;
            } else {
                printf("Error: Division by zero\n");
                exit(EXIT_FAILURE);
            }
        case '^':
            return pow(operand1, operand2);
        default:
            printf("Error: Unknown operator\n");
            exit(EXIT_FAILURE);
    }
}

double parseExpression(char *expression) {
    double stackOperand[MAX_SIZE];
    char stackOperator[MAX_SIZE];
    int operandTop = -1, operatorTop = -1;

    int i = 0;
    while (expression[i] != '\0') {
        if (isdigit(expression[i]) || (expression[i] == '-' && (i == 0 || !isdigit(expression[i - 1])))) {
            operandTop++;
            stackOperand[operandTop] = atof(expression + i);
            while (isdigit(expression[i]) || expression[i] == '.') {
                i++;
            }
        } else if (isOperator(expression[i])) {
            while (operatorTop >= 0 && getPrecedence(stackOperator[operatorTop]) >= getPrecedence(expression[i])) {
                double operand2 = stackOperand[operandTop];
                operandTop--;
                double operand1 = stackOperand[operandTop];
                stackOperand[operandTop] = performOperation(operand1, operand2, stackOperator[operatorTop]);
                operatorTop--;
            }
            operatorTop++;
            stackOperator[operatorTop] = expression[i];
            i++;
        } else if (expression[i] == '(') {
            operatorTop++;
            stackOperator[operatorTop] = expression[i];
            i++;
        } else if (expression[i] == ')') {
            while (operatorTop >= 0 && stackOperator[operatorTop] != '(') {
                double operand2 = stackOperand[operandTop];
                operandTop--;
                double operand1 = stackOperand[operandTop];
                stackOperand[operandTop] = performOperation(operand1, operand2, stackOperator[operatorTop]);
                operatorTop--;
            }
            if (operatorTop >= 0 && stackOperator[operatorTop] == '(') {
                operatorTop--;
            } else {
                printf("Error: Mismatched parentheses\n");
                exit(EXIT_FAILURE);
            }
            i++;
        } else {
            i++;
        }
    }

    while (operatorTop >= 0) {
        double operand2 = stackOperand[operandTop];
        operandTop--;
        double operand1 = stackOperand[operandTop];
        stackOperand[operandTop] = performOperation(operand1, operand2, stackOperator[operatorTop]);
        operatorTop--;
    }

    return stackOperand[operandTop];
}
