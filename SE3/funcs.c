#include "prog1.h"
#include "../SE1/prog22.h"
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
                return 0;
            }
            
            switch (pos)
            {
            case TITULO:
                b->title = malloc(strlen(line1) + 1);
                b->title = line1;
                break;
            case ISBN:
                strcpy(b->isbn, line1);
                break;
            case AUTOR:
                b->authors = malloc(strlen(line1) + 1);
                b->authors = line1;
                break;
            case EDITOR:
                b->publisher = malloc(strlen(line1) + 1);
                b->publisher = line1;
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