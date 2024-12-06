#include "vecs.h"
#include "../SE1/prog22.h"
#include "../SE1/prog24.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TITULO 0
#define ISBN 1
#define AUTOR 3
#define EDITOR 4



void bookFree( Book *b ){

    free(b->title);
    free(b->authors);
    free(b->publisher);
    free(b);
    
}

int fillBookData( Book *b, const char *line ){
    int pos = 0;
    char *line1 = malloc(strlen(line) + 1);
    char *rest = malloc(strlen(line) + 1);
    strcpy(line1, line);
    do{
            rest = splitField( line1 );
            separatorUnify(line1);
            if (line1 == NULL && (pos == TITULO || pos == ISBN || pos == AUTOR || pos == EDITOR))
            {
                free(line1);
                free(rest);
                bookFree(b);
                return 0;
            }
            
            switch (pos)
            {
            case TITULO:
                b->title = malloc(strlen(line1) + 1);
                strcpy(b->title,line1);
                break;
            case ISBN:
                strcpy(b->isbn, line1);
                break;
            case AUTOR:
                b->authors = malloc(strlen(line1) + 1);
                strcpy(b->authors,line1);
                break;
            case EDITOR:
                b->publisher = malloc(strlen(line1) + 1);
                strcpy(b->publisher,line1);
                break;
            default:
                break;
            }
            pos++;
        }while((line1 = rest) != NULL);
    free(line1);
    free(rest);
    return 1; 
}


Book *bookCreate( const char *line ){
    Book *book = malloc(sizeof(Book));
    if (fillBookData(book,line)){
        return book;
    }   else {
        bookFree(book);
        return NULL;
    }
}

VecBookRef *vecRefCreate ( void ){

    VecBookRef *V = malloc(sizeof(VecBookRef));
    V->refs = malloc(sizeof(Book));
    V->size = 0;
    V->space = 1;
    return V;
}

void vecRefAdd( VecBookRef *vec, Book *ref ){
    
    if(vec->space == vec->size){
        
        vec->refs = realloc(vec->refs,(vec->space)*sizeof(Book));
        vec->space++;
        }
    
    vec->refs[vec->size++] = ref;
}

int vecRefSize( VecBookRef *vec ){
    return vec->size;
} 

Book *vecRefGet( VecBookRef *vec, int index){

    if( vec->size >= index){
        Book* ret = vec->refs[index];
        return ret;
    }

return NULL;
}

int compare_title(const void *str1, const void *str2){
    return strcmp_ic((*(Book **)str1)->title, (*(Book **)str2)->title);
}
int compare_isbn(const void *str1, const void *str2){
    return strcmp_ic((*(Book **)str1)->isbn, (*(Book **)str2)->isbn);
}

void vecRefSortIsbn( VecBookRef *vec ){
    qsort(vec->refs,vec->size,sizeof (vec->refs),compare_isbn);
}

void vecRefSortTitle( VecBookRef *vec ){
    qsort(vec->refs,vec->size,sizeof (vec->refs),compare_title);
}

Book *vecRefSearchIsbn( VecBookRef *vec, char *isbn ){

    if (vec == NULL || strlen(isbn) == 0 || vec->refs == NULL || vec->size == 0) {
        return NULL; // Argumentos inválidos ou vetor vazio
    }

    Book key ;
    strcpy(key.isbn, isbn);

    Book *key_ptr = &key;
    Book **found = bsearch(&key_ptr, vec->refs, vec->size, sizeof(Book *), compare_isbn);
    if (found == NULL) {
        return NULL;
    }
    return *found;
}

void vecRefFree( VecBookRef *vec, int freeBooks){
    int i = 0;
    if(freeBooks){
        while(i < vec->size){
            bookFree(vec->refs[i]);
            i++;
        }
        free(vec->refs);
    }
    free(vec);
}
