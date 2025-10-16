#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data, height;
    struct Node *left, *right;
};

int max(int a, int b) {return (a > b) ? a : b;}

int getHeight(struct Node* node) {return node ? node->height : 0;}

int getBalance(struct Node* node) {return node ? getHeight(node->left) - getHeight(node->right) : 0;}

void updateHeight(struct Node* node) {
    if (node) node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

struct Node* leftRotate(struct Node* y) {
    struct Node* x = y->right;
    struct Node* T2 = x->left;

    x->left = y;
    y->right = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

struct Node* balancing(struct Node* node) {
    if (!node) return NULL;

    updateHeight(node);
    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0) return rightRotate(node);
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && getBalance(node->right) <= 0) return leftRotate(node);
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

struct Node* insert(struct Node* node, int val) {
    if (!node) return createNode(val);

    if (val < node->data) node->left = insert(node->left, val);
    else if (val > node->data) node->right = insert(node->right, val);
    else return node;

    return balancing(node);
}

struct Node* findMin(struct Node* node) {
    while (node && node->left) node = node->left;
    return node;
}

struct Node* deleteNode(struct Node* node, int val) {
    if (!node) return NULL;

    if (val < node->data) node->left = deleteNode(node->left, val);
    else if (val > node->data) node->right = deleteNode(node->right, val);
    else {
        if (!node->left || !node->right) {
            struct Node* temp = node->left ? node->left : node->right;
            free(node);
            return temp;
        } else {
            struct Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
    }

    return balancing(node);
}

int search(struct Node* node, int val) {
    if (!node) return 0;
    if (node->data == val) return 1;
    if (val < node->data) return search(node->left, val);
    return search(node->right, val);
}

void Inorder(struct Node* node) {
    if (!node) return;
    Inorder(node->left);
    printf("%d ", node->data);
    Inorder(node->right);
}

void Preorder(struct Node* node) {
    if (!node) return;
    printf("%d ", node->data);
    Preorder(node->left);
    Preorder(node->right);
}

void Postorder(struct Node* node) {
    if (!node) return;
    Postorder(node->left);
    Postorder(node->right);
    printf("%d ", node->data);
}

struct AVL {struct Node* root;};

int main() {
    struct AVL tree;
    tree.root = NULL;

    printf("AVL Tree Operations:\n1. Insert\n2. Search\n3. Delete\n4. Height\n5. Inorder\n6. Preorder\n7. Postorder\n");

    while (1) {
        int choice, val;
        printf("\nEnter Tree Operation: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to Insert: ");
            scanf("%d", &val);
            tree.root = insert(tree.root, val);
            printf("Inserted %d\n", val);
        } else if (choice == 2) {
            printf("Enter value to Search: ");
            scanf("%d", &val);
            printf("%d %s\n", val, search(tree.root, val) ? "Found." : "Not Found.");
        } else if (choice == 3) {
            printf("Enter value to Delete: ");
            scanf("%d", &val);
            tree.root = deleteNode(tree.root, val);
            printf("Deleted %d\n", val);
        } else if (choice == 4) {
            printf("Height of the tree: %d\n", getHeight(tree.root));
        } else if (choice == 5) {
            printf("Inorder: ");
            Inorder(tree.root);
            printf("\n");
        } else if (choice == 6) {
            printf("Preorder: ");
            Preorder(tree.root);
            printf("\n");
        } else if (choice == 7) {
            printf("Postorder: ");
            Postorder(tree.root);
            printf("\n");
        } else printf("Invalid choice. Try again.\n");
    }

    return 0;
}