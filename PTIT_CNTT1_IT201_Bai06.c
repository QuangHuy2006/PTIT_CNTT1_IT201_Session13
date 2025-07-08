#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **arr; // Mảng động chứa phần tử stack
    int top; // Vị trí đỉnh stack
    int cap; // Dung lượng tối đa
} Stack;

// Hàm khởi tạo stack
Stack *createStack(int capacity) {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    if (!stack) {
        return 0;
    }

    stack->cap = capacity;
    stack->top = -1;
    stack->arr = (char **) malloc(capacity * sizeof(char *));
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

void push(Stack *stack, char value[]) {
    if (isFull(stack)) {
        return;
    }
    stack->top += 1;
    stack->arr[stack->top] = value;
}

char *pop(Stack *stack) {
    if (isEmpty(stack)) {
        return "No elements in the stack";
    }
    return stack->arr[stack->top--];
}

char *peek(Stack *stack) {
    if (isEmpty(stack)) {
        return "No elements in the stack";
    }
    return stack->arr[stack->top];
}

void printStack(Stack *stack) {
    for (int i = stack->top; i > 0; i--) {
        printf("%s ", stack->arr[i]);
    }
}

int checkIfPalindrome(Stack *stack) {
    for (int i = stack->top; i > 0; i--) {
        for (int j = 0; j < strlen(stack->arr[stack->top]) / 2; j++) {
            if (stack->arr[stack->top][j] != stack->arr[stack->top][strlen(stack->arr[stack->top]) - j - 1]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int cap;
    scanf("%d", &cap);
    Stack *s = createStack(cap);
    for (int i = 0; i < cap; i++) {
        char value[100];
        fgets(value, 100, stdin);
        value[strcspn(value, "\n")] = '\0';
        push(s, value);
    }
    if (checkIfPalindrome(s)) {
        printf("True");
    } else {
        printf("False");
    }

    return 0;
}
