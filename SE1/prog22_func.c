// Bruno Soares 51832 
// Duarte Santos 51764
// Pedro Alves 51451
#include "prog22.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


char *splitField(char *str) {
     //se tiver tamanho 0 
    if (str == NULL || *str == '\0') { 
        return NULL; 
    }

    // Percorre a string até encontrar o separador ';' ou o terminador de string '\0'
    while (*str != ';' && *str != '\0') { 
        str++;  // Avança o ponteiro para o próximo caracter
    }
    
 
    if (*str == ';') {
        *str = '\0'; // Substitui o ';' pelo terminador de string para isolar o campo atual
        return str + 1; // Retorna o ponteiro para o próximo caracter após o ';'

    } else {
        return NULL; 
    }
}

void arrayshift( char str[], int i){//move todos os conteudos do array a partir da posição i para a esquerda
    for(int j = i; str[j] != '\0'; j++){
        str[j] = str[j+1];
    }    
}

void separatorUnify(char str[]){

    if( strlen(str) != 0){//verifica se o array é um array vazio
        for(int i = 0; str[i] != '\0'; i++){
            if((i == 0 || str[i+1] == '\0') && isspace(str[i])){//se houver espaços no inicio ou no fim do string são removidos por aqui
                arrayshift(str, i);//função auxiliar para mover os conteudos do array para a posição anterior
                i--;//ao decrementar o i consegue se verificar o que esta contido na mesma posição do array após a função arrayshift
            }
            if(isspace(str[i])){
                str[i] = ' ';//troca as tabulações e os paragrafos por espaços
                if(isspace(str[i+1])){//se houver dois espaços seguidos aplica a função arrayshift ao string
                    arrayshift(str, i);
                    i--;   
                }           
            }
        }
    }
}

