#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

char cstack[MAX];
int ctop = -1;

double nstack[MAX];
int ntop = -1;

void cpush(char c) { cstack[++ctop] = c; }
char cpop() { return cstack[ctop--]; }
char cpeek() { return cstack[ctop]; }
int cisEmpty() { return ctop == -1; }

void npush(double v) { nstack[++ntop] = v; }
double npop() { return nstack[ntop--]; }

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// convert infix to postfix
void infixToPostfix(char *infix, char *postfix) {
    ctop = -1;
    int k = 0;
    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];
        if (c == ' ') continue;

        if (isdigit(c)) {
            postfix[k++] = c;
            postfix[k++] = ' ';
        } else if (c == '(') {
            cpush(c);
        } else if (c == ')') {
            while (!cisEmpty() && cpeek() != '(')
                postfix[k++] = cpop(), postfix[k++] = ' ';
            cpop(); // remove '('
        } else if (isOperator(c)) {
            while (!cisEmpty() && precedence(cpeek()) >= precedence(c) && c != '^')
                postfix[k++] = cpop(), postfix[k++] = ' ';
            cpush(c);
        }
    }
    while (!cisEmpty())
        postfix[k++] = cpop(), postfix[k++] = ' ';
    postfix[k] = '\0';
}

double evaluate(char *postfix) {
    ntop = -1;
    for (int i = 0; i < strlen(postfix); i++) {
        char c = postfix[i];
        if (isdigit(c)) {
            npush(c - '0');
        } else if (isOperator(c)) {
            double b = npop(), a = npop();
            if (c == '+') npush(a + b);
            else if (c == '-') npush(a - b);
            else if (c == '*') npush(a * b);
            else if (c == '/') npush(a / b);
            else if (c == '^') npush(pow(a, b));
        }
    }
    return npop();
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression (single digit numbers only): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    printf("Result: %.2f\n", evaluate(postfix));

    return 0;
}
