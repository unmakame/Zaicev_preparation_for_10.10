#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int evalRPN(char *expr) {
    int stack[MAX], top = -1;
    for (int i = 0; expr[i]; i++) {
        if (isdigit((unsigned char)expr[i])) {
            stack[++top] = expr[i] - '0';
        } else if (expr[i] == ' ') {
            continue;
        } else {
            if (top < 1) {
                fprintf(stderr, "Error: stack underflow at position %d\n", i);
                return 0;
            }
            int b = stack[top--];
            int a = stack[top--];
            switch (expr[i]) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/':
                    if (b == 0) {
                        fprintf(stderr, "Error: division by zero at position %d\n", i);
                        return 0;
                    }
                    stack[++top] = a / b; break;
                default:
                    fprintf(stderr, "Warning: unknown operator '%c' at position %d\n", expr[i], i);
                    break;
            }
        }
    }
    if (top != 0) {
        fprintf(stderr, "Warning: stack has %d elements after evaluation (expected 1)\n", top + 1);
    }
    return stack[top];
}

int main() {
    char expr[] = "5 7 + 7 *";
    printf("%d\n", evalRPN(expr));
    return 0;
}