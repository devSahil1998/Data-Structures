#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define DEBUG
#undef DEBUG
struct queue {
    int data;
    struct queue *nextPtr;
    size_t length;
};
typedef struct queue Queue;
typedef Queue *queue;
bool enqueue(queue* , queue* , int );
size_t length(queue* , queue* );
bool dequeue(queue* , queue* );
#ifdef DEBUG
int main (void) {
    queue s1 = NULL, s2 = NULL;
    if (enqueue(&s1, &s2, 2))
        printf("%d%s", 2, " Is Enqueued Into The Queue.");
    puts("");
    if (enqueue(&s1, &s2 , 3))
        printf("%d%s", 3, " Is Enqueued Into The Queue.");
    puts("");
    if (enqueue(&s1, &s2, 4))
        printf("%d%s", 4, " Is Enqueued Into The Queue.");
    puts("");
    printf("%d%s", length(&s1, &s2), " Is The Length Of The Queue");
    puts("");
    printQueue(&s1);
    puts("");
    if (dequeue(&s1, &s2))
        printf("%d%s", length(&s1, &s2), " Is The Length Of The Queue");
    puts("");
    printQueue(&s1);
    puts("");
    if (dequeue(&s1, &s2))
        printf("%d%s", length(&s1, &s2), " Is The Length Of The Queue");
    puts("");
    printQueue(&s1);
    puts("");
    if (dequeue(&s1, &s2))
        printf("%d%s", length(&s1, &s2), " Is The Length Of The Queue");
    puts("");
    printQueue(&s1);
    return 0;
}
#endif // DEBUG
bool enqueue(queue* start, queue* end, int value) {
    queue newNode = malloc(sizeof(Queue));
    if (newNode != NULL) {
        newNode -> data = value;
        newNode -> nextPtr = NULL;
        newNode -> length = 0;
    }
    else
        return false;
    queue prevPtr = NULL, NextPtr = *start;
    while(NextPtr != NULL) {
        prevPtr = NextPtr;
        NextPtr = NextPtr -> nextPtr;
    }
    if (prevPtr == NULL) {
        *end = (*start = newNode);
        newNode -> length = 1;
    }
    else {
        prevPtr -> nextPtr = newNode;
        newNode -> length = (prevPtr -> length) + 1;
        newNode -> nextPtr = NextPtr;
        *end = newNode;
    }
    return true;
}
bool dequeue(queue* start, queue*end) {
    if (firstElement(start) == -1)
        return false;
    else {
        queue tempPtr;
        if ((*start) -> nextPtr == NULL) {
            tempPtr = *start;
            *end = (*start = NULL);
            free(tempPtr);
            tempPtr = NULL;
        }
        else {
            tempPtr = *start;
            *start = (*start) -> nextPtr;
            free(tempPtr);
            tempPtr = NULL;
            queue NextPtr = *start;
            while(NextPtr != NULL) {
                NextPtr -> length = (NextPtr -> length) - 1;
                NextPtr = NextPtr -> nextPtr;
            }
            NextPtr = NULL;
        }
        return true;
    }
}
int firstElement(queue start) {
    if (start == NULL)
        return -1;
    else
        return start -> data;
}
size_t length(queue* start, queue* end) {
    if(firstElement(*start) == -1)
        return 0;
    else
        return (*end) -> length;
}
void printQueue(queue* start) {
    queue NextPtr = *start;
    while (NextPtr != NULL) {
        printf("%d%s", NextPtr -> data, "  ");
        NextPtr = NextPtr -> nextPtr;
    }
}
