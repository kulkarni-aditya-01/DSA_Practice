#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node {
    int data ;
    struct node *next ;
};


struct node *create_SLL(int n);
struct node *insert(struct node *head, int key, int loc, int n);
struct node *delete(struct node *head, int key);
struct node *reverse(struct node *head);
void display(struct node *head);


void display(struct node *head){
    struct node *p;
    p=head;
    while(p != NULL){
        printf("%d ",p->data);
        p=p->next ;
    }
    printf("\n");
}

struct node *reverse(struct node *head){
    struct node *p,*q,*r;
    r=head ;
    q=NULL;
    if(head==NULL){
        printf("Enter list is the NULL :) ");
        return NULL;
    }
    if(head->next == NULL){
        return head ;
    }
    else {
        while(r != NULL){
            p=q;
            q=r;
            r=r->next;
            q->next=p;
            if(r == NULL){
                head= q ;
                break ;
            }
        }
        return head ;
    }
    return head ;
}


struct node *delete(struct node *head, int key){
    struct node *p, *q ;
    p=q=head ;
    if(head==NULL){
        printf("Null list it is  :)\n");
        return NULL ;
    }
    if(head->data == key){
        head=p->next ;
        free(p);
        return head ;
    }
    else{
        while (q->data == key && q->next != NULL){
            p=q ;
            q=q->next;
        }
        if(q->data == key && q!=NULL){
            p->next=q->next;
            free(q);
            return head ;
        }
        else {
            printf("Key is not found :) ");
            return head ;
        }
    }
    return head ;


}
struct node *insert(struct node *head, int key, int loc, int n){
    struct node *p ;
    p=head ;
    if(head==NULL){
        return NULL; 
    }
    if(loc==0){
        struct node *newnode ;
        newnode = (struct node *)malloc(sizeof(struct node ));
        newnode->data=key;
        newnode->next=head;
        head=newnode ;
        return head;
    }
    else if(loc<=n){
        for(int i=1 ; i<loc; i++){
            p=p->next;
        }
        struct node *newnode ;
        newnode =(struct node *)malloc(sizeof(struct node ));
        newnode->data=key;
        newnode -> next=p->next ;
        p->next=newnode;
        return head ;
    }
    else if(loc>n){
        printf("Enter the correct location :)  ");
        return head ;
    }
    return head ;

}

struct node *create_SLL(int n){
    struct node *head ;
    struct node *p ;
    int value ;
    head=(struct node *)malloc(sizeof(struct node ));
    printf("Entert the node value : ");
    scanf(" %d", &value);
    head->data= value ;
    head->next=NULL;
    p=head ;
    for(int i=1 ; i<n;i++){
        p->next=(struct node *)malloc(sizeof(struct node ));
        p=p->next ;
        printf("Enter the node %d : ",i);
        scanf(" %d",&p->data);
        p->next=NULL;
    }
    return head;
}

int main (){
    struct node *head ;
    int n;
    printf("Enter the no. of the links in the list :" );
    scanf(" %d",&n);
    head= create_SLL(n);
    printf("USer enter the list : ");
    display(head);
    int choice ;
    do{
        printf("Enter the choice 1:insert()\t2:delete()\t3:reverse()\t4:display()\t(-1 is for the exit)");
        scanf(" %d",&choice);
        switch(choice){
            case 1:{
            int keyi, loc ;
            printf("Enter the key and the location : ");
            scanf(" %d %d",&keyi,&loc);
            head=insert(head, keyi, loc, n);
            break ;
            }
            case 2:{
            int keyd ;
            printf("Enter the key to be deleted : ");
            scanf(" %d",&keyd);
            head=delete(head, keyd);
            break ;
            }
            case 3:{
            head= reverse(head);
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
