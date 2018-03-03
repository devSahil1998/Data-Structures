#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define DEBUG
#undef DEBUG
#define DEBUGING
#undef DEBUGING
struct BST {
    struct BST* leftLink;
    struct BST* rightLink;
    int data;
};
typedef struct BST bst;
typedef bst *treeNode;
bool insertNode(treeNode* , int );
bool isEmpty(treeNode);
bool searchTree(treeNode* ,int );
size_t depth (treeNode* , int );
#ifdef DEBUG
int main (void) {
    treeNode t1 = NULL;
    if (insertNode (&t1, 2))
        printf("%s", "2 is inserted to the tree");
    puts("");
    if (insertNode (&t1, 4))
        printf("%s", "4 is inserted to the tree");
    puts("");
    if (insertNode (&t1, 3))
        printf("%s", "3 is inserted to the tree");
    puts("");
    if (searchTree (&t1, 4))
        printf("%s", "4 is found in this tree");
    puts("");
    if (searchTree (&t1, 7))
        printf("%s", "7 is found in this tree");
    else
        printf("%s", "7 is not found in this tree");
    puts("");
    printTree (&t1, 0);
    puts("");
    printf("%u", depth(&t1, 0));
    return 0;
}
#endif // DEBUG
bool insertNode(treeNode* root, int value) {
    if (isEmpty(*root)) {
        #ifdef DEBUGING
        printf("Then i ran");
        #endif // DEBUG
        treeNode newNode = malloc(sizeof(bst));
        if (newNode == NULL)
            return false;
        newNode -> data = value;
        newNode -> leftLink = NULL;
        newNode -> rightLink = NULL;
        (*root) = newNode;
        return true;
    }
    else {
        #ifdef DEBUGING
        printf("Am running");
        #endif // DEBUG
        if (value < (*root) -> data)
            return insertNode(&((*root) -> leftLink), value);
        else if (value > (*root) -> data)
            return insertNode(&((*root) -> rightLink), value);
        else
            return false;
    }
}
size_t depth (treeNode* root, int var) {
    static size_t count = 0;
    while (!isEmpty(*root)) {
        if ((((*root) -> leftLink == NULL) && (*root) -> rightLink == NULL))
            return count;
        var++;
        depth (&((*root) -> leftLink), var);
        if (count < var)
            count = var;
        depth (&((*root) -> rightLink), var);
        if (count < var)
            count = var;
        return count;
    }
    return count;
}
bool searchTree (treeNode* root, int value) {
    if (isEmpty(*root))
        return false;
    else {
        if ((*root) -> data == value)
            return true;
        else if ((*root) -> data < value)
            return searchTree (&((*root) -> rightLink), value);
        else if ((*root) -> data > value)
            return searchTree (&((*root) -> leftLink), value);
    }
}
void printTree(treeNode* root, int totalSpaces) {
    while (!isEmpty(*root)) {
        //printf("%d  ", (*root) -> data);
        printTree(&((*root) -> rightLink), totalSpaces + 5);
        size_t i;
        for (i = 0;i < totalSpaces;++i) {
            printf("%c", ' ');
        }
        printf("%d", (*root) -> data);
        puts("");
        printTree(&((*root) -> leftLink), totalSpaces + 5);
        return;
    }
}
bool isEmpty(treeNode root) {
    if (root == NULL)
        return true;
    else
        return false;
}
