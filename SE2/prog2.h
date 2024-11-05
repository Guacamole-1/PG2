#ifndef SE2_PROG2_H
#define SE2_PROG2_H
#define MAX_LINE_SIZE 440
#define MAX_TITLE 210
#define SIZE_ISBN 15
#define MAX_AUTHORS 95
#define MAX_PUB_NAME 55
#define MAX_BOOKS 300

typedef struct book { 
 char title[MAX_TITLE]; 
 char isbn[SIZE_ISBN]; 
 char authors[MAX_AUTHORS]; 
 char publisher[MAX_PUB_NAME]; 
} BookData; 
 
typedef struct{ 
 BookData books[MAX_BOOKS]; 
 BookData *refs[MAX_BOOKS]; 
 int count; // quantidade de elementos preenchidos em books 
} Collection; 


int fillBookData( BookData *b, const char *line ); 

int collAddBook( const char *line, void *context );

#endif 
