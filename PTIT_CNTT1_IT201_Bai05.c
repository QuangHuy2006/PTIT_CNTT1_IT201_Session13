#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

int scanValue(struct Node *head, int value, int arr[], int arrCnt) {
    int count = 0;
    struct Node *current = head;
    while (current != NULL) {
        count++;
        if (current->data == value) {
            arr[arrCnt++] = count;
        }
        current = current->next;
    }
    return arrCnt;
}

void deleteValue(struct Node *head, int arr[], int arrCnt) {
    struct Node *temp = head;
    for (int i = 0; i < arrCnt; i++) {
        for (int j = 1; j < arr[i] - 1; j++) {
            if (temp == NULL) break;
            temp = temp->next;
        }
        if (arr[i] == 1 ) {
            struct Node *newTemp = head;
            for (int j = 1; j < 2; j++) {
                if (newTemp == NULL) break;
                newTemp = newTemp->next;
            }
            struct Node *current = newTemp->prev;
            newTemp->prev = current->prev;
            free(current);
            for (int e = 0; e < arrCnt; e++) {
                arr[e] -= 1;
            }
        }
        struct Node *current = temp->next;
        temp->next = current->next;
        free(current);
        for (int e = 0; e < arrCnt; e++) {
            arr[e] -= 1;
        }
    }
}

struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void printList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
}

int main() {
    int arrCnt = 0;
    int arr[100];
    int value;
    printf("Nhap gia tri can tim kiem: ");
    scanf("%d", &value);
    struct Node *node1 = createNode(1);
    struct Node *node2 = createNode(2);
    struct Node *node3 = createNode(3);
    struct Node *node4 = createNode(4);
    struct Node *node5 = createNode(2);
    node1->prev = NULL;
    node2->prev = node1;
    node3->prev = node2;
    node4->prev = node3;
    node5->prev = node4;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;
    arrCnt = scanValue(node1, value, arr, 0);
    deleteValue(node1, arr, arrCnt);
    printList(node1);
}
