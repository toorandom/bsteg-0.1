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
int
write_header (char *imgpath, bsteg_info nfo)
{
  bmp_header *handler;
  int fd;
  struct stat imgnfo;
  if (stat (imgpath, &imgnfo) < 0)
    return ERRSTAT;

  if ((fd = open (imgpath, O_RDWR)) < 0)
    return ERROPEN;
  if ((handler =
       mmap (NULL, sizeof (struct bmp_header_t), PROT_WRITE | PROT_READ,
	     MAP_SHARED, fd, 0)) == NULL)
    {
      close (fd);
      return ERRMMAP;
    }
  close (fd);
  if(endian() == __BIGENDIAN__)
  {
	  fprintf(stderr,"Swapping size\n");
	  nfo.size = bswap32(nfo.size);
  }

  handler->imp_colors= nfo.size;
  if (munmap (handler, sizeof (struct bmp_header_t)) < 0)
    return ERRMUNMAP;
  return OK;
}
