

#define EOF (-1)
#define NULL (0x0)

#define SEEK_CUR    1
#define SEEK_END    2
#define SEEK_SET    0

typedef struct file FILE;


#ifdef unix
/* Write formatted output to stdout.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int printf (const char *__restrict __format, ...);

#else
//TODO need to define printf in terms of getchar()
//Functionality required:
//  * %s
//  * %d
//  * %.6s
//  * %1d
//  * %c
//  * case with debug breakpoint set to catch un-expected escape

#endif
/* Write formatted output to STREAM.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
#define fprintf(f,s, ...) printf( s, __VA_ARGS__)

int getc(FILE* f);
FILE* fopen(char* filename, char* mode);

int fseek ( FILE * stream, long int offset, int origin );

long int ftell (FILE* stream);