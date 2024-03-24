#pragma once

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_EXPRESSION_LENGTH 100

// ����ԭ��
double evaluateExpression(const char* expression);
double evaluateTerm(const char* expression, char** endptr);
double evaluateFactor(const char* expression, char** endptr);
double evaluateNumber(const char* expression, char** endptr);

// ������ʽ�ĺ���
double evaluateExpression(const char* expression) {
    char* endptr;
    double result;

    result = strtod(expression, &endptr);

    // ����Ƿ���ת�������ַ���
    if (endptr == expression + strlen(expression))
        return result;

    // ���򣬼�����ʽ 
    result = evaluateTerm(expression, &endptr);

    return result;
}

// ����Ӽ��ĺ���
double evaluateTerm(const char* expression, char** endptr) {
    double result = evaluateFactor(expression, endptr);

    while (**endptr == '+' || **endptr == '-') {
        char operator = **endptr;
        (*endptr)++;

        double nextFactor = evaluateFactor(*endptr, endptr);

        if (operator == '+')
            result += nextFactor;
        else
            result -= nextFactor;
    }

    return result;
}

// ����˳��ĺ��� 
double evaluateFactor(const char* expression, char** endptr) {
    double result = evaluateNumber(expression, endptr);

    while (**endptr == '*' || **endptr == '/') {
        char operator = **endptr;
        (*endptr)++;

        double nextNumber = evaluateNumber(*endptr, endptr);

        if (operator == '*')
            result *= nextNumber;
        else if (nextNumber != 0)
            result /= nextNumber;
        else {
            printf("Error: Division by zero!\n");
            exit(EXIT_FAILURE);
        }
    }

    return result;
}

// ���ȼ��������ڵ����ֵĺ���
double evaluateNumber(const char* expression, char** endptr) {
    double result;

    if (*expression == '(') {
        (*endptr) = strchr(expression, ')');
        if (*endptr == NULL) {
            printf("Error: Invalid expression!\n");
            exit(EXIT_FAILURE);
        }
        *endptr += 1; // ��ָ�� endptr ָ��ĵ�ַ�����ƶ�һ���ַ�λ��

        char subExpression[MAX_EXPRESSION_LENGTH];
        strncpy(subExpression, expression + 1, (*endptr - expression) - 2);
        subExpression[(*endptr - expression) - 2] = '\0';

        result = evaluateExpression(subExpression);
    }
    else {
        result = strtod(expression, endptr);
    }

    return result;
}

#endif 

