#include <stdio.h>
#include <stdlib.h>
#include "vecs.h"
#include "../SE2/prog1.h"

DynCollection *dynCollCreate( void ){
    DynCollection *d = malloc(sizeof(DynCollection));
    d->titleVec = vecRefCreate();
    d->isbnVec = vecRefCreate();

return d;
}

int dynCollAddBook( const char *line, void *context ){

    Book *b = bookCreate(line);
    
    DynCollection *col = context;

    if(b == NULL){  
        return 0;
    }
    
    vecRefAdd(col->titleVec,b);
    

return 1;
}

void dynCollFill( DynCollection *coll, const char *filename ){
//ta me a dar erro quanto ao File pq o argumento é um pointer enquanto o
//argumento que passas para o processfile é o nome do file
    processFile(filename, dynCollAddBook, coll);  
    vecRefSortIsbn(coll->isbnVec);
    vecRefSortTitle(coll->titleVec);  

}

void dynCollFree( DynCollection *coll){

    vecRefFree(coll->isbnVec, 1);
    vecRefFree(coll->titleVec, 1);
    free(coll);

}