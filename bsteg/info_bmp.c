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
void info_bmp(bmp_header hdr) {
	fprintf(stdout,"Signature: %x%x\n",hdr.sig1,hdr.sig2);
	fprintf(stdout,"Size of bmp: %x\n",hdr.size);
	fprintf(stdout,"Reserved : %d\n",hdr.reserved);
	fprintf(stdout,"Offset: %d\n",hdr.offset);
	fprintf(stdout,"BMP Info: %d\n",hdr.bmpinfo);
	fprintf(stdout,"Pix width in pixels: 0x%x\n",hdr.pixwidth);
	fprintf(stdout,"Pix height in pixels: 0x%x\n",hdr.pixheight);
	fprintf(stdout,"Planes: %d\n",hdr.planes);
	fprintf(stdout,"Pixel size in bits: %d\n",hdr.pixbits);
	fprintf(stdout,"Compression: %d\n",hdr.comp);
	fprintf(stdout,"Size of images with padding: %d\n",hdr.imgsize);
	fprintf(stdout,"Horizontal resolution in pixels per meter: %d\n",hdr.hrp);
	fprintf(stdout,"Vertical resolution in pixels per meter: %d\n",hdr.vrp);
	fprintf(stdout,"Number of colors in image (zero max) : %d\n",hdr.numcolors);
	fprintf(stdout,"Number of important colors in image (zero max): %d\n",hdr.imp_colors);
	fprintf(stdout,"sizeof header %d\n",(int)sizeof(hdr));
	return;
}
