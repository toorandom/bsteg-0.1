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
#ifndef _XBITS_H_
#define _XBITS_H_
typedef struct xbyte_t {
	unsigned char bit[8];
}xbyte;
xbyte
break_byte (unsigned char);
unsigned char
modify_lsb (unsigned char, unsigned char);
unsigned char
get_lsb (unsigned char);
unsigned char
build_byte (xbyte);
#endif
