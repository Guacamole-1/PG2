#include "prog2.h"
#include "prog1.h"
#include "../SE1/prog24.h"
#include <stdio.h>

int main(int argc, char* argv[]){
    char cmd;
    Collection col;
    processFile("dados.csv",collAddBook,&col);

    while (scanf("%s",&cmd))
    {
        if (cmd == 'l')
        {
            collSortTitle(&col);
            printf("Titulo;Editor;Editora;autores\n");
            for (int i = 0; i < col.count; i++)
            {
                printf("%s;%s;%s;%s\n",col.books[i].title,col.books[i].publisher,col.books[i].isbn,col.books[i].authors);
            }
        }
        else if (cmd == 'i')
        {
            collSortRefIsbn(&col);
            printf("Titulo;Editor;Editora;autores\n");
            for (int i = 0; i < col.count; i++)
            {
                //printf("%s;%s;%s;%s\n",col.refs[i]->isbn,col.refs[i]->publisher,col.refs[i]->isbn,col.refs[i]->authors);
            }
        }
        else if (cmd == 'q')
        {
            return 0;
        }
        
    }

    return 1;
}