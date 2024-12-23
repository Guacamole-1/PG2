// Bruno Soares 51832 
// Duarte Santos 51764
// Pedro Alves 51451

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../SE1/prog22.h"
#include "../SE1/prog24.h"
#include "vecs.h"
#include "linked_list.h"


int lRefAdd(LNode **headPtr, Book *ref) {

    LNode *scoutptr = *headPtr;
    while (scoutptr != NULL) {
        if (strcmp(scoutptr->ref->title, ref->title) == 0) {
            return 0;
        }
            scoutptr = scoutptr->next;
    }

    if(*headPtr == NULL){
        LNode *newNode = malloc(sizeof(LNode));
        newNode->ref = ref;
        newNode->next = NULL;
        *headPtr = newNode;
        return 1;
    }else{
        scoutptr = *headPtr;
        return lRefAdd(&scoutptr->next, ref);
    }
    
    return 1;
}

void lRefPrint( LNode *head ){
    LNode *current = head;

    while(current != NULL){
    printf("%s;%s;%s;%s\n",current->ref->title,current->ref->isbn,current->ref->authors,current->ref->publisher);
    current = current->next;
    }   
}

void lRefFree( LNode *head){

    LNode *ptr = head;

    while(head != NULL){
    ptr = head;
    head = head->next;
    
    free(ptr);
    
    }

}
