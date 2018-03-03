#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define DEBUG
#undef DEBUG
struct stack {
    int data;
    struct stack *nextPtr;
    size_t length;
};
typedef struct stack Stack;
typedef Stack *stack;
bool push(stack* , int );
bool pop(stack* );
#ifdef DEBUG
int main (void) {
    stack s1 = NULL;
    if (push(&s1, 2))
        printf("%d%s", top(s1), " is pushed onto the stack.");
    puts("");
    if (push(&s1, 3))
        printf("%d%s", top(s1), " is pushed onto the stack.");
    puts("");
    printf("%d%s", len(&s1), " is the length of the stack.");
    puts("");
    printStack(&s1);
    puts("");
    if (pop(&s1))
        printf("%d%s", top(s1), " is the top element now.");
    puts("");
    printf("%d%s", len(&s1), " is the length of the stack.");
    puts("");
    printStack(&s1);
    return 0;
}
#endif // DEBUG
bool push(stack* topPtr, int value) {
    stack newNode = malloc(sizeof(Stack));
    if (newNode != NULL) {
        newNode -> data = value;
        newNode -> nextPtr = NULL;
        newNode -> length = 0;
    }
    else
        return false;
    if (top(*topPtr) == -1){
        *topPtr = newNode;
        newNode -> length = 1;
    }
    else {
        newNode -> length = ((*topPtr) -> length) + 1;
        newNode -> nextPtr = *topPtr;
        *topPtr = newNode;
    }
    return true;
}
bool pop(stack* topPtr) {
    if(top(*topPtr) == -1)
        return false;
    else {
        stack tempPtr;
        if ((*topPtr) -> nextPtr == NULL) {
            tempPtr = (*topPtr);
            *topPtr = NULL;
            free(tempPtr);
            tempPtr = NULL;
        }
        else {
            tempPtr = *topPtr;
            *topPtr = (*topPtr) -> nextPtr;
            free(tempPtr);
            tempPtr = NULL;
        }
        return true;
    }
}
int top(stack topPtr) {
    if (topPtr == NULL)
        return -1;
    else
        return topPtr -> data;
}
size_t len(stack* topPtr) {
    if (top(*topPtr) == -1)
        return 0;
    else
        return (*topPtr) -> length;
}
void printStack(stack* topPtr) {
    stack prevPtr, NextPtr;
    prevPtr = NULL;
    NextPtr = *topPtr;
    while(NextPtr != NULL) {
        prevPtr = NextPtr;
        printf("%d%s", NextPtr -> data, "  ");
        NextPtr = NextPtr -> nextPtr;
    }
}
