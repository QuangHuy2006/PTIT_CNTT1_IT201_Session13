#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int findValue(struct Node *head, int count) {
    struct Node *temp = head;
    for (int i = 0; i < count / 2; i++) {
        if (temp == NULL) break;
        temp = temp->next;
    }
    return temp->data;
}

int scan(int count, struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        if (current->data) {
            count++;
        }
        current = current->next;
    }
    return count;
}

void printList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
}

int main() {
    struct Node *node1 = createNode(1);
    struct Node *node2 = createNode(2);
    struct Node *node3 = createNode(3);
    struct Node *node4 = createNode(4);
    struct Node *node5 = createNode(5);
    struct Node *node6 = createNode(6);
    node1->prev = NULL;
    node2->prev = node1;
    node3->prev = node2;
    node4->prev = node3;
    node5->prev = node4;
    node6->prev = node5;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = NULL;
    int count = scan(0, node1);
    double cnt = scan(0, node1);
    if (count % 2 == 0) {
        printf("Node %.0lf: %d", ceil(cnt / 2) + 1,findValue(node1, count));
    }else {
        printf("Node %.0lf: %d", ceil(cnt / 2), findValue(node1, count));
    }
}
