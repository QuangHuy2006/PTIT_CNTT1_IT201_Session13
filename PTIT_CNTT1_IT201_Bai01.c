#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int top;
    int cap;
} Stack;

Stack* createStack(int capacity) {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    if (!stack) {
        return 0;
    }

    stack->cap = capacity;
    stack->top = -1;
    stack->arr = (int*) malloc(capacity * sizeof(int));
    if (!stack->arr) {
        return 0;
    }

    return stack;
}

int isFull(Stack *stack) {
    return stack->top == stack->cap - 1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int value) {
    if (isFull(stack)) {
        return;
    }
    stack->top += 1;
    stack->arr[stack->top] = value;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek(Stack *stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->arr[stack->top];
}

void printStack(Stack *stack) {
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
}
int main() {
    Stack *s = createStack(5);

    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);

    printStack(s);

    return 0;
}
