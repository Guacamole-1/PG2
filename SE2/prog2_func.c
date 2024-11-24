// Bruno Soares 51832 
// Duarte Santos 51764
// Pedro Alves 51451

#include "../SE1/prog22.h"
#include "../SE1/prog24.h"
#include "prog2.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



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
    return strcmp_ic((*(BookData **)str1)->isbn, (*(BookData **)str2)->isbn);
}

void collSortTitle( Collection *col ){
    qsort(col->books,col->count,sizeof *col->books,compare_title);
}
void collSortRefIsbn( Collection *col ){

    for (int i = 0; i < col->count; i++)
    {
        col->refs[i] = &col->books[i];
    }
    qsort(col->refs,col->count,sizeof *col->refs,compare_isbn);
}

int bookContainsAuthor( BookData *b, const char *word ){

    const char *sepAuth = ",";
    char *rest;
    char temp[MAX_AUTHORS];
    char temp2[MAX_AUTHORS];
    strcpy(temp,b->authors);
    strcpy(temp2, word);

    rest = strtok(temp,sepAuth);

    while(rest != NULL){

        separatorUnify(rest);
        separatorUnify(temp2);

        if(strcmp_ic(temp2,rest) == 0){
            return 1;
        }
        rest = strtok(NULL, sepAuth);
    }

    const char *sep = " ";
    strcpy(temp,b->authors);
    rest = strtok(temp,sep);
    separatorUnify(temp2);
    while(rest != NULL){

        if(strcmp_ic(temp2,rest) == 0){
            return 1;
        }
        rest = strtok(NULL, sep);
    }

return 0;
}
void find_books_isbn(Collection *col, const char *target_isbn) {

    collSortRefIsbn(col);

    BookData key;
    strcpy(key.isbn, target_isbn);

    BookData *key_ptr = &key;
    BookData **found = (BookData **)bsearch(&key_ptr, col->refs, col->count, sizeof(BookData *), compare_isbn);

    if (found == NULL) {
        printf("Nenhum livro encontrado com o ISBN: %s\n", target_isbn);
        return;
    }

    printf("Livros encontrados com o ISBN %s:\n", target_isbn);
    // Verificar livros anteriores com o mesmo ISBN
    while (strcmp((*(found - 1))->isbn, target_isbn) == 0) {
        found--;
    }
    // Iterar para frente e listar todos os livros com o mesmo ISBN
    while (strcmp_ic((*found)->isbn, target_isbn) == 0) {
        printf("- Título: %s\n", (*found)->title);
        printf("  Autor(es): %s\n", (*found)->authors);
        printf("  Editora: %s\n\n", (*found)->publisher);
        
        found++;
    }
}