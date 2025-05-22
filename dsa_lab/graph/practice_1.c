#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max_node 15 

struct node {
    int data;
    struct node *next;
};

struct adj_list {
    struct node *head;
};

struct queue {
    struct node *g_node;
    struct queue *next;
};

struct queue *rear = NULL;
struct queue *front = NULL;
struct adj_list *adj_list[max_node];
int visited[max_node] ;

void enqueue(struct node *node);
struct node *dequeue();
bool isEmpty();
void addnode(int s, int d);
void display(int n);
void BFS_traversal(int strt);

bool isEmpty() {
    return (rear == front && rear == NULL);
}

void enqueue(struct node *node) {
    struct queue *newnode;
    newnode = (struct queue *)malloc(sizeof(struct queue));
    newnode->g_node = node;
    newnode->next = NULL;
    if (rear == front && rear == NULL) {
        rear = front = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

struct node *dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return NULL;
    }
    struct node *temp = front->g_node;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    return temp;
}

void addnode(int s, int d) {
    struct node *dest = (struct node *)malloc(sizeof(struct node));
    dest->data = d;
    dest->next = NULL;

    if (adj_list[s]->head == NULL) {
        adj_list[s]->head = (struct node *)malloc(sizeof(struct node));
        adj_list[s]->head->data = s;
        adj_list[s]->head->next = NULL;
    }

    struct node *temp = adj_list[s]->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = dest;
}

void display(int n) {
    for (int i = 0; i < n; i++) {
        struct node *temp = adj_list[i]->head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
            if (temp != NULL) {
                printf("---->");
            }
        }
        printf("\n");
    }
}

void BFS_traversal(int strt) {
    enqueue(adj_list[strt]->head) ;
    visited[strt]=1 ;
    while( !isEmpty() ){
        struct node *temp = dequeue() ;
        if(visited[temp->data] == 0 && temp != NULL){
            printf("%d ",temp->data);
            visited[temp->data] = 1 ;
            temp = temp->next ;
            while(temp != NULL){
                if(visited[temp->data] == 0 && temp != NULL){
                    enqueue(adj_list[temp->data]->head);
                }
                temp = temp ->next ;
            }
        }
    }
}

int main() {
    int n, m;
    printf("Enter the total no. of the nodes: ");
    scanf(" %d", &n);
    printf("Enter the total no. of the edges: ");
    scanf(" %d", &m);

    int **arr;
    arr = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        arr[i] = (int *)malloc(2 * sizeof(int));
        printf("Enter the edge %d: ", i + 1);
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    for (int i = 0; i < n; i++) {
        adj_list[i] = (struct adj_list *)malloc(sizeof(struct adj_list));
        adj_list[i]->head = NULL;
        visited[i]= 0 ;
    }

    for (int i = 0; i < m; i++) {
        addnode(arr[i][0], arr[i][1]);
        addnode(arr[i][1],arr[i][0]);
    }
    int strt ;
    printf("Enter the strt node for the strt : ");
    scanf(" %d",&strt);

    display(n);

    BFS_traversal(strt);

    return 0;
}
