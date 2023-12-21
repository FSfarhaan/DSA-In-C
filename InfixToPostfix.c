// Program to convert Infix expression to Postfix expression using Stack;

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[10];
int top = -1;

int isOperator(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/') return 1;
    return 0;
}

void push(char c){
    stack[++top] = c;
}

int precedency(char c) {
    if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return 0;
}

char pop() {
    char c = stack[top--];
    return c;
}

int main() {
    char infixExp[10] = "a*b-c*d";
    char postfixExp[10];

    int i = 0, j = 0;
    while(infixExp[i] != '\0') {
        if(!isOperator(infixExp[i])) {
            postfixExp[j] = infixExp[i];
            i++; j++;
        }
        else if(isOperator(infixExp[i])) {
            if(precedency(infixExp[i]) > precedency(stack[top])) {
                push(infixExp[i]);
                i++;
            } 
            else {
                postfixExp[j] = pop();
                j++;
            }
        }
    }
    while(top != -1) {
        postfixExp[j] = stack[top--];
        j++;
    }

    // To make postfixExp a valid string, this has to be added in the end.
    postfixExp[j] = '\0';
    
    printf("%s", infixExp);
    printf("\n");
    printf("%s", postfixExp);    

    return 0;
}