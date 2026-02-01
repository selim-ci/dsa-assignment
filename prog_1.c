#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

// check if brackets match
int isMatch(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '[' && close == ']') return 1;
    if (open == '{' && close == '}') return 1;
    return 0;
}

int isBalanced(char *expr) {
    top = -1;
    for (int i = 0; i < strlen(expr); i++) {
        char c = expr[i];
        if (c == '(' || c == '[' || c == '{') {
            push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty()) return 0;
            char o = pop();
            if (!isMatch(o, c)) return 0;
        }
    }
    return isEmpty();
}

int main() {
    char exprs[3][100] = {
        "a + (b - c) * (d",
        "m + [a - b * (c + d * {m)]",
        "a + (b - c)"
    };

    for (int i = 0; i < 3; i++) {
        printf("Expression: %s\n", exprs[i]);
        if (isBalanced(exprs[i]))
            printf("Result: Balanced\n\n");
        else
            printf("Result: Not Balanced\n\n");
    }

    return 0;
}
