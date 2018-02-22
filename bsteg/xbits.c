/*
 * bsteg 0.1
 * This computer program can be copied without the permission of the creator
 * if you include this copyright notice in all the source files
 *
 * Created by
 *
 * Eduardo Ruiz Duarte
 *
 * toorandom@gmail.com
 */
#include "xbits.h"

xbyte
break_byte (unsigned char byte)
{
  int i;
  xbyte r;
  for (i = 0; i < 8; i++)
    r.bit[7 - i] = ((byte >> i) & 1);
  return r;

}
unsigned char
build_byte (xbyte byte)
{
  int i;
  unsigned char r = 0;
  for (i = 0; i < 8; i++)
    r |= ((byte.bit[i] & 1) << (7 - i));
  return r;

}
unsigned char
modify_lsb (unsigned char byte, unsigned char x)
{
  return (unsigned char)((byte & 0xfe) | (x & 0x01));
}
/* mas significativo
unsigned char
modify_lsb (char byte, unsigned char x)
{
  return (unsigned char)((byte & 0xef) | (x<<7));
}
*/
unsigned char
get_lsb (unsigned char byte)
{
  return (unsigned char)(byte & 0x01);
}
/*
int main(int argc , char **argv) {
printf("%d\n",get_lsb(0x59));
}*/
