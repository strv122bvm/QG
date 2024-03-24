#pragma once

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_EXPRESSION_LENGTH 100

// 函数原型
double evaluateExpression(const char* expression);
double evaluateTerm(const char* expression, char** endptr);
double evaluateFactor(const char* expression, char** endptr);
double evaluateNumber(const char* expression, char** endptr);

// 计算表达式的函数
double evaluateExpression(const char* expression) {
    char* endptr;
    double result;

    result = strtod(expression, &endptr);

    // 检查是否已转换整个字符串
    if (endptr == expression + strlen(expression))
        return result;

    // 否则，计算表达式 
    result = evaluateTerm(expression, &endptr);

    return result;
}

// 计算加减的函数
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

// 计算乘除的函数 
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

// 优先计算括号内的数字的函数
double evaluateNumber(const char* expression, char** endptr) {
    double result;

    if (*expression == '(') {
        (*endptr) = strchr(expression, ')');
        if (*endptr == NULL) {
            printf("Error: Invalid expression!\n");
            exit(EXIT_FAILURE);
        }
        *endptr += 1; // 将指针 endptr 指向的地址往后移动一个字符位置

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

