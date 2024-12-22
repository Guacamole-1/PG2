#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "../SE1/prog22.h"
#include "../SE1/prog24.h"
#include "vecs.h"
#include "bin_tree.h"
#include "linked_list.h"


TNode *treeToSortedList( TNode *r, TNode *link ){

    TNode * p;
    if( r == NULL ) return link;

    p = treeToSortedList( r->left, r );
    r->left = NULL;
    r->right = treeToSortedList( r->right, link );

    return p;
} 

TNode *sortedListToBalancedTree(TNode **listRoot, int n) {
    if( n == 0 )return NULL;

    TNode *leftChild = sortedListToBalancedTree(listRoot, n/2);
    TNode *parent = *listRoot;
    parent->left = leftChild;
    *listRoot = (*listRoot)->right;
    parent->right = sortedListToBalancedTree(listRoot, n-(n/2 + 1) );
    return parent;
} 



void bstAdd( TNode **rootPtr, char *namWord, Book *ref ){

    TNode *scoutptr = *rootPtr;

    
    if(scoutptr->word == NULL){
        TNode *node = (TNode *)malloc(sizeof(TNode));
        node->word = namWord;
        lRefAdd(&scoutptr->head, ref); 
        scoutptr = node;
        return;
    }

    if( strcmp_ic(namWord, (*rootPtr)->word) == 0 ){
        lRefAdd(&scoutptr->head, ref);
        return;
    }

    if (strcmp_ic(namWord, (*rootPtr)->word) < 0){
        bstAdd(& (*rootPtr) ->left,namWord,ref);
    }
    else if (strcmp_ic(namWord, (*rootPtr)->word) == 1){
        bstAdd(& (*rootPtr) ->right,namWord,ref);
    }
    return;
}

void bstBalance( TNode **rootPtr){
    TNode *Nroot; 
    TNode *Scout;
    int n = 0;

    Nroot = treeToSortedList(*rootPtr, NULL);
    
    Scout = Nroot;
    while(Scout->right != NULL){
        n++;
        Scout = Scout->right;
    }

    *rootPtr = sortedListToBalancedTree(&Nroot, n);

}


LNode *bstSearch ( TNode *root, char *namWord ){

    TNode *scout = root;

    if(scout == NULL){
        return NULL;
    }
    if (strcmp_ic(namWord, scout->word) < 0){
        return bstSearch(scout->left,namWord);
    }
    else if (strcmp_ic(namWord, scout->word) == 0){
        return scout->head;
    }
    return bstSearch(scout->right,namWord);  
}

void removeComma(char *str) {
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (str[i] != ',') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

void binTreeStart(TNode *root, VecBookRef *vec){

    Book *book;

    const char *sep = " ";
    char *temp1 = malloc(500);
    char *authors = malloc(500);

    for(int i = 0; i < vecRefSize(vec); i++){
        
        book = vecRefGet(vec, i);
        
        strcpy(authors,book->authors);
        removeComma(authors);

        
        temp1 = strtok(authors, sep);
   
        while( temp1 != NULL ) {
            bstAdd(&root, temp1, book);
            temp1 = strtok(NULL, sep);
        }
    }

}

void bstFree(TNode *root){

    if(root == NULL){
        return;
    }else if((root->left == NULL) && (root->right == NULL)){
        lRefFree(root->head);
        free(root);
    }else{
        bstFree(root->left);
        bstFree(root->right);
    }
    
}

