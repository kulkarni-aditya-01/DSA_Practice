#include <stdio.h>
#include <stdlib.h>

// Define the structure for the binary tree node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Define the stack structure for traversal
struct stack {
    struct node* data[100];
    int top;
};

// Function prototypes
struct node* createNode(int data);
void push(struct stack* s, struct node* node);
struct node* pop(struct stack* s);
int isEmpty(struct stack* s);
void postorderTraversal(struct node* root);

int main() {
    // Create the binary tree
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    // Perform postorder traversal
    printf("Postorder Traversal (Non-Recursive):\n");
    postorderTraversal(root);

    return 0;
}

// Function to create a new tree node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to push a node onto the stack
void push(struct stack* s, struct node* node) {
    s->data[++(s->top)] = node;
}

// Function to pop a node from the stack
struct node* pop(struct stack* s) {
    return s->data[(s->top)--];
}

// Function to check if the stack is empty
int isEmpty(struct stack* s) {
    return s->top == -1;
}

// Function to perform non-recursive postorder traversal
void postorderTraversal(struct node* root) {
    if (root == NULL) return;

    struct stack s;
    s.top = -1;

    struct node* current = root;
    struct node* prev = NULL;

    while (!isEmpty(&s) || current != NULL) {
        // Traverse to the leftmost node
        while (current != NULL) {
            push(&s, current);
            current = current->left;
        }

        current = pop(&s);

        // If the current node has no right child or the right child has already been visited
        if (current->right == NULL || current->right == prev) {
            printf("%d ", current->data);
            prev = current;
            current = NULL;
        } else {
            // Push the node back into the stack, and process its right child next
            push(&s, current);
            current = current->right;
        }
    }
}
 
//push to the leftmost node and strta to pop 
//check the right node always null or the visited if yes go ---1 if no go to ---2
//1.print the data,  make the prev=current aand the current=NULL 
//2. push the node on to the stack and go back in the loop 