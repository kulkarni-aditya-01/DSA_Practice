#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct stack
{
    struct node *tree;
    struct stack *next;
};
struct stack *top = NULL;

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

void push(struct node *tree_node);
struct node *pop();
void peek();
bool isEmpty();
struct node *create_BST();
struct node *insert(struct node *root, int key);
struct node *delete(struct node *root, int key);
void inorder_rec(struct node *root);
void inorder_nonrec(struct node *root);
void preorder_nonrec(struct node *root);


bool isEmpty(){
    if(top == NULL)
    return true ;

    return false ;
}
struct node *pop(){
    if(top == NULL){
    return NULL;
    }
    struct stack *temp ;
    struct node *node ;
    temp = top ;
    node = temp->tree;
    top = top->next;
    free(temp);
    return node ;
}

void push(struct node *tree_node){
    struct stack *newnode ;
    newnode = (struct stack *)malloc(sizeof(struct stack));
    newnode -> tree= tree_node ;
    newnode -> next = top ;
    top = newnode ; 
}

void preorder_nonrec(struct node *root){
    struct node *current_node ;
    struct stack *current_stack;
    current_node = root ;

    while(current_node != NULL || !isEmpty()){
        while(current_node !=  NULL){
            printf("%d ",current_node ->data);
            push(current_node);
            current_node = current_node ->left ;
        }
        current_node = pop();
        current_node = current_node->right;
    }
}
void inorder_nonrec(struct node *root){
    struct stack *current_stack ;
    struct node *current_node=root;
    while (current_node != NULL || !isEmpty()){
        while(current_node != NULL ){
        push(current_node);
        current_node = current_node->left ;
    }
    current_node = pop() ;
    printf("%d ",current_node->data);
    current_node = current_node->right ;
    }
}

void inorder_rec(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder_rec(root->left);
    printf("%d ", root->data);
    inorder_rec(root->right);
}
struct node *create_BST()
{
    int x;
    printf("Enter the node value : ");
    scanf(" %d", &x);
    if (x == -1)
    {
        return NULL;
    }
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    printf("Enter the left node of the %d :\n", x);
    newnode->left = create_BST();
    printf("Enter the right node of the %d : \n", x);
    newnode->right = create_BST();
    return newnode;
}

int main()
{
    struct node *root;
    root = NULL;
    root = create_BST();
    inorder_rec(root);
    printf("\n");
    printf("Inorder non_rec : ");
    inorder_nonrec(root);
    printf("\n");
    printf("Preorder_nonrec : ");
    preorder_nonrec(root);
    return 0;
}