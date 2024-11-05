// Bruno Soares 51832 
// Duarte Santos 51764
// Pedro Alves 51451
#include "prog24.h"
#include <stdio.h>


int main(int argc, char* argv[]){
    if (argc<3){
        printf("Não há argumentos suficientes!\n");
        printf("./prog24.c {str a comparar} {str || ...}");
    }
    for (int i = 2; i < argc; i++) {
        printf("%s é alfabeticamente %s a %s\n",argv[1],check_result(strcmp_ic(argv[1],argv[i])),argv[i]);
    }
    
}   