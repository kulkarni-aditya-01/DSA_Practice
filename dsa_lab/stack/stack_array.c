#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
int stack[MAX];
int top = -1;

void push(int x);
int pop();
void peek();
bool isEmpty();
bool isFull();

bool isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    return false;
}
bool isFull()
{
    if (top == MAX - 1)
    {
        return true;
    }
    return false;
}
void push(int key)
{
    if (!isFull()){
        top++;
        stack[top]=key;
        return ;
    }
    printf("Stack is the full :) ");
}
int pop(){
    if(!isEmpty()){
        int temp=stack[top];
        top--;
        return temp;
    }
    printf("Stack is the empty :)");
    return 0 ;
}
void peek(){
    if(!isEmpty()){
        printf("%d\n",stack[top]);
    }
    else {
        printf("Stack is the empty :)");
    }
}
void display(){
    if(!isEmpty()){
        int temp = top ;
        while(temp != -1){
            printf("%d ",stack[temp]);
            temp --;
        }
        printf("\n");
        return ;
    }
    printf("stack is the empty :) ");
}


int main()
{
    int choice;
    printf("Enter the choice 1:push()\t2:pop()\t3:peek()\t4:display()\t(-1 for exit the loop)");
    scanf(" %d", &choice);
    while (choice != -1)
    {
        switch (choice){
        case 1:{
            int keyi;
            printf("Enter the key to be push : ");
            scanf(" %d", &keyi);
            push(keyi);
            break;
        }
        case 2:{
            int keyd = pop();
            printf("%d\n", keyd);
            break;
        }
        case 3:{
            peek();
        }
        case 4:{
            display();
            break;
        }
    }
        printf("Enter the choice 1:push()\t2:pop()3:peek()\t4:display()\t(-1 for exit the loop)");
        scanf(" %d", &choice);
    }
    return 0;
}