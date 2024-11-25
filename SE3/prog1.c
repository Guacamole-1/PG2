#include "prog1.h"
#include <stdio.h>
int main(){
    char* str = "The C Programming Language;0131103628;9780131103627;Brian W. Kernighan, Dennis M. Ritchie;Prentice Hall;language, programming;272;1988-04-01;Paperback;67.00 USD";
    Book *b = bookCreate(str);
    printf("%s",b->isbn);
}