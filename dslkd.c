#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa cấu trúc Node cho danh sách liên kết đơn
typedef struct Node {
    char name[50];
    char email[50];
    struct Node *next;
} Node;

// Hàm tạo một Node mới
Node *createNode(char name[], char email[]) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->email, email);
    newNode->next = NULL;
    return newNode;
}

// Hàm chèn một Node vào cuối danh sách liên kết đơn
Node *insertNode(Node *head, char name[], char email[]) {
    Node *newNode = createNode(name, email);

    if (head == NULL) {
        return newNode;
    }

    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Hàm tìm kiếm một Node trong danh sách liên kết đơn
Node *searchNode(Node *head, char name[]) {
    Node *current = head;

    while (current != NULL) {
        if (strcmp(name, current->name) == 0) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

// Hàm xóa một Node khỏi danh sách liên kết đơn
Node *removeNode(Node *head, char name[]) {
    Node *current = head;
    Node *prev = NULL;

    while (current != NULL) {
        if (strcmp(name, current->name) == 0) {
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                // Nếu nút cần xóa là nút đầu tiên
                head = current->next;
            }
            free(current);
            break;
        }

        prev = current;
        current = current->next;
    }

    return head;
}

// Hàm hiển thị danh sách liên kết đơn
void displayList(Node *head) {
    Node *current = head;

    while (current != NULL) {
        printf("Name: %s, Email: %s\n", current->name, current->email);
        current = current->next;
    }
}

// Hàm lưu trữ danh sách liên kết đơn vào một file văn bản
void storeListToFile(Node *head, FILE *file) {
    Node *current = head;

    while (current != NULL) {
        fprintf(file, "%s %s\n", current->name, current->email);
        current = current->next;
    }
}

// Hàm giải phóng bộ nhớ của danh sách liên kết đơn
void freeList(Node *head) {
    Node *current = head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Node *head = NULL;
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
                    head = insertNode(head, name, email);
                }
                fclose(file);
                printf("Data loaded successfully!\n");
            }
        } else if (strcmp(command, "Find") == 0) {
            printf("Enter student name: ");
            scanf("%s", name);
            Node *result = searchNode(head, name);
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
            head = insertNode(head, name, email);
            printf("Student profile inserted.\n");
        } else if (strcmp(command, "Remove") == 0) {
            printf("Enter student name: ");
            scanf("%s", name);
            head = removeNode(head, name);
            printf("Student removed.\n");
        } else if (strcmp(command, "Store") == 0) {
            printf("Enter filename: ");
            scanf("%s", filename);

            FILE *file = fopen(filename, "w");
            if (file == NULL) {
                printf("Error opening file!\n");
            } else {
                storeListToFile(head, file);
                fclose(file);
                printf("Data stored successfully!\n");
            }
        } else if (strcmp(command, "Quit") == 0) {
            // Cleanup and exit the program
            freeList(head);
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}
