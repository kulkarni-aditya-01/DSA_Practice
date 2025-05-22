#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
struct stack{
    char name[20];
    struct stack *next ;
} ;
struct stack *top=NULL;

void push(char *name);
char *pop();
void peek();

void push(char *name_p){
    struct stack *newnode ;
    newnode = (struct stack *)malloc(sizeof(struct stack ));
    strcpy(newnode->name, name_p);
    newnode -> next = top ;
    top = newnode ;
}
char *pop(){
    if(top == NULL){
        printf("It is the empty !");
        return NULL ;
    }
    char *name_d;
    name_d = top->name ;
    top=top->next ;
    return name_d;
}
void peek(){
    if(top != NULL)
    printf("%s\n",top->name);
    else
    printf("Empty it is \n");
}

int main(){
    int choice ;
    printf("Enter the choices 1:add name 2:delete name 3:show the top name (-1 for the exit)");
    scanf(" %d",&choice);
    while(choice != -1){
        switch(choice){
            case 1:{
            char name[10];
            printf("Enter the name : ");
            scanf(" %[^\n]s",name);
            push(name);
            break ;
            }
            case 2: {
                char *name = pop();
                break ;
            }
            case 3:{
                peek();
                break ;
            }
        }
        printf("Enter the choices 1:add name 2:delete name 3:show the top name (-1 for the exit)");
        scanf(" %d",&choice);
    }
    return 0;
}