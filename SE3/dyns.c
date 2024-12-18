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
    processFile(filename, dynCollAddBook, coll);  
    vecRefSortIsbn(coll->isbnVec);
    vecRefSortTitle(coll->titleVec);  
}

void dynCollFree( DynCollection *coll){

    vecRefFree(coll->isbnVec, 1);
    vecRefFree(coll->titleVec, 1);
    free(coll);

}