#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;      // Mảng động chứa phần tử stack
    int top;       // Vị trí đỉnh stack
    int cap;       // Dung lượng tối đa
} Stack;

// Hàm khởi tạo stack
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
        printf("No elements in the stack");
        return -1;
    }
    return stack->arr[stack->top];
}

void printStack(Stack *stack) {

    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }

}
void reversedStack(Stack *stack) {
    for (int i = 0 ; i < stack->cap / 2; i++) {
        int temp = stack->arr[i];
        stack->arr[i] = stack->arr[stack->cap - i - 1];
        stack->arr[stack->cap - i - 1] = temp;
    }
}
int main() {
    Stack *s = createStack(5);
    for (int i = 0; i < 5; i++) {
        int value;
        scanf("%d", &value);
        push(s, value);
    }
    printf("Before reversed: ");
    printStack(s);
    reversedStack(s);
    printf("After reversed: ");
    printStack(s);

    return 0;
}
