#ifndef SE2_PROG13_H
#define SE2_PROG13_H


int processFile( const char *filename, 
                 int (*action)( const char *line, void *context ), 
                 void *context );

int linePrintRaw( const char *line, void *context );

int lineFilterPrint( const char *line, void *context );
#endif 

