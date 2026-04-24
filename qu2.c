#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* left;
    struct node* right;
    int data;
};

struct node* createNode(int value){
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inorder(struct node* root){
    if(root !=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct node* inOrderPred(struct node * root){
    root = root->left;
    while(root->right!=NULL) root = root->right;
    return root;
}

struct node* deleteNode(struct node* root,int key){
    if(root==NULL) return NULL;
    if(key<root->data) root->left = deleteNode(root->left, key);
    else if(key> root->data) root->right = deleteNode(root->right, key);
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        else if(root->left == NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        else{
            struct node* inP = inOrderPred(root);
            root->data = inP->data;
            root->left = deleteNode(root->left, inP->data);
        }
    }
    return root;
}

struct node * insert(struct node* root, int key){
    if(root==NULL) return createNode(key);
    if(key<root->data) root->left = insert(root->left, key);
    else if(key>root->data) root->right = insert(root->right, key);
    
    return root;
}

int main(){
    struct node *root = createNode(4);
    root->right = createNode(6);
    root->right->left = createNode(5);
    root->left = createNode(2);
    root->left->right = createNode(3);
    root->right->right = createNode(7);
    root->left->left = createNode(1);

    inorder(root);
    printf("\n");
    root = deleteNode(root, 4);
    printf("\n");
    inorder(root);
    printf("\n");
    insert(root, 4);
    printf("\n");
    inorder(root);

}
