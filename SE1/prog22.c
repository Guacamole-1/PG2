// Bruno Soares 51832 
// Duarte Santos 51764
// Pedro Alves 51451
#include "prog22.h"
#include <stdio.h>
#define MAX_SIZE 255
int main(){
    FILE *file = fopen("teste.txt", "r");
    char line[MAX_SIZE];
    char *line_ptr, *rest;
    while (fgets(line, sizeof(line), file) != NULL) {
        line_ptr = line;
        do{
                rest = splitField( line_ptr );
                separatorUnify(line_ptr);
                printf( "{%s}", line_ptr);
            }while((line_ptr = rest) != NULL); 
    }
} 