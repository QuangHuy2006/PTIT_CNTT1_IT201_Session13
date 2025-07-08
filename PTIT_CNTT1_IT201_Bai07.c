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

int check(Stack *stack) {
    int flag1 = 1;
    int flag2 = 1;
    int flag3 = 1;
    int flag4 = 1;
    int flag5 = 1;
    int flag6 = 1;
    for (int i = 0; i <= stack->top; i++) {
        for (int j = 0; j < strlen(stack->arr[i]); j++) {
            if (stack->arr[i][j] == '(') {
                for (int e = 0; e < strlen(stack->arr[i]); e++) {
                    if (stack->arr[i][e] == ')') {
                        flag1 = 1;
                        break;
                    } else {
                        flag1 = 0;
                    }
                }
            } else if (stack->arr[i][j] == ')') {
                for (int e = 0; e < strlen(stack->arr[i]); e++) {
                    if (stack->arr[i][e] == '(') {
                        flag2 = 1;
                        break;
                    } else {
                        flag2 = 0;
                    }
                }
            } else if (stack->arr[i][j] == '{') {
                for (int e = 0; e < strlen(stack->arr[i]); e++) {
                    if (stack->arr[i][e] == '}') {
                        flag3 = 1;
                        break;
                    } else {
                        flag3 = 0;
                    }
                }
            } else if (stack->arr[i][j] == '}') {
                for (int e = 0; e < strlen(stack->arr[i]); e++) {
                    if (stack->arr[i][e] == '{') {
                        flag4 = 1;
                        break;
                    } else {
                        flag4 = 0;
                    }
                }
            } else if (stack->arr[i][j] == '[') {
                for (int e = 0; e < strlen(stack->arr[i]); e++) {
                    if (stack->arr[i][e] == ']') {
                        flag5 = 1;
                        break;
                    } else {
                        flag5 = 0;
                    }
                }
            } else if (stack->arr[i][j] == ']') {
                for (int e = 0; e < strlen(stack->arr[i]); e++) {
                    if (stack->arr[i][e] == '[') {
                        flag6 = 1;
                        break;
                    } else {
                        flag6 = 0;
                    }
                }
            }
        }
    }
    if (flag1 && flag2 && flag3 && flag4 && flag5 && flag6) {
        return 1;
    }else {
        return 0;
    }
}

int main() {
    int cap;
    scanf("%d", &cap);
    ++cap;
    Stack *s = createStack(cap);
    for (int i = 0; i < cap; i++) {
        char value[100];
        fgets(value, 100, stdin);
        value[strcspn(value, "\n")] = '\0';
        push(s, value);
    }
    if (check(s)) {
        printf("True");
    } else {
        printf("False");
    }

    return 0;
}
