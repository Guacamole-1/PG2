// Bruno Soares 51832 
// Duarte Santos 51764
// Pedro Alves 51451

#include "prog2.h"
#include "prog1.h"
#include "../SE1/prog24.h"
#include "../SE1/prog22.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vecs.c"


void help() { 
printf("Possiveis comandos:\n");
printf("l - Listar todos os livros por ordem alfabética dos títulos\n");
printf("a {nome}- Listar todos os livros que contêm o autor dado, e por ordem alfabética dos títulos\n");
printf("i {isbn}- Listar todos os livros que contêm o ISBN dado\n");
printf("h - Ajuda\n");
printf("q - Terminar\n");
}

int main(int argc, char* argv[]){
    char line[255];
    DynCollection *col = dynCollCreate();
    if (argc < 2){
        printf("Não há argumentos suficientes!\n");
        printf("%s {nome do ficheiro}\n",argv[0]);
        return 0;
    } else if (argc > 2){
        printf("Argumentos a mais!\n");
        printf("%s {nome do ficheiro}\n",argv[0]);
        return 0;
    } 
    dynCollFill(col,"../SE2/dados.csv");
    while (1)
    {   
        printf("$ ");
        fgets(line, 255, stdin);
        separatorUnify(line);
        if (strlen(line) == 0) continue; 
        char *cmd = strtok(line, " ");
        char *args = strtok(NULL, "\0");

        if (*cmd == 'l')
        {
            /*
            printf("Titulo;Editor;Editora;Autores\n");
            for (int i = 0; i < col.count; i++)
            {
                printf("%s;%s;%s;%s\n",col.books[i].title,col.books[i].publisher,col.books[i].isbn,col.books[i].authors);
            }
            */
        }
        else if (*cmd == 'i')
        {
            if (args != NULL)
            {
               find_books_isbn(&col,args);
            } else {
                printf("Falta o numero do ISBN para procurar! Usa h para ajuda\n");
            }
            
            
        }
        else if (*cmd == 'a')
        {
            if (args != NULL)
            {

            } else {
                printf("Falta o nome para procurar! Usa h para ajuda\n");
            }
            
        }
        else if (*cmd == 'h' )
        {
            help();
        }
        else if (*cmd == 'q' )
        {
            return 0;
        }
        
    }

    return 1;
}