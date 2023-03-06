//
// Created by noah- on 2/26/2023.
//

#ifndef C_DATASTRUCTURES_QUEUE_H
#define C_DATASTRUCTURES_QUEUE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Queue {
    int top;
    int* head;
} Queue;

Queue* createQueue(int size) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->top = 0;
    queue->head = (int*) malloc(size);
}

int add(int add, Queue* queue) {
    if (queue->top == sizeof(queue->head)) {
        queue->head = (int*) realloc(queue->head,2 * sizeof(queue->head));
        return 0;
    }
    int* location = queue->head;
    location += queue->top + 1;
    *location = add;
    queue->top++;
    return 1;
}

int qRemove(Queue* queue) {
    if (queue->top == 0) {
        printf("No items in Queue\n");
        return -1;
    }
    int* location = queue->head;
    location += 1;
    int removing = *location;
    for (int i = 1; i < queue->top; i++) {
        int * oLocation = queue->head;
        oLocation += i + 1;
        *location = *oLocation;
        location = oLocation;
    }
    return removing;
}

int qPeek(Queue* queue) {
    if (queue->top == 0) {
        printf("No items in queue\n");
        return -1;
    }
    int* location = queue->head;
    location += 1;
    return *location;
}

void destroyQueue(Queue* queue) {
    free(queue->head);
    free(queue);
}
#endif //C_DATASTRUCTURES_QUEUE_H
