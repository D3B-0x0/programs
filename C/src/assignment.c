#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* insert(struct Node* root, int x) {
    if (!root) {
        root = malloc(sizeof(struct Node));
        root->data = x;
        root->left = root->right = NULL;
    }
    else if (x < root->data) root->left = insert(root->left, x);
    else if (x > root->data) root->right = insert(root->right, x);
    return root;
}

struct Node* search(struct Node* root, int x) {
    if (!root || root->data == x) return root;
    return (x < root->data) ? search(root->left, x) : search(root->right, x);
}

void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, x;
    
    while (1) {
        printf("\n1.Insert 2.Search 3.Display 4.Exit\nChoice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("Value: ");
            scanf("%d", &x);
            root = insert(root, x);
        }
        else if (choice == 2) {
            printf("Search: ");
            scanf("%d", &x);
            printf(search(root, x) ? "Found\n" : "Not found\n");
        }
        else if (choice == 3) {
            printf("Tree: ");
            inorder(root);
            printf("\n");
        }
        else break;
    }
    return 0;
}
