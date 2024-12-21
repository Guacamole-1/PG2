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


void binTreeStart(TNode *root, VecBookRef *vec){

    Book *temp;

    const char *sepAuth = ",";
    const char *sep = " ";
    char *rest = malloc(500);
    char *rest1 = malloc(500);
    char *authors = malloc(500);

    for(int i = 0; i <= vecRefSize(vec); i++){
        
        temp = vecRefGet(vec, i);
        
        strcpy(authors,temp->authors);
        strcpy(rest,authors);

        strtok(authors,sepAuth);
        
        while(authors != NULL){

            while(authors != NULL){

                strtok(authors,sep);

                bstAdd(&root, authors, temp);

                authors = rest1;
            }
            authors = rest;
            rest = strtok(authors,sepAuth);
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

