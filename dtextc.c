
#include "dtextc_data.h"
#include "stdio_shim.h"

#include "funcs.h"
#include "vars.h"

struct file
{
  const unsigned char* origPtr;
  unsigned char* currPtr;
  const unsigned int len;
};


const unsigned int dtextc_len = 133008;

FILE dtextc_file = 
{
  dtextc,
  dtextc,
  sizeof(dtextc)
};

// void* const fauxBOF = (void*)fauxFilePtr;
// unsigned char* const fauxEOF = fauxFilePtr + dtextc_len;

//FILE is now a ptr to array, so trap and increment, checking for EOF 

int getc(FILE* f)
{
  if (f->currPtr >= f->origPtr + f->len)
    return EOF;

  const int ret = *(f->currPtr);
  f->currPtr++;
  return ret;
}

const char* const dtext_filename = "dtextc.dat";

FILE* fopen(char* filename, char* mode)
{

  return &dtextc_file;
  // const char* _fn = filename;
  // const char* _cmp = dtext_filename;

  // FILE* ret = NULL;

  // logical match = 1;

  // while (*_fn != 0 && *_cmp != 0)
  // { 
  //   //cmpr filename to static fname, if differ then 0
  //   if ((_cmp++ != _fn++))
  //     match = 0;
  // }

  // if (match)
  // {
  //   ret = &dtextc_file;
  // }


  // return ret;
}

long int ftell (FILE* stream)
{
  if (stream)
  {
    return stream->currPtr - stream->origPtr;
  }
  else return EOF;

}

int fseek ( FILE * stream, long int offset, int origin )
{
  switch (origin)
  {
    case SEEK_CUR:
      stream->currPtr += offset;
      break;
    case SEEK_SET:
      stream->currPtr = stream->origPtr + offset;
      break;
    case SEEK_END:
      stream->currPtr = stream->origPtr + stream->len + offset;
      break;
  
    default:
      return EOF;
      break;
  }

  //currPtr coherent
  if (stream->currPtr < stream->origPtr + stream->len)
    return 0;

  return EOF;

}

