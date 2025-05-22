#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data ;
    struct node *next ;
} ;
struct node *tail=NULL; 

struct node *create_SCLL(int n);
struct node *insert(struct node *head, int key, int loc, int n);
struct node *delete(struct node *head, int key);
struct node *reverse(struct node *head);
void display(struct node *head);


void display(struct node *head){
    // struct node *p;
    // p=head ;
    // while(p->next != head ){
    //     printf("%d ",p->data);
    //     p=p->next;
    // }
    // printf("%d ",p->data);
    struct node *temp;
    temp=tail->next ;
    while(temp->next != tail->next){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
    printf("\n");
}
struct node *reverse (struct node *head){
    struct node *p ,*q, *r ;
    p=NULL;
    q=head;
    r=q->next;
    if(tail == NULL){
        printf("Empty list it is :) ");
        return NULL ;
    }
    if(tail->next->next == NULL){
        return head ;
    }
    else {
        while(q != tail){
            p=q;
            q=r;
            r=q->next ;
            q->next = p;
        }
        r->next=tail;
        tail=r;
        head=q;
    }
    return head ;
}
struct node *delete(struct node *head, int key){
    struct node *p ;
    struct node *q ;
    p=q=head ;
    if(tail->next->data == key){
        head = head->next ;
        tail -> next = head ;
        free(p) ;
        return head ;
    }
    else {
        while (q->data != key && q->next != tail->next ){
            p=q ;
            q=q->next ;
        }
        if( q -> data == key){
            p->next = q->next ;
            if( q->next == tail->next){
                tail=p;
            }
            free(q);
            return head ;
        }
        else {
            printf("Enter the correct key :)");
            return head ;
        }
    }
    return head ;
}

struct node *insert(struct node *head, int key, int loc, int n){
    struct node *p ;
    p=head ;
    if(tail == NULL){
        return NULL ;
    }
    if(loc == 0){
        struct node *newnode ;
        newnode = (struct node *)malloc(sizeof(struct node ));
        newnode -> data = key ;
        newnode ->next = tail->next ;
        tail ->next = newnode ;
        head = newnode ;
        return head ;
    }
    else if(loc <= n){
        int i ;
        for(i=1 ; i<loc ; i++){
            p=p->next ;  
        }
        struct node *newnode ;
        newnode=(struct node *)malloc(sizeof(struct node ));
        newnode -> data = key;
        newnode -> next=p->next ;
        p->next = newnode ;
        if(i == n){
            tail = newnode ;
        }
        return head ;
    }
    return head ;
}

struct node *create_SCLL(int n){
    struct node *head;
    struct node *p;
    int value ;
    head=(struct node *)malloc(sizeof(struct node ));
    printf("Enter the head node : ");
    scanf(" %d",&value);
    head->data=value ;
    head->next = NULL;
    p=head ;
    for(int i=1; i<n; i++){
        p->next=(struct node *)malloc(sizeof(struct node ));
        p=p->next ;
        printf("Enter the node %d : ",i);
        scanf(" %d",&p->data);
        p->next = NULL;
        tail=p ;
    }
    p->next=head;
    return head ;
}

int main(){
    struct node *head;
    int n ;
    printf("Enter the total no. of the link : ");
    scanf(" %d",&n);
    if(n<=0){
        printf("Enter the corrrect vlaue of the n :)");
        return 0;
    }
    head=create_SCLL(n);
    printf("User enters the linked list : ");
    display(head);
    printf("%ld\n",head);
    printf("%d %ld",tail->data, &tail->next);
    // head = insert(head, 2, 2, n);
    int choice ;
    do{
        printf("Enter the choice for the operations 1:insert()\t2:delete()\t3:reverse()\t4:display()\t(-1 for the exit process) : ");
        scanf(" %d",&choice);
        switch(choice){
            case 1: {
            int keyi , loc ;
            printf("Enter the key and the location of the inserting node : ");
            scanf(" %d %d",&keyi,&loc);
            head=insert(head, keyi, loc, n);
            break ;
            }
            case 2:{
            int keyd ;
            printf("Enter the key to be deleted from the list : ");
            scanf(" %d",&keyd);
            head=delete(head, keyd);
            break ;
            }
            case 3:{
            head=reverse(head);
            break;
            }
            case 4:{
            display(head) ;
            break ;
            }
        }
        } while( choice != -1);
    printf("\n");
    display(head) ;
    return 0 ;
}