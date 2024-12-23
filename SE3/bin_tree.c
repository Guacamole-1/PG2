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

    if(*rootPtr == NULL){
        *rootPtr = malloc(sizeof(TNode));
        (*rootPtr)->word = namWord;
        (*rootPtr)->left = NULL;
        (*rootPtr)->right = NULL;
        (*rootPtr)->head = NULL;
        lRefAdd(&(*rootPtr)->head, ref); 
        return;
    }

    if( strcmp_ic(namWord, (*rootPtr)->word) == 0 ){
        lRefAdd(&(*rootPtr)->head, ref);
        return;
    }

    if (strcmp_ic(namWord, (*rootPtr)->word) < 0){
        bstAdd(&(*rootPtr)->left,namWord,ref);
    }
    else if (strcmp_ic(namWord, (*rootPtr)->word) == 1){
        bstAdd(&(*rootPtr)->right,namWord,ref);
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

void binTreeStart(TNode **root, VecBookRef *vec){

    char *temp1;
    for(int i = 0; i < vecRefSize(vec); i++){
        
        Book *book = vecRefGet(vec, i);
        char *authors = malloc(strlen(book->authors)+1);
        strcpy(authors,book->authors);
        
        removeComma(authors);

        temp1 = strtok(authors, " ");
   
        while( temp1 != NULL ) {
            bstAdd(root, temp1, book);
            temp1 = strtok(NULL, " ");
        }
    }
    bstBalance(root);

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

