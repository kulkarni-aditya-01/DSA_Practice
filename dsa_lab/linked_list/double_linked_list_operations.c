#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data ;
    struct node *next ;
    struct node *prev;
} ;

struct node *create_DLL(int n);
struct node *insert(struct node *head, int key, int loc, int n);
struct node *delete(struct node *head, int key);
struct node *reverse(struct node *head);
void display(struct node *head);

void display(struct node *head ){
    struct node *p = head;
    while(p != NULL){
        printf("%d ",p->data);
        p=p->next ;
    }
    printf("\n");
}

struct node *reverse(struct node *head){
    struct node *p,*q ;
    p=head ;
    while(p!=NULL){
        q=p->next ;
        p->next=p->prev ;
        p->prev=q ;
        if(q==NULL){
            head = p ;
            break;
        }
        p=q ;
    }
    return head ;
}

struct node *delete(struct node *head, int key){
    struct node *p , *q ;
    p=head ;
    q=head ;
    if(head == NULL){
        printf("Liked list is the NULL :)");
        return NULL ;
    }

    if(head -> data ==key){
        p = p->next ;
        p->prev=NULL;
        head = p ;
        free(p);
        return head ;
    }
    else {
        while(q->data != key && q->next != NULL){
           p = q ;
           q= q->next ; 
        }
        if( q->data == key && q!= NULL){
            p->next=q->next ;
            if(q->next != NULL){
            q->next->prev = p ;
            }
            free(q);
            return head ;
        }
        else {
            printf("Enter the correct key for the delete :)");
            return head ;
        }
    }
    return p ;
}

struct node *insert(struct node *head, int key, int loc, int n){
    struct node *p ;
    if(head == NULL){
        printf("Linked_List is the NULL :) ");
        return NULL;
    }
    p=head;

    if(loc == 0){
        struct node *newnode ;
        newnode = (struct node *)malloc(sizeof(struct node ));
        newnode -> data = key ;
        newnode -> next = p ;
        newnode -> prev = NULL ;
        head = newnode ;
        return head ;    
    }

    else if(loc <= n){
        for(int i=1 ; i<loc ;i++){
            p=p->next ;
        }
        struct node *newnode ;
        newnode=(struct node *)malloc(sizeof(struct node ));
        newnode ->data = key ;
        newnode -> next = p->next ;         //link to the next node of the newnode 
        newnode ->prev = p ;                //link to the prev of nrewnode
        if(p->next != NULL){
            p->next->prev=newnode ;        //backlink for newnode->next->prev 
        }
        p->next = newnode ;                //link to new pointer
        return head ;
    }
    else if(loc>n){
        printf("Enter the correct location for the insert :)");
        return head ;
    }
    return head ;
}

struct node *create_DLL(int n){
    struct node *head , *p , *q;
    int value ;
    head = (struct node *)malloc(sizeof(struct node ));
    printf("Enter the head node value : ");
    scanf(" %d",&value);
    head->data = value ;
    head->next= head->prev = NULL; 
    p = head ;
    for(int i=1 ;i<n;i++){
        q=p;
        p->next=(struct node *)malloc(sizeof(struct node ));
        p=p->next ;
        printf("Enter the node %d : ",i);
        scanf(" %d",&p->data);
        p->prev = q ;
        p -> next =NULL ;
    }
    return head ;
}


int main(){
    struct node *head ;
    int n ;
    printf("Enter the total nodes : ");
    scanf(" %d",&n);
    if(n<=0){
        printf("Enter the correct value :) ");
        return 0 ;
    }
    head = create_DLL(n);
    printf("user enter the linked_list : ");
    display(head);
    int choice ;
    do {
        printf("Enter the operations code 1:insert()\t2:delete()\t3:reverse()\t4.display()   (-1 for the exit) : ");
        scanf(" %d",&choice);
        switch(choice){
            case 1: {
            int key , loc ;
            printf("Enter the key and the location : ");
            scanf(" %d %d",&key,&loc);
            head = insert(head,key,loc,n);
            break;
            }
            case 2:{
            int keyd ;
            printf("Enter the key to be deleted : ");
            scanf(" %d",&keyd);
            head= delete(head,keyd);
            break ;
            }
            case 3:{
            head = reverse(head);
            break;
            }
            case 4:{
            display(head);
            break ;
            }
        }
    }while(choice != -1);    
    return 0;
}