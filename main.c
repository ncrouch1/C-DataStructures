//
// Created by noah- on 2/26/2023.
//

#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"


int main(void) {
    Queue* queue = createQueue(10);
    for (int i = 1; i <= 20; i++) {
        int code = add(i, queue);
        printf("%d added\n", i);
        printf("%d code\n", code);
    }
    for (int i = 0; i < 20; i++) {
        int removed = qRemove(queue);
        printf("%d removed\n", removed);
    }
    destroyQueue(queue);
    return 0;
}