#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "../SE1/prog22.h"
#include "../SE1/prog24.h"
#include "vecs.h"
#include "linked_list.h"

typedef struct tNode{
 struct tNode *left, *right;
 char *word;
 LNode *head;
} TNode; 

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

    if( strcmp_ic(namWord, (*rootPtr)->word) == 0 ){
        lRefAdd(&scoutptr->head, ref);
        return;
    }

    if(scoutptr == NULL){
        TNode *node = (TNode *)malloc(sizeof(TNode));
        node->word = namWord;
        lRefAdd(&scoutptr->head, ref);

        node->head->next = NULL;
        node->left = node->right = NULL;     
        
        scoutptr = node;
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


TNode *binTreeStart(TNode *root, VecBookRef *vec){

    Book *temp;

    const char *sepAuth = ",";
    const char *sep = " ";
    char *rest;
    char *rest1;
    char *temp1;

    for(int i = 0; i <= vecRefSize(vec); i++){
        temp = vecRefGet(vec, i);
        
        strcpy(temp1,temp->authors);

        rest = strtok(temp1,sepAuth);
        while(temp1 != NULL){

            while(temp1 != NULL){

                rest1 = strtok(temp1,sep);

                bstAdd(&root, temp1, temp);

                temp1 = rest1;
            }
            temp1 = rest;
            rest = strtok(temp1,sepAuth);
        }
    }

    return root;
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

