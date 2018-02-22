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
#include "xbits.h"
#include "bswap.h"
void
get_file (char *imgpath, char *outpath)
{
  struct stat imgnfo;
  int fd, i,p=0,delta,cbytes=0;
  BMP *img;
  bmp_header hdr;
  unsigned char *imghandler, byte;
  xbyte xb;
  if (stat (imgpath, &imgnfo) < 0)
    {
      perror ("get_file stat()");
      exit (EXIT_FAILURE);
    }
  if ((fd = open (outpath, O_WRONLY | O_CREAT, S_IRWXU)) < 0)
    {
      perror ("get_file stat()");
      exit (EXIT_FAILURE);
    }
  if ((img = map_bmp (imgpath)) == NULL)
    {
      perror ("get_file map_bmp()");
      close (fd);
      exit (EXIT_FAILURE);
    }
  if ((get_bmp_header (imgpath, &hdr)) < 0)
    {
      perror ("get_file get_bmp_header()");
      close (fd);
      unmap_bmp ();
      exit (EXIT_FAILURE);
    }
  imghandler = (unsigned char *) img;
  printf("Getting %d bytes\n",hdr.imp_colors);
  memset(&xb,0,sizeof(struct xbyte_t));
  delta = ((imgnfo.st_size)/(hdr.imp_colors*8));
  for (i=0;i<imgnfo.st_size; i+=delta)
    {
      if ( ((p > 0) && (p % 8)) == 0)
	{
	  byte = build_byte (xb);
	  if(p > 7)
	  write (fd, &byte, sizeof (unsigned char));
	  if(cbytes == hdr.imp_colors)
	  {
	  printf("Got all bytes (%d)!\n",cbytes);
	  break;
	  }
	  cbytes++;
	}
      xb.bit[p % 8] = get_lsb (imghandler[i]);
	p++;

    }
  close (fd);
  unmap_bmp ();
  return;
}
