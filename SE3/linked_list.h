#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct lNode{
 struct lNode *next; // ligação na lista
 Book *ref; // referência de acesso a um descritor de livro
} LNode; 

int lRefAdd( LNode **headPtr, Book *ref ); 

void lRefPrint( LNode *head );

void lRefFree( LNode *head ); 

#endif