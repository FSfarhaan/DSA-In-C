// A program to check the validity of Parenthesis in an expression. 

#include <stdio.h>
#include <stdlib.h>

char stack[50];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    char stackTop = stack[top--];
    return stackTop;
}

int isMatch(char a, char b) {
    if((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}')) return 1;
    return 0;
}

int isEmpty() {
    if(top == -1) return 1;
    return 0;
}

int main() {
    char exp[50] = "8+{[}9[1-3{45+34}]-[12+2{4}]";

    for(int i = 0; exp[i] != '\0'; i++) {
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{'){
            push(exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if(isEmpty()) {
                printf("The expression is not valid\n");
                exit(0);
            } 
            char stackTop = pop();
            if(!isMatch(stackTop, exp[i])) {
                printf("The expression is not valid\n");
                exit(0);
            }
        }
    }
    
    if(top == -1) printf("The expression is valid\n");
    else  printf("The expression is not valid\n");

    return 0;
}