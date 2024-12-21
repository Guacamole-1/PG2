#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "../SE1/prog22.h"
#include "../SE1/prog24.h"
#include "vecs.h"
#include "linked_list.h"
#include "bin_tree.h"

TNode *binTreeStart(VecBookRef *vec){

    TNode *root = (TNode *)malloc(sizeof(TNode));
    Book *temp;

    const char *sepAuth = ",";
    const char *sep = " ";
    char *rest;
    char *rest1;
    char temp1;

    for(int i = 0; i <= vecRefSize(vec); i++){
        temp = vecRefGet(vec, i);
        
        temp1 = temp->authors;

        rest = strtok(temp1,sepAuth);
        while(temp1 != NULL){

            while(temp1 != NULL){

                rest1 = strtok(temp1,sep);

                bstAdd(root, temp1, temp);

                temp1 = rest1;
            }
            temp1 = rest;
            rest = strtok(temp1,sepAuth);
        }
    }

    return root;
}