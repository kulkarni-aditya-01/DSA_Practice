#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max_node 10
// below are the global expressions ......
struct node
{
    int vertex_num;
    struct node *next;
};
struct adjlist
{
    struct node *head;
};
struct queue
{
    struct node *g_node;
    struct queue *next;
};
struct queue *front = NULL;
struct queue *rear = NULL;
int visited[max_node];
struct adjlist *adjlist[max_node];
int m, n;
// below are the functions defines
void addnode(int s, int d);
void display();
void enqueue(struct node *node);
struct node *dequeue();
bool isEmpty();
void BFS_traversaal(int src );

// actually start the code ....
void enqueue(struct node *node)
{
    struct queue *newnode;
    newnode = (struct queue *)malloc(sizeof(struct queue));
    newnode->g_node = node;
    newnode->next = NULL;
    if(rear==NULL && front== NULL){
        rear=front=newnode ;
    }
    else {
        rear->next=newnode ;
        rear=newnode ;
    }
    
}
struct node *dequeue()
{
    if (front == NULL && rear == NULL)
    {
        printf("Queue is empty ! ");
        return NULL;
    }
    else if (front == rear)
    {
        struct node *temp = front->g_node;
        front = rear = NULL;
        return temp;
    }
    struct node *temp = front->g_node ;
    front = front->next;
    return temp;
}

bool isEmpty()
{
    if (front == NULL && rear == NULL)
        return true;
    return false;
}

void BFS_traversal(int src){
    enqueue(adjlist[src]->head);
    while(!isEmpty()){
        struct node *temp=dequeue();
        if(visited[temp->vertex_num]==0 && temp != NULL){
            printf("%d ",temp->vertex_num);
            visited[temp->vertex_num]=1;
            struct node *node = temp->next;
            while(node != NULL){
                if(visited[node->vertex_num] == 0 && node != NULL){
                    enqueue(adjlist[node->vertex_num]->head);
                }
                node=node->next ;
            }
        }
    }
}
void addnode(int s, int d)
{
    struct node *dest, *temp;
    if (adjlist[s]->head == NULL)
    { // this is for the source node creation which will save in the head
        adjlist[s]->head = (struct node *)malloc(sizeof(struct node));
        adjlist[s]->head->next = NULL;
        adjlist[s]->head->vertex_num = s;
    }
    dest = (struct node *)malloc(sizeof(struct node)); // this will make the adjacency list eventually
    dest->next = NULL;
    dest->vertex_num = d;
    temp = adjlist[s]->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = dest; // this will make the list coonected or add the node at the last
}

void display()
{
    for (int i = 0; i < n; i++)
    {
        struct node *temp = adjlist[i]->head;
        while (temp != NULL)
        {
            printf("%d ", temp->vertex_num);
            temp = temp->next;
            if (temp != NULL)
            {
                printf("--->");
            }
        }
        printf("\n");
    }
}

int main()
{
    printf("Enter the total no. of the node : ");
    scanf(" %d", &n);
    printf("Enter the total edges : ");
    scanf(" %d", &m);

    int **arr;
    // for the graph edges
    arr = (int **)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * 2);
    }
    for (int i = 0; i < m; i++)
    {
        printf("Enter the edge %d : ", i + 1);
        scanf(" %d %d", &arr[i][0], &arr[i][1]);
    }

    // for the adjlist
    for (int i = 0; i < n; i++)
    { // this will make the memory for the every member to save the value ;
        adjlist[i] = (struct adjlist *)malloc(sizeof(struct adjlist));
    }
    for (int i = 0; i < n; i++)
    { // this NULL will be saved in the each head ;
        adjlist[i]->head = NULL;
    }

    for (int i = 0; i < m; i++)
    {
        addnode(arr[i][0], arr[i][1]);
    }
    display();

    // for the BSF traversal ;
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    BFS_traversal(0);
    
    return 0;
}
