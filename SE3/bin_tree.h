#ifndef BIN_TREE_H
#define BIN_TREE_H
#include "vecs.h"
typedef struct lNode{ 
 struct lNode *next; // ligação na lista 
 Book *ref; // referência de acesso a um descritor de livro 
} LNode; 
#endif