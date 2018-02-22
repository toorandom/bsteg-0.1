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
get_bmp_header (char *bmp_file, bmp_header * hdr)
{
  int fd;
  struct stat imginfo;
  void *ptr;
  if (stat (bmp_file, &imginfo) < 0)
    return ERRSTAT;
  if ((fd = open (bmp_file, O_RDONLY)) < 0)
    return ERROPEN;
  if((ptr = mmap (0, sizeof (struct bmp_header_t), PROT_READ, MAP_SHARED, fd,0)) == NULL)
    return ERRMMAP;
  if(close(fd) < 0)
    return ERRCLOSE;
  memcpy (hdr, ptr, sizeof (struct bmp_header_t));
  if(munmap (ptr, sizeof (struct bmp_header_t)) < 0)
	  return ERRMUNMAP;
  if(endian() != __LITTLEENDIAN__)
  {
	  fprintf(stderr,"Converting to little endian (header)\n");
  convert_little_endian(hdr);
  }
  return OK;
}
