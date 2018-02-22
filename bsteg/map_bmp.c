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
static void *Image_bak;
static int image;
struct stat imginfo;

int
unmap_bmp (void)
{
  if ((munmap (Image_bak, imginfo.st_size)) < 0)
    return ERRMUNMAP;
  return OK;
}

BMP *
map_bmp (char *bmp_file)
{
  int r;
  BMP *Img;
  unsigned char *handler;
  bmp_header hdr;
  if ((r = get_bmp_header (bmp_file, &hdr)) < 0)
        return NULL;
  if (stat (bmp_file, &imginfo) < 0)
    return NULL;
  if ((image = open (bmp_file, O_RDWR)) < 0)
    return NULL;
  if ((Img =
       mmap (NULL, imginfo.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, image, 0)) == NULL)
    return NULL;
  
  if (close (image) < 0)
    return NULL;
    
  Image_bak = Img;
  printf("map_bmp: %c%c\n",Img->r,Img->g);
  handler = (unsigned char *)Img;
  handler = handler + hdr.offset;
  Img = (BMP *)handler;
  return Img;
}
