#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"

int main() {
    char expression[MAX_EXPRESSION_LENGTH];
    printf("Enter the expression: ");
    fgets(expression, MAX_EXPRESSION_LENGTH, stdin);
    expression[strcspn(expression, "\n")] = 0; // �����з��滻����ֹ��

    double result = evaluateExpression(expression);
    printf("Result: %lf\n", result);

    return 0;
}
