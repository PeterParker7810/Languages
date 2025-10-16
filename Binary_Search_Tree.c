#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void Insert(struct Node** root, int val) {
    if (*root == NULL) {
        *root = createNode(val);
        printf("Inserted: %d\n", val);
        return;
    }
    if (val < (*root)->data) Insert(&((*root)->left), val);
    else Insert(&((*root)->right), val);
}

int Search(struct Node* root, int val) {
    if (root == NULL) return 0;  
    if (root->data == val) return 1; 

    if (val < root->data) return Search(root->left, val);
    else return Search(root->right, val);
}

struct Node* FindMin(struct Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

struct Node* Delete(struct Node* root, int val) {
    if (root == NULL) return root;
    
    if (val < root->data) root->left = Delete(root->left, val);
    else if (val > root->data) root->right = Delete(root->right, val);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = FindMin(root->right);
        root->data = temp->data;
        root->right = Delete(root->right, temp->data);
    }
    return root;
}

void Inorder(struct Node* root) {
    if (root == NULL) return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}

void Preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(struct Node* root) {
    if (root == NULL) return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct Node* root = NULL;
    int choice, val;

    printf("\n1. Insert\n2. Search\n3. Delete\n4. Inorder Traversal\n5. Preorder Traversal\n6. Postorder Traversal\n");
    while (1) {
        printf("\nEnter Tree Operation: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &val);
            Insert(&root, val);
        }
        else if (choice == 2) {
            printf("Enter value to search: ");
            scanf("%d", &val);
            if (Search(root, val)) printf("%d Found in the tree.\n", val);
            else printf("%d Not Found in the tree.\n", val);
        }
        else if (choice == 3) {
            printf("Enter value to delete: ");
            scanf("%d", &val);
            root = Delete(root, val);
            printf("Deleted: %d\n", val);
        }
        else if (choice == 4) {
            printf("Inorder: ");
            Inorder(root);
            printf("\n");
        }
        else if (choice == 5) {
            printf("Preorder: ");
            Preorder(root);
            printf("\n");
        }
        else if (choice == 6) {
            printf("Postorder: ");
            Postorder(root);
            printf("\n");
        }
        else printf("Invalid choice. Please try again.\n");
    }

    return 0;
}