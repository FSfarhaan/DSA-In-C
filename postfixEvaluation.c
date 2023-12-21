#include <stdio.h>
#include <ctype.h>
#define MAX 50

int stack[MAX];
int top = -1;

void push(int num) {
    stack[++top] = num;
}
int pop() {
    return stack[top--];
}
 
int main() {
    char postFix[MAX] = "56*45+-"; // (5 * 6) - (4 + 5) = 21; 

    int i = 0;
    while(postFix[i] != '\0') {
        if(isdigit((int)postFix[i])){
            push(postFix[i] - '0'); // Converting character to int while pushing;
            i++;
        }
        else {
            int num1, num2, result;
            num2 = pop(); num1 = pop();
            switch (postFix[i]) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                result = num1 / num2;
                break;
            default:
                break;
            }
            push(result);
            i++;
        }
    }

    printf("The result is %d", pop());

    return 0;
}