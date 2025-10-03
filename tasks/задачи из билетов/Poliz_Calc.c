#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int evalRPN(char *expr) {
    int stack[MAX], top = -1;
    for (int i = 0; expr[i]; i++) {
        if (isdigit(expr[i])) {
            stack[++top] = expr[i] - '0';
        } else if (expr[i] == ' ') {
            continue;
        } else {
            int b = stack[top--];
            int a = stack[top--];
            switch (expr[i]) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break;
            }
        }
    }
    return stack[top];
}

int main() {
    char expr[] = "5 7 + 7 *";
    printf("%d\n", evalRPN(expr));
    return 0;
}