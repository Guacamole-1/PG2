// Bruno Soares 51832 
// Duarte Santos 51764
// Pedro Alves 51451

#include "prog2.h"
#include "prog1.h"
#include <stdio.h>

int main(int argc, char* argv[]){
    
    if (argc < 2){
        printf("Não há argumentos suficientes!\n");
        printf("Uso: %s {ficheiro}\n",argv[0]);
        return -1;

    } else if (argc > 2){
        printf("Argumentos a mais!\n");
        printf("Uso: %s {ficheiro}\n",argv[0]);
        return -1;
    }
    Collection col;
    printf("!%d!",processFile(argv[1],collAddBook,&col));
    for (int i = 0; i < col.count; i++)
    {
        printf("%s;%s;%s;%s\n",col.books[i].title,col.books[i].publisher,col.books[i].isbn,col.books[i].authors);
    }
    
    

    return 0;
}