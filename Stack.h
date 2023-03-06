//
// Created by noah- on 2/26/2023.
//

#ifndef C_DATASTRUCTURES_STACK_H
#define C_DATASTRUCTURES_STACK_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Stack {
    int top;
    int* head;
} Stack;

Stack* createStack(int size) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = 0;
    stack->head = (int*) malloc(size);
    return stack;
}

void destroyStack(Stack* stack) {
    free(stack->head);
    free(stack);
}

void push(int add, Stack* stack) {
    if (sizeof(stack->head) == stack->top) {
        stack->head = (int *) realloc(stack->head, stack->top * 2);
    }
    int* oldLocation = stack->head;
    int* newLocation = (oldLocation += stack->top + 1);
    *newLocation = add;
    stack->top += 1;
    return;
}



int peek(Stack* stack) {
    if (stack->top == 0) {
        printf("No items in stack");
        return -1;
    }
    int* location = stack->head;
    location += stack->top;
    return *location;
}

int pop(Stack* stack) {
    if (stack->top == 0) {
        printf("No items in stack\n");
        return -1;
    }
    int* head = stack->head;
    head += stack-> top;
    int removing = *(head);
    head = 0;
    stack->top -= 1;
    return removing;
}

int get(Stack* stack, int index) {
    if (index > stack->top) {
        printf("Index greater than stack size\n");
        exit(EXIT_FAILURE);
    }
    int* location = stack->head;
    location += index;
    return *location;
}

int set(Stack* stack, int index, int value) {
    if (index > stack->top) {
        printf("Index greater than stack size\n");
        exit(EXIT_FAILURE);
    }
    int* location = stack->head;
    location += index;
    *location = value;
    return value;
}

#endif //C_DATASTRUCTURES_STACK_H
