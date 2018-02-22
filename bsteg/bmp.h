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
#ifndef _BMP_H_
#define _BMP_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
typedef struct bmp_header_t
{
  unsigned char sig1;		/* 0x42 */
  unsigned char sig2;		/* 0x4d */
  unsigned int size;		/* size of bmp file in bytes */
  /* Using a unsigned int (we are going to use this space) 
  unsigned short reserved1;	
  unsigned short reserved2;	
  */
  unsigned int reserved;	/* reserved space */
  unsigned int offset;		/* start of image in bytes */
  unsigned int bmpinfo;		/* must be 40 */
  unsigned int pixwidth;	/* image width in pixels */
  unsigned int pixheight;	/* image height in pixels */
  unsigned short planes;	/* must be 1 */
  unsigned short pixbits;	/* pixel size in bits must be 1,4,8 or 24 */
  unsigned int comp;		/* 0=none , 1=RLE-8 , 2=RLE-4 */
  unsigned int imgsize;		/* size in bytes with padding */
  unsigned int hrp;		/* horizontal resolution in pixels per meter (shit) */
  unsigned int vrp;		/* vertical resolution in pixels per meter (shit) */
  unsigned int numcolors;	/* number of colors in image or zero */
  unsigned int imp_colors;	/* number of important colors, or zero */
}__attribute__((__packed__)) bmp_header;
typedef struct bsteg_info_t {
unsigned int size;
unsigned int algorithm;
} bsteg_info;
typedef struct BMP_t {
	unsigned char b;
	unsigned char g;
	unsigned char r;
}__attribute__((__packed__)) BMP;
int
endian ();
void info_bmp(bmp_header hdr) ;
int
get_bmp_header (char *, bmp_header *);
BMP *
map_bmp (char *);
int unmap_bmp(void);
int convert_little_endian(bmp_header *);
void
get_file (char *, char *);
int
write_header (char *, bsteg_info);
void
insert_file (char *, char *);
#define OK 0
#define ERRSTAT -1
#define ERROPEN -2
#define ERRCLOSE -3
#define ERRMMAP -4
#define ERRMUNMAP -5
#define NULLPOINTER -1
#define __BIGENDIAN__ 0x10
#define __LITTLEENDIAN__ 0x01
#define __UNKENDIAN__ 0x11
#endif
