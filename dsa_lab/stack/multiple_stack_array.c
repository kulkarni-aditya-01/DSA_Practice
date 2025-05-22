#include <stdio.h>
#include <stdlib.h>

#define MAX 10  // Maximum size of each stack

// Define the stack structure
struct stack {
    int data[MAX];
    int top;
};

// Function prototypes
void push(struct stack *s, int value);
int pop(struct stack *s);
int isEmpty(struct stack *s);
int isFull(struct stack *s);
void display(struct stack *s);

int main() {
    struct stack s1, s2, s3;  // Declare three stacks
    s1.top = -1;  // Initialize the top for all stacks
    s2.top = -1;
    s3.top = -1;

    // Sample usage
    printf("Pushing into Stack 1:\n");
    push(&s1, 10);
    push(&s1, 20);
    push(&s1, 30);
    display(&s1);

    printf("\nPopping from Stack 1:\n");
    printf("Popped: %d\n", pop(&s1));
    display(&s1);

    printf("\nPushing into Stack 2:\n");
    push(&s2, 100);
    push(&s2, 200);
    display(&s2);

    printf("\nPushing into Stack 3:\n");
    push(&s3, 500);
    push(&s3, 600);
    push(&s3, 700);
    display(&s3);

    return 0;
}

// Push function
void push(struct stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    s->data[++s->top] = value;
    printf("Pushed %d\n", value);
}

// Pop function
int pop(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;  // Return an error value
    }
    return s->data[s->top--];
}

// Check if the stack is empty
int isEmpty(struct stack *s) {
    return s->top == -1;
}

// Check if the stack is full
int isFull(struct stack *s) {
    return s->top == MAX - 1;
}

// Display the stack
void display(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack contents: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}
