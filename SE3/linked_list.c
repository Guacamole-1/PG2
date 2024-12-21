// Bruno Soares 51832 
// Duarte Santos 51764
// Pedro Alves 51451

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vecs.h"
#include "linked_list.h"

int lRefAdd( LNode **headPtr, Book *ref ){
    
    LNode *scoutNode = *headPtr;
    
    while(1){
        
        if(scoutNode != NULL && scoutNode->ref == ref){
            return 0;
        }    
        if (scoutNode == NULL){
            scoutNode = malloc(sizeof(LNode));
            scoutNode->ref = ref;
            return 1;
       }
       scoutNode = scoutNode->next;
    } 
    return 1;
}

void lRefPrint( LNode *head ){
    
    printf("%s;%s;%s;%s\n",head->ref->title,head->ref->isbn,head->ref->authors,head->ref->publisher);

}

void lRefFree( LNode *head){

    LNode *ptr = head;

    while(head != NULL){
    head = head->next;
    free(ptr);
    ptr = head;
    }

}
