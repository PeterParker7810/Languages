#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value){
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

void InorderTraversal(struct TreeNode* root){
    if (root == NULL) return;
    InorderTraversal(root->left);
    printf("%d ", root->data);
    InorderTraversal(root->right);
}

int main(){
    struct TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(3);
    root->left->right = createNode(7);

    printf("Inorder Traversal: ");
    InorderTraversal(root);

    return 0;
}
