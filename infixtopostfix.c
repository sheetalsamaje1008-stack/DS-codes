#include <stdio.h>
#include <ctype.h>

#define SIZE 50
int top = -1;
char stack[SIZE];

void push(char elem) {
    stack[++top] = elem;
}

char pop() {
    return stack[top--];
}

int pre(char charsymbol) {
    if (charsymbol == '^')
        return 3;
    else if (charsymbol == '*' || charsymbol == '/')
        return 2;
    else if (charsymbol == '+' || charsymbol == '-')
        return 1;
    else
        return 0;
}

int main() {
    char infix[SIZE], postfix[SIZE], ch, elem;
    int i = 0, k = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    push('#');

    while ((ch = infix[k++]) != '\0') {
        if (ch == '(')
            push(ch);
        else if (isalnum(ch))
            postfix[i++] = ch;
        else if (ch == ')') {
            while (stack[top] != '(')
                postfix[i++] = pop();
            pop(); // remove '('
        } else {
            while (pre(stack[top]) >= pre(ch))
                postfix[i++] = pop();
            push(ch);
        }
    }

    while (stack[top] != '#')
        postfix[i++] = pop();

    postfix[i] = '\0';
    printf("Postfix expression = %s\n", postfix);

    return 0;
}
