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
#ifndef _BSWAP_H_
#define _BSWAP_H_
#include <stdint.h>
#define bswap16(x) (((x) & 0x00ff) << 8 | ((x) & 0xff00) >> 8)
#define bswap32(x) \
      ((((x) & 0xff000000) >> 24) | (((x) & 0x00ff0000) >>  8) | \
            (((x) & 0x0000ff00) <<  8) | (((x) & 0x000000ff) << 24))
inline static uint64_t
bswap64 (uint64_t x)
{
  union
  {
    uint64_t ll;
    uint32_t l[2];
  } w, r;
  w.ll = x;
  r.l[0] = bswap32 (w.l[1]);
  r.l[1] = bswap32 (w.l[0]);
  return r.ll;
}
#endif
