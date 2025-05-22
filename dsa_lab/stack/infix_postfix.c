#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
char stack[MAX];
int top = -1;

void push(char x);
void pop();
bool isEmpty();
bool isFull();
void display(char *exp);
void infix_to_postfix(char *exp);
int precedence(char x);

void display(char *exp){
    if(exp == NULL){
        return ;
    }
    printf("%s\n",exp);
}

int precedence(char x){
    switch(x){
        case '+' :
        case '-' :
        return 1 ;
        case '*' :  
        case '/' :
        return 2;
        case '^' :
        return 3;
    }
}

bool isEmpty(){
    return (top == -1) ;
} 
bool isFull(){
    return (top == MAX-1);
}

void push(char x)
{
    if (top == MAX - 1)
    {
        printf("stack is full : ");
        return ;
    }
    top++;
    stack[top]=x ;
}
void pop(){
    if(!isEmpty()){
        if(stack[top] == '('){
            top--;
            return ;
        }
        printf("%c",stack[top]);
        top--;
    }
    // else {
    //     printf("Stack is empty :) ");
    // }
}


void infix_to_postfix(char *exp)
{
    int i = 0;
    while (exp[i] != '\0')
    {
        if (isalnum(exp[i]))
        {
            printf("%c", exp[i]);
        }
        // else if(isEmpty() || staack[top] == '{'){
        //     push(exp[i]);
        // }
        else if (exp[i] == '(')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (!isEmpty() && stack[top] != '(')
            {
                pop();
            }
            pop();
        }
        else
        {
            while (!isEmpty() && precedence(exp[i]) < precedence(stack[top]))
            {
                pop();
            }
            while (!isEmpty() && precedence(exp[i]) == precedence(stack[top]))
            {
                if (stack[top] == '+' || stack[top] == '-' || stack[top] == '/' || stack[top] == '*')
                {
                    pop();
                }
                else
                {
                    push(exp[i]);
                }
            }
            push(exp[i]);
        }
        i++;
    }
    while(top != -1){
        pop();
    }
}

int main()
{
    char *exp;
    exp = (char *)malloc(sizeof(char) * MAX);
    printf("Enter the expression : ");
    scanf(" %s", exp);
    printf("User enter the expression : ");
    display(exp);
    printf("Postfix exp : ");
    infix_to_postfix(exp);
    return 0;
}