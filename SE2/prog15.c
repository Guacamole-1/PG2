#include <stdio.h>
#include "../SE1/prog22.h"
#include "../SE1/prog24.h"
#include "prog1.h"

int main(int argc, char* argv[]){
    if (argc < 3){
        printf("Não há argumentos suficientes!\n");
        printf("./prog15.c {nome do ficheiro} {string a procurar}\n");

    }else if(argc > 3) {
        printf("Argumentos a mais!\n");
        printf("./prog15.c {nome do ficheiro} {string a procurar}\n");
    }
     else {
        separatorUnify(argv[2]); // temos de meter o separatorunify no print???
        printf("nº de linhas: %d\n",processFile(argv[1],lineFilterPrint,argv[2]));
    }

    return 0;
}