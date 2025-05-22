#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
char stack[MAX];
int top=-1;

void push(char x);
char pop();
void reverse(char *exp);
bool isEmpty();
int precedence(char x);
void infix_to_prefix(char *exp);

bool isEmpty(){
    return top==-1;
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

char pop(){
    if(!isEmpty()){
        char temp = stack[top] ;
        if(temp == '('){
            return '\0' ;
        }
        top--;
        return temp ;
    }
    return '\0' ;
}

void push(char x){
    if(top == MAX -1){
        return ;
    }
    else {
        top++;
        stack[top] = x ;
    }
}

void reverse(char *exp){
   int len=strlen(exp);
   int strt=0;
   int end=len-1;
   while(strt < end){
        char temp ;
        temp=exp[strt];
        exp[strt]=exp[end];
        exp[end]=temp;
        strt++;
        end--;
   }
   exp[len]='\0' ;
}

void infix_to_prefix(char *exp){
    reverse(exp);
    printf("%s\n",exp);
    char *prefix ;
    prefix = (char *)malloc(sizeof(char )*MAX);
    for(int i=0 ; exp[i] != '\0' ; i++){
        if(exp[i] == ')'){
            exp[i] = '(';
        }
        else if(exp[i] == '('){
            exp[i] = ')';
        }
    }
    int j=0 ; 
    int n=0 ;
    while(exp[j] != '\0'){
        if(isalnum(exp[j])){
            prefix[n++] = exp[j] ;           
        }
        else if(exp[j] == '('){
            push(exp[j]) ;
        }
        else if(exp[j] == ')'){
            while(stack[top] != '('){
                prefix[n++] = pop();
            }
            prefix[j]=pop();
        }
        else {
            while(!isEmpty() && precedence(exp[j]) <= precedence(stack[top])){
                prefix[n++]=pop();
            }
            push(exp[j]);
        }
        j++;
    }
    while(top != -1){
        prefix[n++]=pop();
    }
    prefix[n]='\0' ;
    reverse(prefix);
    printf("%s ",prefix);
} 

int main(){
    char *exp ;
    exp=(char *)malloc(sizeof(char)*MAX);
    printf("Enter the expression : ");
    scanf(" %[^\n]s",exp);
    infix_to_prefix(exp);
    return 0;
}