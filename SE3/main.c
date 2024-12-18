// Bruno Soares 51832 
// Duarte Santos 51764
// Pedro Alves 51451

#include "../SE2/prog2.h"
#include "../SE2/prog1.h"
#include "../SE1/prog24.h"
#include "../SE1/prog22.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vecs.h"

void printBook(Book* book){
    printf("%s; %s; %s; %s\n",book->title,book->publisher,book->isbn,book->authors);
}

void help() { 
printf("Possiveis comandos:\n");
printf("l - Listar todos os livros por ordem alfabética dos títulos\n");
printf("a {nome}- Listar todos os livros que contêm o autor dado, e por ordem alfabética dos títulos\n");
printf("i {isbn}- Procurar o livro que contém o ISBN dado\n");
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
    separatorUnify(argv[1]);
    dynCollFill(col,argv[1]);
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
            printf("Titulo;Editor;Editora;Autores\n");
            for (int i = 0; i < vecRefSize(col->titleVec); i++)
            {
                Book* book = vecRefGet(col->titleVec,i);
                printBook(book);
            }
        }
        else if (*cmd == 'i')
        {
            if (args != NULL)
            {
               Book* found = vecRefSearchIsbn(col->isbnVec,args);
               if (found != NULL)
               {
                printf("Livros encontrados com o ISBN %s:\n", args);
                printBook(found);
               } else {
                printf("Não foi encontrado nenhum livro com o ISBN %s:\n", args);
               }
               
            } else {
                printf("Falta o numero do ISBN para procurar! Usa h para ajuda\n");
            }
            
            
        }
        // else if (*cmd == 'a')
        // {
        //     if (args != NULL)
        //     {
        //        for(int i = 0; i < MAX_BOOKS; i++){
        //         if(bookContainsAuthor(&col.books[i],args)){
        //             printf("%s, %s, %s, %s\n", col.books[i].title, col.books[i].isbn, col.books[i].authors, col.books[i].publisher);
        //         }
        //     }
        //     } else {
        //         printf("Falta o nome para procurar! Usa h para ajuda\n");
        //     }
            
        // }
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