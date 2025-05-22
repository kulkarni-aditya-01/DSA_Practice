#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data ;
    struct node *right; 
    struct node *left ;
} ;
struct stack{
    struct node *node ;
    struct stack *next ;
} ;
struct stack *top = NULL;

void push(struct node *node );
struct node *pop();
bool isEmpty();
void peek () ;
struct node *create_BST();
struct node *insert(struct node *root, int key);
struct node *delete(struct node *root, int key);
void find (struct node *root, int key);
void show(struct node *root);
void postorder_nonrec(struct node *root);

void push(struct node *node){
    struct stack *newnode ;
    newnode=(struct stack *)malloc(sizeof(struct stack ));
    newnode ->node = node ;
    newnode->next = top ;
    top=newnode ;
}

struct node *pop(){
    if(top == NULL){
        printf("Null stack it is ! ");
        return NULL ;
    }
    struct node *temp= top->node ;
    top=top->next ;
    return temp ;
}
bool isEmpty(){
    return  top==NULL ;
}

// void preorder_nonrec(struct node *root){
//     struct node *current_node=root ;
//     struct node *prev ;
//     while(current_node != NULL && !isEmpty() )
//     while(current_node != NULL){
//         push(current_node);
//         current_node=current_node ->left;        //push all left node 
//     }
//     current_node = pop();
//     if(current_node ->right != NULL || current_node != prev){
//         push(current_node);
//         prev=
//     }
// }

void show(struct node *root){
    // postorder_nonrec(root);
}

void find(struct node *root, int key){
    if(root == NULL){
        printf("key is not found !");
        return ;
    }
    if(key < root->data){
        find(root->left, key);
    }
    else if(key> root->data){
        find(root->right , key);
    }
    else {
        if(root->data == key){
            printf("%d key found !", root->data);
        }
    }
}

struct node *findMin(struct node *root){
    while(root != NULL && root->left != NULL){
        root= root->left ;
    }
    return root ;
}

struct node *delete(struct node *root, int key){
    if(root == NULL){
        return NULL;
    }
    if(key < root->data){
        root->left= delete(root->left, key);
    }
    else if(key > root->data){
        root->right=delete(root->right, key);
    }
    else {
        if(root->left==NULL && root->right==NULL){
            free(root);       //case of leaf node delete 
            return root ;
        }
        else if(root->right == NULL){
            struct node *temp= root->left ;
            free(root);       //case of having one child 
            return temp;
        }
        else if(root->left == NULL){
            struct node *temp=root->right;
            free(root);    
            return temp ;
        }
        else {
            struct node *temp=findMin(root->right);
            root->data=temp->data;
            root->right=delete(root->right, temp->data);            
        }
    }
}


struct node *insert(struct node *root, int key){
    if(root == NULL){
        struct node *newnode ;
        newnode=(struct node *)malloc(sizeof(struct node ));
        newnode->right = NULL;
        newnode->left = NULL;
        return newnode ;
    }

    if(key < root->data){
        root->left = insert(root->left, key);
    }
    else if(key > root->data){
        root->right= insert(root->right, key);
    }

    return root ;
}

struct node *create_BST(){
    struct node *root;
    int x;
    printf("Enter the key : ");
    scanf(" %d",&x);
    if( x== -1){
        return NULL;
    }
    root=(struct node *)malloc(sizeof(struct node ));
    root->data=x;
    printf("Enter the left key of the %d\n",x);
    root->left=create_BST();
    printf("Enter the right node of the %d\n",x);
    root->right=create_BST();
    return root ;
}


int main(){
    struct node *root ;
    root=create_BST();
    int choice ;
    printf("Enter the choice 1:insert()\t2:delete()3:find()\t4:show()\t(-1 for the exit) : ");
    scanf(" %d",&choice);
    while(choice != -1){
        switch(choice ){
            case 1 :{
                int keyi ;
                printf("Enter the to be inserted  : ");
                scanf(" %d",&keyi);
                root= insert(root, keyi);
                break ;
            }
            case 2:{
                int keyd ;
                printf("Enter the to be deleted  : " );
                scanf(" %d",&keyd);
                root=delete(root, keyd);
                break ;
            }
            case 3:{
                int keyf;
                printf("Ente the key to be find : ");
                scanf(" %d",&keyf);
                find(root,keyf);
                break;
            }
            case 4:{
                show(root);
                break ;
            }
        }
        printf("Enter the choice 1:insert()\t2:delete()3:find()\t4:show()\t(-1 for the exit) : ");
        scanf(" %d",&choice);
    }
    return 0 ;
}

