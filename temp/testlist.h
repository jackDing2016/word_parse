#include <stdbool.h>

extern struct arraylist *createarraylist();
extern void addelement( struct arraylist *arraylist, char *value);
extern int getsize( struct arraylist *arraylist );
extern void iteratearraylist( struct arraylist *arraylist );
extern bool iscontainelement( struct arraylist *al, char *val );
extern char *getelement( struct arraylist *al, int index ); 

