#ifndef VECS_H
#define VECS_H
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


void bookFree( Book *b );

Book *bookCreate( const char *line ); 

VecBookRef *vecRefCreate ( void );

void vecRefAdd( VecBookRef *vec, Book *ref ); 

int vecRefSize( VecBookRef *vec );

Book *vecRefGet( VecBookRef *vec, int index);

int compare_title(const void *str1, const void *str2);

int compare_isbn(const void *str1, const void *str2);

void vecRefSortTitle( VecBookRef *vec );

void vecRefSortIsbn( VecBookRef *vec ); 

Book *vecRefSearchIsbn( VecBookRef *vec, char *isbn );

void vecRefFree( VecBookRef *vec, int freeBooks );

DynCollection *dynCollCreate( void );

int dynCollAddBook( const char *line, void *context );

void dynCollFill( DynCollection *coll, const char *filename );

void dynCollFree( DynCollection *coll);
#endif