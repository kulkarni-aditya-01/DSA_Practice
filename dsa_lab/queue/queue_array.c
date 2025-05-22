#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
# define MAX 100
struct passanger{
    char name[50];
    char destination[50];
    char start[50];
    int ticket_fees ;    
} ;
struct passanger queue[MAX];
int rear =-1;
int front =-1;

void enqueue(struct passanger passanger);
void dequeue();
void front_peek();
void display();
void total_passanger();

void enqueue(struct passanger passanger){
    if(rear == -1 && front == -1){
        front = 0;
        rear= 0;
        queue[front] = passanger ;
    }
    else if( rear == MAX-1){
        printf("All tickets are full !\n");
    }
    else {
        rear++;
        queue[rear] = passanger ;
    }
}
void dequeue(){
    if(front == rear){
        struct passanger passanger = queue[front];
        printf("%s\t%s\t%s\t%d\n",passanger.name,passanger.start,passanger.destination,passanger.ticket_fees);
        front=rear=-1;
    }
    else if(front == rear == -1){
        printf("Empty queue !\n");
    }
    else {
        struct passanger passanger = queue[front];
        printf("%s\t%s\t%s\t%d\n",passanger.name,passanger.start,passanger.destination,passanger.ticket_fees);        
        front++;
    }
}
void front_peek(){
    if(front != -1 && rear != -1){
        struct passanger passanger = queue[front];
        printf("%s\t%s\t%s\tRs.%d\n",passanger.name,passanger.start,passanger.destination,passanger.ticket_fees);
    }
    else {
        printf("Queue is empty or the full !\n");
    }
}
void display(){
    if(front != -1 && rear != -1){
        int temp=front ;
        while(temp <= rear){
            struct passanger passanger = queue[temp];
            printf("%s\t%s\t%s\tRs.%d\n",passanger.name,passanger.start,passanger.destination,passanger.ticket_fees);
            temp++;
        }
    }
    else {
        printf("Queue is full or the empty !\n");
    }
}
void total_passanger(){
    if(front != -1 && rear != -1)
    printf("%d are the total apssanger in the queue !\n",rear-front+1);
}


int main (){
    struct passanger passanger ;
    int choice ;
    printf("Enter the choice 1:add passanger\t2:delete passanger\t3:start of the queue\t4:total passanger\t5:list of the passamger (-1 for the exxit)");
    scanf(" %d",&choice);
    while(choice != -1){
        switch(choice){
            case 1:{
                struct passanger passanger ;
                printf("Enter the name of the passanger : ");
                scanf(" %[^\n]s",passanger.name);
                printf("Enter the detination station : ");
                scanf(" %[^\n]s",passanger.destination);
                printf("Enter the start station : ");
                scanf(" %[^\n]s",passanger.start);
                printf("Enter the ticket fees :");
                scanf(" %d",&passanger.ticket_fees);
                enqueue(passanger);
                break;
            }
            case 2:{
                dequeue();
                break;
            }
            case 3:{
                front_peek();
                break;
            }
            case 4:{
                total_passanger();
                break;
            }
            case 5:{
                display();
                break ;
            }
        }
    printf("Enter the choice 1:add passanger\t2:delete passanger\t3:start of the queue\t4:total passanger\t5:list of the passamger (-1 for the exxit)");
    scanf(" %d",&choice);
    }
    return 0;
}
