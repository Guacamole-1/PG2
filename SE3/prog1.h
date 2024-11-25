#ifndef SE3_PROG2_H
#define SE3_PROG2_H
//#include "../SE2/prog2.h"
#define MAX_ISBN 15

typedef struct {  // Descritor dos dados de um livro 
 char *title;  //  string alojada dinamicamente 
 char isbn[MAX_ISBN]; // string com dimensão fixa 
 char *authors;   //  string alojada dinamicamente 
 char *publisher; //  string alojada dinamicamente 
} Book; 
 
typedef struct{  // Descritor de um vetor 
 Book **refs; //  array alojado dinamicamente 
 int size;   //  quantidade de elementos preenchidos 
 int space;  //  quantidade de elementos alojados 
} VecBookRef; 
 
typedef struct{  // Descritor de um vetor 
 VecBookRef *titleVec; //  vetor a ordenar por título 
 VecBookRef *isbnVec;  //  vetor a ordenar por isbn 
} DynCollection; 

Book *bookCreate( const char *line ); 

void bookFree( Book *b );

int fillBookData( Book *b, const char *line );

#endif