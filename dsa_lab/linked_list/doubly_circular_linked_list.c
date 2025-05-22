#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data ;
    struct node *prev ;
    struct node *next ;
} ;
struct node *tail ;

struct node *create_DCLL(int n);
struct node *insert(struct node *head, int key , int loc , int n);
struct node *delete(struct node *head, int key);
struct node *reverse(struct node *head);
void display(struct node *head);

void display(struct node *head){
    struct node *p;
    p=tail->next ;
    while(p->next != tail->next){
        printf("%d ",p->data);
        p=p->next ;
    }
    printf("%d ",p->data);
}

struct node *reverse(struct node *head){
    struct node *current , *nextnode;
    current = head;
    if(head == NULL){
        return NULL;
    }
    if(tail->next->next == NULL){
        return tail->next ;
    }
    else {
        while(current != tail){
            nextnode=current->next ;
            current->next=current->prev;
            current -> prev= nextnode ;
            current=nextnode;
        }     
        current->next=current->prev;
        current -> prev= nextnode ;  
        tail=head;
        head=current ; 
        return head ;
    }
    return head ;
}

struct node *delete(struct node *head, int key){
    struct node *p , *q  ;
    p=q=head ;
    if(head == NULL){
        return NULL;
    }
    if(head->data == key){
        head=p->next ;
        tail->next=head;
        head->prev=tail ;
        free(p);
        return head ;
    }
    else {
        while(q -> data != key && q->next != tail->next ){
            p=q;
            q=q->next;
        }
        if(q->data == key ){
            p->next=q->next;
            q->next->prev=p;
            if(q -> next == tail->next){
                tail=p;
            }
            return head ;
        }
        else {
            printf("Invalid key it is :) ");
            return head ;
        }
    }
    return head ;
}


struct node *insert(struct node *head, int key, int loc, int n){
    struct node *p ;
    int i ;
    p=head;
    if(head == NULL){
        printf("NULL linked list :) ");
        return NULL ;
    }
    if(loc == 0){
        struct node *newnode ;
        newnode = (struct node *)malloc(sizeof(struct node ));
        newnode->data =key ;
        newnode -> next = tail->next;
        newnode -> prev = tail ;
        tail->next=newnode ;
        head=newnode ;
    }
    else if(loc<=n){
        for(i=1 ; i<loc ; i++){
            p=p->next ;
        }
        struct node *newnode ;
        newnode = (struct node *)malloc(sizeof(struct node ));
        newnode -> data = key;
        newnode ->next=p->next;
        newnode->prev=p;
        p->next->prev=newnode ;
        if(i == n){
            tail=newnode;
        }
        p->next=newnode;
    }
    return head ;
}


struct node *create_DCLL(int n){
    struct node *head ;
    struct node *p, *q;
    int x ;
    head=(struct node *)malloc(sizeof(struct node ));
    printf("Enter the value of the head node : ");
    scanf(" %d",&x);
    head->data = x;
    head->next=NULL;
    head->prev=NULL;
    p=head ;

    for(int i=1 ; i< n ; i++){
        q=p ;
        p->next=(struct node *)malloc(sizeof(struct node ));
        p=p->next ;
        scanf(" %d",&p->data);
        p->next=NULL;
        p->prev=q;
        tail=p;
    }
    p->next=head ;
    head->prev=p ;    
}


int main(){
    struct node *head ;
    int n ;
    printf("Enter the how many nodes in the circular linked list : ");
    scanf(" %d",&n);
    head = create_DCLL(n);
    display(head) ;
    printf("\ntail node : %d\n",tail->data);
    head = insert(head, 2, 3, n);
    display(head);
    printf("\n");
    head=delete(head, 4);
    display(head);
    printf("\n");
    head=reverse(head);
    display(head) ;
    printf("\n");

    return 0 ;
}
