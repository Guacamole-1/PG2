// Bruno Soares 51832 
// Duarte Santos 51764
// Pedro Alves 51451

#include <stdio.h>
#include <string.h>
#include "../SE1/prog22.h"
#include "../SE1/prog24.h"
#include "prog1.h"
#define MAX_LINE_SIZE 440

int processFile( const char *filename, 
                 int (*action)( const char *line, void *context ), 
                 void *context ){


    FILE *file = fopen(filename, "r");
    if (!file) {
        return -1; // Erro ao abrir o ficheiro
    }
    char line[MAX_LINE_SIZE];
    int sum_context;
    while (fgets(line, sizeof(line), file) != NULL) {
        sum_context += action(line,context);
    }
                 
    fclose(file);
    return sum_context;
}

int linePrintRaw( const char *line, void *context ){
    printf("%s",line);
    return 1;
}

int lineFilterPrint( const char *line, void *context ){
    char line1[strlen(line)];
    strcpy(line1,line);
    splitField(line1);
    separatorUnify(line1);
    if (strcmp_ic(line1,context) == 0 )
    {
        printf("%s\n",line);
        return 1;
    }
    
    return 0;
}