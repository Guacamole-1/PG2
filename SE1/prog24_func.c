// Bruno Soares 51832 
// Duarte Santos 51764
// Pedro Alves 51451
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "prog24.h"

int strcmp_ic(const char *str1, const char *str2){
    int a = strlen(str1)-strlen(str2);
    
    do{
        if(tolower(*str1)-tolower(*str2) > 0){
            return 1;
        }    
        if(tolower(*str1)-tolower(*str2) < 0){
            return -1;
        }
    }while(*str1++ != '\0' && *str2++ != '\0'); // ver se as letras são alf. superiores ou inferiores

    if (a > 0)  //ver o tamanho das letras para decidir a posição alfabetica
        return 1;
    else if (a == 0)
        return 0;
    else if (a < 0)
        return -1;
}
char* check_result(int result){
    if (result == 2)
        return "inválido";
    if (result == 0)
        return "igual";
    if (result == -1)
        return "inferior";
    if (result == 1)
        return "superior";

    return NULL;

}