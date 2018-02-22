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
#include "bswap.h"

int convert_little_endian(bmp_header *h) {
	if(h == NULL) 
		return NULLPOINTER;
	h->size =  bswap32(h->size);
	h->reserved = bswap32(h->reserved);
	h->offset = bswap32(h->offset);
	h->bmpinfo = bswap32(h->bmpinfo);
	h->pixwidth = bswap32(h->pixwidth);
	h->pixheight = bswap32(h->pixheight);
	h->planes = bswap16(h->planes);
	h->pixbits = bswap16(h->pixbits);
	h->comp = bswap32(h->comp);
	h->imgsize = bswap32(h->imgsize);
	h->hrp = bswap32(h->hrp);
	h->vrp = bswap32(h->vrp);
	h->numcolors = bswap32(h->numcolors);
	h->imp_colors = bswap32(h->imp_colors);
	return OK;
}
