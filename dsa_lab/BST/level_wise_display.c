#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the BST
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Define the structure of a queue
struct queue {
    struct node* data;
    struct queue *next;
};

// Function prototypes
struct node* createNode(int data);
void enqueue(struct queue **front, struct queue **rear, struct node* newNode);
struct node* dequeue(struct queue **front);
int isEmpty(struct queue *front);
void levelOrderTraversal(struct node* root);

int main() {
    struct node* root = NULL;

    // Manually create a simple BST
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    printf("Level Order Traversal of BST: \n");
    levelOrderTraversal(root);

    return 0;
}

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to enqueue a node
void enqueue(struct queue **front, struct queue **rear, struct node* newNode) {
    struct queue* temp = (struct queue*)malloc(sizeof(struct queue));
    temp->data = newNode;
    temp->next = NULL;
    
    if (*rear == NULL) {
        *front = *rear = temp;  // First node in the queue
    } else {
        (*rear)->next = temp;
        *rear = temp;
    }
}

// Function to dequeue a node
struct node* dequeue(struct queue **front) {
    if (isEmpty(*front)) {
        printf("Queue is empty!\n");
        return NULL;
    }
    struct queue* temp = *front;
    *front = (*front)->next;
    struct node* result = temp->data;
    free(temp);
    return result;
}

// Function to check if the queue is empty
int isEmpty(struct queue *front) {
    return front == NULL;
}

// Function to perform Level Order Traversal
void levelOrderTraversal(struct node* root) {
    if (root == NULL) {
        return;
    }

    struct queue *front = NULL, *rear = NULL;

    // Enqueue the root node
    enqueue(&front, &rear, root);

    // Perform level order traversal
    while (!isEmpty(front)) {
        struct node* currentNode = dequeue(&front);
        printf("%d ", currentNode->data);

        // Enqueue left child
        if (currentNode->left != NULL) {
            enqueue(&front, &rear, currentNode->left);
        }

        // Enqueue right child
        if (currentNode->right != NULL) {
            enqueue(&front, &rear, currentNode->right);
        }
    }
}
