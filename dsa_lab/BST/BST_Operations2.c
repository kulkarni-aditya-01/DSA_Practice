    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <ctype.h>
    struct node{
        int data ;
        struct node *left ;
        struct node *right ;
    };
    struct stack{
        struct node *tree_node ;
        struct stack *next ;
    };
    struct stack *top=NULL;



    void push(struct node *node);
    struct node *pop();
    void peek();
    bool isEmpty();
    void leaf_node_rec(struct node *root);
    void leaf_node_non_rec(struct node *root);
    struct node *create_BST();
    void inorder_rec (struct node *root);
    void depth_of_BST(struct node *root);
    void mirror(struct node *root);
    void mirror_nonrec(struct node *root);

    bool isEmpty(){
        return (top == NULL);
    }
    void push(struct node *node){
        struct stack *newnode;
        newnode=(struct stack *)malloc(sizeof(struct stack ));
        newnode -> tree_node = node;
        newnode -> next = top ;
        top = newnode ;
    }
    struct node *pop(){
        if(top != NULL){
            struct node *temp;
            temp = top->tree_node ;
            top = top->next ;
            return temp;
        }
        return NULL;
    }

    void leaf_node_non_rec(struct node *root){
            struct node *current_node = root ;
            while(!isEmpty() || current_node != NULL){
            while(current_node != NULL){
                push(current_node);
                current_node = current_node->left;
            }
            current_node = pop() ;
            if(current_node ->right == NULL && current_node->left == NULL){
                printf("%d ",current_node->data);
            }
            current_node = current_node->right ;
         }   
    }
    void leaf_node_rec(struct node *root){
        if(root == NULL){
            return ;        
        }
        if(root->left==NULL && root->right==NULL ){
                printf("%d ",root->data);
                return ;
        }
        leaf_node_rec(root->left);
        leaf_node_rec(root->right);
    }

    void inorder_rec(struct node *root){
        if(root == NULL){
            return ;
        }
        inorder_rec(root->left);
        printf("%d ",root->data);
        inorder_rec(root->right);
    }
    void mirror(struct node* root) {
    if (root == NULL)
        return;

    // Swap the left and right subtrees
    struct node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recur for left and right subtrees
    mirror(root->left);
    mirror(root->right);
}
    void mirror_nonrec(struct node *root){
        top = NULL ;
        struct node *current_node=root ;
        while(current_node != NULL || !isEmpty()){
            while(current_node != NULL){
                push(current_node);
                current_node= current_node->left;
            }
            current_node=pop();
            struct node *temp=current_node->left;
            current_node->left=current_node->right;
            current_node->right=temp;

            current_node=current_node->right;
        }
    }

    struct node *create_BST(){
        int x ;
        printf("Enter the node value : ");
        scanf(" %d",&x);
        if(x== -1){
            return NULL;
        }
        struct node *root ;
        root = (struct node *)malloc(sizeof(struct node ));
        root->data=x;
        printf("Enter the left node of the %d:\n",x);
        root->left=create_BST();
        printf("Enter the right value of the %d:\n",x);
        root->right=create_BST();
        return root ;
        
    }

    int main (){
        struct node *root ;
        root = create_BST() ;
        inorder_rec(root);
        printf("\n") ;
        printf("Leaf node are :" );
        leaf_node_rec(root);
        printf("\n");
        printf("Leaf nodes by the non_rec : ");
        leaf_node_non_rec(root);
        mirror(root);
        printf("\n");
        printf("Mirror image of the bst : ");
        inorder_rec(root);
        printf("\n");
        printf("Mirror image by the non_rec : ");
        mirror_nonrec(root);
        inorder_rec(root);
        return 0;
    }
