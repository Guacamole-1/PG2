#include <stdio.h>
#include <stdlib.h>
#include "vecs.h"
#include "bin_tree.h"
int main(){
    DynCollection *col = dynCollCreate();
    TNode *root = malloc(sizeof(TNode));
    LNode *head = malloc(sizeof(LNode));
    Book *book = malloc(sizeof(Book));
    Book *book2 = malloc(sizeof(Book));
    // const char *line = "The C Programming Language;0131103628;9780131103627;Brian W. Kernighan, Dennis M. Ritchie;Prentice Hall;language, programming;272;1988-04-01;Paperback;67.00 USD";
    // const char *line2 = " C Programming Absolute Beginner's Guide (3rd Edition);0789751984;9780789751980;Greg Perry, Dean Miller;Que Publishing;guide, beginner, absolute, programming;352;2013-08-17;Paperback;29.99 USD" ;
    // dynCollAddBook(line,col);
    // dynCollAddBook(line2,col);
    //book = bookCreate(line);
    //book2 = bookCreate(line2);
    //puts("p");
    //printf("%s",col->titleVec->refs[0]->title);
    dynCollFill(col,"../SE2/dados.csv");
    binTreeStart(root,col->titleVec);
    //lRefAdd(&head,book);
    //lRefAdd(&head,book2);


    printf("x");

    //head = bstSearch(root, "Brian");
    //printf("%s",col->titleVec->refs[0]->title);
    //puts(col->isbnVec->refs[0]->title);
    //dynCollFree(col);

    lRefFree(head);
    bookFree(book);
}