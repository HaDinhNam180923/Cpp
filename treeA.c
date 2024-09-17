#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa cấu trúc Node cho cây nhị phân tìm kiếm
typedef struct Node {
    char name[50];
    char email[50];
    struct Node *left;
    struct Node *right;
} Node;

// Hàm tạo một Node mới
Node *createNode(char name[], char email[]) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->email, email);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Hàm chèn một Node vào cây nhị phân tìm kiếm
Node *insertNode(Node *root, char name[], char email[]) {
    if (root == NULL) {
        return createNode(name, email);
    }

    int compareResult = strcmp(name, root->name);

    if (compareResult < 0) {
        root->left = insertNode(root->left, name, email);
    } else if (compareResult > 0) {
        root->right = insertNode(root->right, name, email);
    }

    return root;
}

// Hàm tìm kiếm một Node trong cây nhị phân tìm kiếm
Node *searchNode(Node *root, char name[]) {
    if (root == NULL || strcmp(name, root->name) == 0) {
        return root;
    }

    if (strcmp(name, root->name) < 0) {
        return searchNode(root->left, name);
    }

    return searchNode(root->right, name);
}

// Hàm hiển thị danh sách hồ sơ sinh viên
void displayTree(Node *root) {
    if (root != NULL) {
        displayTree(root->left);
        printf("Name: %s, Email: %s\n", root->name, root->email);
        displayTree(root->right);
    }
}

// Hàm lưu trữ cây nhị phân tìm kiếm vào một file văn bản
void storeTreeToFile(Node *root, FILE *file) {
    if (root != NULL) {
        storeTreeToFile(root->left, file);
        fprintf(file, "%s %s\n", root->name, root->email);
        storeTreeToFile(root->right, file);
    }
}

// Hàm giải phóng bộ nhớ của cây nhị phân tìm kiếm
void freeTree(Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node *root = NULL;
    char command[20];
    char filename[50];
    char name[50];
    char email[50];

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "Load") == 0) {
            printf("Enter filename: ");
            scanf("%s", filename);

            FILE *file = fopen(filename, "r");
            if (file == NULL) {
                printf("Error opening file!\n");
            } else {
                while (fscanf(file, "%s %s", name, email) == 2) {
                    root = insertNode(root, name, email);
                }
                fclose(file);
                printf("Data loaded successfully!\n");
            }
        } else if (strcmp(command, "Find") == 0) {
            printf("Enter student name: ");
            scanf("%s", name);
            Node *result = searchNode(root, name);
            if (result != NULL) {
                printf("Name: %s, Email: %s\n", result->name, result->email);
            } else {
                printf("Student not found.\n");
            }
        } else if (strcmp(command, "Insert") == 0) {
            printf("Enter student name: ");
            scanf("%s", name);
            printf("Enter student email: ");
            scanf("%s", email);
            root = insertNode(root, name, email);
            printf("Student profile inserted.\n");
        } else if (strcmp(command, "Remove") == 0) {
            printf("Enter student name: ");
            scanf("%s", name);
            // Implement the remove operation based on your specific requirements
            // (e.g., deletion in BST)
            printf("Student removed.\n");
        } else if (strcmp(command, "Store") == 0) {
            printf("Enter filename: ");
            scanf("%s", filename);

            FILE *file = fopen(filename, "w");
            if (file == NULL) {
                printf("Error opening file!\n");
            } else {
                storeTreeToFile(root, file);
                fclose(file);
                printf("Data stored successfully!\n");
            }
        } else if (strcmp(command, "Quit") == 0) {
            // Cleanup and exit the program
            freeTree(root);
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}
