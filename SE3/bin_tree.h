#ifndef BIN_TREE_H
#define BIN_TREE_H
#include "linked_list.h"

typedef struct tNode{
 struct tNode *left, *right;
 char *word;
 LNode *head;
} TNode; 

TNode *treeToSortedList( TNode *r, TNode *link );

TNode *sortedListToBalancedTree(TNode **listRoot, int n);

void bstAdd( TNode **rootPtr, char *namWord, Book *ref );

void bstBalance( TNode **rootPtr);

LNode *bstSearch ( TNode *root, char *namWord );

void bstFree(TNode *root);

void removeComma(char *str);

void binTreeStart(TNode **root, VecBookRef *vec);

#endif