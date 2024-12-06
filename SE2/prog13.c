// Bruno Soares 51832 
// Duarte Santos 51764
// Pedro Alves 51451

#include <stdio.h>
#include "../SE1/prog22.h"
#include "../SE1/prog24.h"
#include "prog1.h"

int main(int argc, char* argv[]){
    if (argc < 2){
        printf("Não há argumentos suficientes!\n");
        printf("./prog13.c {nome do ficheiro}\n");
    } else {
    printf("\n%d\n",processFile(argv[1],linePrintRaw,NULL));
    }
    return 0;
}