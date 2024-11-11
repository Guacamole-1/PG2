#include "../SE1/prog22.h"
#include "../SE1/prog24.h"
#include "prog2.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#define TITULO 0
#define ISBN 1
#define AUTOR 3
#define EDITOR 4



int fillBookData( BookData *b, const char *line ){
    int pos = 0;
    char line1[strlen(line)];
    char rest[strlen(line)];
    strcpy(line1,line);
    char* rest_ptr;
    char* line1_ptr = line1;
    do{
            rest_ptr = splitField( line1_ptr );
            separatorUnify(line1_ptr);
            if (line1_ptr == NULL && (pos == TITULO || pos == ISBN || pos == AUTOR || pos == EDITOR))
            {
                return 0;
            }
            
            switch (pos)
            {
            case TITULO:
                strcpy(b->title, line1_ptr);
                break;
            case ISBN:
                strcpy(b->isbn, line1_ptr);
                break;
            case AUTOR:
                strcpy(b->authors, line1_ptr);
                break;
            case EDITOR:
                strcpy(b->publisher, line1_ptr);
                break;
            default:
                break;
            }
            pos++;
        }while((line1_ptr = rest_ptr) != NULL);
    return 1; 
}

int collAddBook( const char *line, void *context ){

    BookData book_;
    Collection *coll = (Collection *)context;
    if (coll->count >= MAX_BOOKS || !fillBookData(&book_,line))
    {
        return 0;
    }
    coll->books[coll->count] = book_;
    coll->count++;

return 1;
}

int compare_title(const void *str1, const void *str2){
    return strcmp_ic(((BookData *)str1)->title, ((BookData *)str2)->title);
}
int compare_isbn(const void *str1, const void *str2){
    BookData  str11 = *(BookData *)str1;
    BookData  str22 = *(BookData *)str2;
    printf("%s\n",str11.isbn);
    return strcmp_ic(str11.isbn, str22.isbn);
}

void collSortTitle( Collection *col ){
    qsort(col->books,col->count,sizeof *col->books,compare_title);
}
void collSortRefIsbn( Collection *col ){

    for (int i = 0; i < col->count; i++)
    {
        col->refs[i] = &col->books[i];
    }
    printf("!%d!",strcmp_ic(col->books[1].isbn,col->books[0].isbn));
    printf("!%d!",strcmp_ic(col->books[1].isbn,col->books[0].isbn));
    qsort(col->refs,col->count,sizeof *col->refs,compare_isbn);
}
// *col->refs[0] = &Bookdata