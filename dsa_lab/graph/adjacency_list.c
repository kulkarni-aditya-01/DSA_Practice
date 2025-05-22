#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max_node 100
struct node {
    int vertex_num ;
    struct node *next ;
} ;
struct node *head[max_node];
int n , m ;
void addnode(int s, int d);
void display();

void addnode(int s, int d){
    struct node *src, *temp, *dest;
    if(head[s]==NULL){     //first make the space for itself 
       head[s]=(struct node *)malloc(sizeof(struct node));
       head[s]->next=NULL;
       head[s]->vertex_num=s;
    }
    dest=(struct node *)malloc(sizeof(struct node));
    dest->next=NULL;
    dest->vertex_num=d;
    temp=head[s];
    while(temp->next != NULL){
        temp = temp->next ;
    }
    temp->next=dest ;
}

void display(){
    struct node *temp ;
    for(int i=0 ; i<n; i++){
        temp=head[i];
        while(temp != NULL){
            printf("%d ",temp->vertex_num);
            temp=temp->next;
            if(temp != NULL)
                printf("--->");
        }
        printf("\n");
    }
}

int main(){
    printf("Enter the no. of the nodes : ");
    scanf(" %d",&n);
    printf("Enter the no. of the edges ");
    scanf(" %d",&m);

    int **arr;
    arr=(int **)malloc(sizeof(int)*m);
    for(int i=0 ; i<m; i++){
        arr[i]=(int *)malloc(sizeof(int )*2);
    }
    for(int i=0 ; i<m ; i++){
        printf("Enter the edge %d : ",i+1);
        scanf(" %d %d",&arr[i][0],&arr[i][1]);
    }
    for(int j=0 ; j<n; j++){
        head[j] = NULL;
    }
    for(int i=0;i<m;i++){
        addnode(arr[i][0],arr[i][1]);
    }
    display() ;
    
}


