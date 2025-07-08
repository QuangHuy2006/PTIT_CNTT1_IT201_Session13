#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

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
        printf("data: %d\n", current->data);
        current = current->next;
    }
}

int main() {
    struct Node *node1 = createNode(1);
    struct Node *node2 = createNode(2);
    struct Node *node3 = createNode(3);
    struct Node *node4 = createNode(4);
    struct Node *node5 = createNode(5);
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
    printList(node1);
}
