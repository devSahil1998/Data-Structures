//Doubly Linked Lists
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define DEBUG
#undef DEBUG
struct linkedList{
    struct linkedList *nextPtr;
    struct linkedList *prevPtr;
    int data;
};
typedef struct linkedList LinkedList;
typedef LinkedList *linkedList;
bool insertNode (linkedList *, linkedList *, int);
bool deleteNode (linkedList *, linkedList *, int);
void printList (linkedList *);
void printReversedList (linkedList *);
bool isEmpty(linkedList *);
#ifdef DEBUG
    int main (void) {
    linkedList *l1, *l2;
    l1 = (l2 = NULL);
    if (insertNode(&l1, &l2, 2))
        puts("2 is added");
    printList(&l1);
    puts("");
    printReversedList(&l2);
    puts("");
    if (insertNode(&l1, &l2, 3))
        puts("3 is added");
    printList(&l1);
    puts("");
    printReversedList(&l2);
    puts("");
    if (insertNode(&l1, &l2, 4))
        puts("4 is added");
    printList(&l1);
    puts("");
    printReversedList(&l2);
    puts("");
    if (insertNode(&l1, &l2, 1))
        puts("1 is added");
    printList(&l1);
    puts("");
    printReversedList(&l2);
    puts("");
    if (deleteNode(&l1, &l2, 2))
        puts("2 is deleted");
    printList(&l1);
    puts("");
    if (deleteNode(&l1, &l2, 4))
        puts("4 is deleted");
    printList(&l1);
    puts("");
    printReversedList(&l2);
    puts("");
    if (deleteNode(&l1, &l2, 1))
        printList(&l1);
    puts("");
    printReversedList(&l2);
    puts("");
    if (deleteNode (&l1, &l2, 3))
        printList(&l1);
    puts("");
    printReversedList(&l2);
return 0;
}
#endif // DEBUG
bool insertNode(linkedList *start, linkedList *end, int value) {
    linkedList newNode = malloc (sizeof (LinkedList));
    if (newNode != NULL) {
        newNode -> nextPtr = NULL;
        newNode -> prevPtr = NULL;
        newNode -> data = value;
    }
    else
        return false;
    linkedList PreviousPtr = NULL, NextPtr = *start;
    while (NextPtr != NULL && (NextPtr -> data) < value) {
        PreviousPtr = NextPtr;
        NextPtr = NextPtr -> nextPtr;
    }
    if (PreviousPtr == NULL) {
        if(isEmpty(start)) {
            *end = (*start = newNode);
            newNode -> nextPtr = NULL;
            newNode -> prevPtr = NULL;
        }
        else {
            newNode -> nextPtr = *start;
            (*start) -> prevPtr = newNode;
            newNode -> prevPtr = NULL;
            *start = newNode;
        }
    }
    else
    {
        if (NextPtr != NULL) {
            PreviousPtr -> nextPtr = newNode;
            newNode -> prevPtr = PreviousPtr;
            newNode -> nextPtr = NextPtr;
            NextPtr -> prevPtr = newNode;
        }
        else {
            PreviousPtr -> nextPtr = newNode;
            newNode -> prevPtr = PreviousPtr;
            newNode -> nextPtr = NextPtr;
            *end = newNode;
        }
        return true;
    }
}
bool deleteNode(linkedList *start, linkedList *end, int value) {
    if(isEmpty(start))
        return false;
    else {
        linkedList PreviousPtr = NULL, NextPtr = *start, TempPtr;
        while (NextPtr != NULL && (NextPtr -> data) != value) {
            PreviousPtr = NextPtr;
            NextPtr = NextPtr -> nextPtr;
        }
        if (NextPtr -> data == value) {
            if (PreviousPtr == NULL) {
                if (*start == *end) {
                    TempPtr = *start;
                    *end = (*start = (NextPtr = NULL));
                    free(TempPtr);
                    TempPtr = NULL;
                }
                else {
                    TempPtr = *start;
                    *start = (*start) -> nextPtr;
                    (*start) -> prevPtr = NULL;
                    free(TempPtr);
                    TempPtr = (NextPtr = NULL);
                }
                return true;
            }
            else {
                if (NextPtr != *end) {
                    PreviousPtr -> nextPtr = (NextPtr -> nextPtr);
                    (NextPtr -> nextPtr) -> prevPtr = PreviousPtr;
                    TempPtr = NextPtr;
                    free(TempPtr);
                    TempPtr = (NextPtr = NULL);
                }
                else {
                    PreviousPtr -> nextPtr = (NextPtr -> nextPtr);
                    TempPtr = NextPtr;
                    *end = PreviousPtr;
                    free(TempPtr);
                    TempPtr = (NextPtr = NULL);
                }
                return true;
            }
        }
        else
            return false;
    }
}
void printList(linkedList *start) {
    linkedList PreviousPtr = NULL, NextPtr = *start;
    if (isEmpty(start))
        printf("%s", "The Linked List Is Empty");
    else {
        while (NextPtr != NULL) {
            PreviousPtr = NextPtr;
            printf("%d%s", (NextPtr -> data), " -> ");
            NextPtr = NextPtr -> nextPtr;
        }
        printf("NULL");
    }
    PreviousPtr = NULL;
    NextPtr = NULL;
}
void printReversedList(linkedList *end) {
    linkedList PreviousPtr = NULL, NextPtr = *end;
    if ( isEmpty(end) )
        printf("%s", "The Linked List Is Empty");
    else {
        while (NextPtr != NULL) {
            PreviousPtr = NextPtr;
            printf("%d%s", (NextPtr -> data), " -> ");
            NextPtr = NextPtr -> prevPtr;
        }
        printf("NULL");
    }
    PreviousPtr = NULL;
    NextPtr = NULL;
}
bool isEmpty (linkedList *l) {
    if ((*l) == NULL)
        return true;
    else
        return false;
}
