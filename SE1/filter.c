// Bruno Soares 51832 
// Duarte Santos 51764
// Pedro Alves 51451
#include "prog24.h"
#include <stdlib.h>
#include "prog22.h"
#include <stdio.h>
#define MAX_SIZE 255

int main(int argc, char* argv[]){
    FILE *file = fopen("teste.txt", "r");
    char line[MAX_SIZE];
    char *line_ptr, *rest;
    char full_line[MAX_SIZE];
    int index = 1;
    int line_num = 1;
    
    if (argc < 3){
        printf("Não há argumentos suficientes!\n");
        printf("Uso: %s {posição do campo} {str a ser comparada}\n",argv[0]);
        return -1;

    } else if (argc > 3){
        printf("Argumentos a mais!\n");
        printf("Uso: %s {posição do campo} {str a ser comparada}\n",argv[0]);
        return -1;
    }
    for (int i = 0; argv[1][i] ; i++) //ver se o primeiro campo é um numero
    {
        if (!isdigit(argv[1][i])){

        printf("não é possivel usar: %s\n",argv[1]);
        printf("Uso: %s {posição do campo} {str a ser comparada}\n",argv[0]);
        return -1;
        }
    }

    int pos = strtoul (argv[1], NULL, 0); // posição do campo que queremos
    separatorUnify(argv[2]); // formatar a string que queremos procurar
        
    while (fgets(line, sizeof(line), file) != NULL) {
        line_ptr = line;
        index = 1; // campo onde estamos
        strcpy(full_line,line);
        do{
                rest = splitField( line_ptr );
                separatorUnify(line_ptr);
                if(strcmp_ic(argv[2],line_ptr) == 0 && index == pos){ //se encontrámos o string no campo certo
                    printf("(linha %d):\n",line_num);
                    printf("%s\n",full_line);}
                index++;
            }while((line_ptr = rest) != NULL);
        line_num++;
    }
}

