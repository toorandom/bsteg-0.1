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
#include "bmp.h"
int
endian ()
{
  char *x = "A";
  short *y = (short *) x;
  if(y[0] == 0x4100)
    return __BIGENDIAN__;
  else
    return __LITTLEENDIAN__;
  return __UNKENDIAN__;
}
