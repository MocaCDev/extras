#include <stdio.h>
#include <stdlib.h>

#define BUFFER(byte,against) ( ((byte && against ) == 1) ? 0 : 1)
#define BUFFER_NEXT(curr_byte) ( curr_byte + 1 )
#define BUFFER_BY_SIZE(curr_byte, size, against) (( curr_byte * size && against == 1) ? 0 : 1)
#define BUFFER_SIZE(curr_byte, by) ( ( curr_byte + 1 ) * ( by - 1 ))

int __indication_start(void const * const buffer_indication)
{
  if(BUFFER(buffer_indication,buffer_indication)==0) return 0;
  return 1;
}
int __buffer_output(void const * const _buffer)
{
  if(__indication_start(_buffer)==0)
  {
    return (int)BUFFER_SIZE((int)_buffer,1); // next value
  }
  return (int)BUFFER_SIZE((int)_buffer, BUFFER_SIZE((int)_buffer,1)); // next value after the next ascii value..
}

int __buffer_write(void const * const _buffer)
{
  while(__indication_start(_buffer)==0)
  {
    if(__indication_start((char*)BUFFER_NEXT(_buffer))==0)
      return (int)_buffer;
    if(BUFFER_BY_SIZE((int)_buffer,2,(int)_buffer)==0)
      return (int)BUFFER_NEXT((int)_buffer);
    if(BUFFER_BY_SIZE((int)_buffer,2,(int)_buffer)==1)
      return (int)BUFFER_NEXT(BUFFER_SIZE((int)_buffer-1,2));
    return __buffer_output((char*)_buffer); // next buffer value
  }
  return -1;
}

int main(void) {
  
  // 0xa should be \n!
  if(__indication_start((char*)0xa) == 0)
  {
    if(__buffer_write((char*)0xa) != -1)
    {
      int output = __buffer_write((char*)0xa);
      output -= __buffer_output((char*)0xa); // making sure the buffered value is as expected!
      printf("%c",output); // boom!
    }
  }

  return 0;
}
