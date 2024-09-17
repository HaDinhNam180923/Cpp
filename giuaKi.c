#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node LIST;
LIST *L;

int generate() {
    return rand() % 201 - 100; // Sinh số nguyên trong khoảng [-100, 100]
}

LIST* createList(int n) {
    LIST dummy;
    LIST *current = &dummy;

    for (int i = 1; i <= n; ++i) {
        LIST *newNode = (LIST *)malloc(sizeof(LIST));
        newNode->data = generate();
        newNode->next = NULL;

        current->next = newNode;
        current = newNode;
    }

    return dummy.next; // Return the next pointer of the dummy node
}


int count(LIST *L) {
    int countEven = 0;
    LIST *current = L->next;

    while (current != NULL) {
        if (current->data % 2 == 0) {
            countEven++;
        }
        current = current->next;
    }

    return countEven;
}

void deleteEven(LIST *L) {
    LIST *current = L;
    while (current->next != NULL) {
        if (current->next->data % 2 == 0) {
            LIST *temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

void sort(LIST *L) {
    int swapped;
    LIST *ptr1;
    LIST *lptr = NULL;

    // Check for empty list
    if (L->next == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = L->next;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap the data of the nodes
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void display(LIST *L) {
    LIST *current = L->next;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    int choice, n;

    do {
        printf("\nMenu:\n");
        printf("1. Tạo danh sách\n");
        printf("2. Hiển thị số lượng phần tử chẳn trong danh sách\n");
        printf("3. Xóa các phần tử chẵn khỏi danh sách\n");
        printf("4. Sắp xếp danh sách tăng dần\n");
        printf("5. Hiển thị danh sách\n");
        printf("6. Quit\n");
        printf("Chọn: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhập số lượng phần tử: ");
                scanf("%d", &n);
                L = createList(n);
                printf("Danh sách đã được tạo.\n");
                break;

            case 2:
                printf("Số lượng phần tử chẵn trong danh sách: %d\n", count(L));
                break;

            case 3:
                deleteEven(L);
                printf("Các phần tử chẵn đã được xóa khỏi danh sách.\n");
                break;

            case 4:
                sort(L);
                printf("Danh sách đã được sắp xếp tăng dần.\n");
                break;

            case 5:
                printf("Danh sách: ");
                display(L);
                break;

            case 6:
                printf("Thoát chương trình.\n");
                break;

            default:
                printf("Chọn không hợp lệ. Vui lòng chọn lại.\n");
        }
    } while (choice != 6);

    return 0;
}
