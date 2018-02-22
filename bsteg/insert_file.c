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
void
insert_file (char *imgpath, char *filepath)
{
  bmp_header hdr;
  BMP *img;
  int fd, i, k = 0;
  unsigned char byte, *imghandler;
  struct stat imgnfo, filenfo;
  bsteg_info nfo;
  xbyte nbyte;
  if (stat (imgpath, &imgnfo) < 0)
    {
      perror ("insert_file stat()");
      exit (EXIT_FAILURE);
    }
  if (stat (filepath, &filenfo) < 0)
    {
      perror ("insert_file stat()");
      exit (EXIT_FAILURE);
    }
  if (get_bmp_header (imgpath, &hdr) < 0)
    {
      perror ("insert_file get_bmp_header()");
      exit (EXIT_FAILURE);
    }
  info_bmp(hdr);
  if ((fd = open (filepath, O_RDONLY)) < 0)
    {
      perror ("insert_file open()");
      exit (EXIT_FAILURE);
    }
  if ((img = map_bmp (imgpath)) == NULL)
    {
      close (fd);
      perror ("insert_file map_bmp()");
      exit (EXIT_FAILURE);
    }
  imghandler = (unsigned char *) img;
	nfo.size = filenfo.st_size;
	
  if ((filenfo.st_size*8) > (hdr.pixwidth * hdr.pixheight * 3))
    {
      fprintf (stderr, "File to insert too large for the BMP\n");
      close (fd);
      unmap_bmp ();
      exit(EXIT_FAILURE);
    }
  fprintf(stderr,"Inserting file..\n");
  while (read (fd, &byte, sizeof (byte)) > 0)
    {
      nbyte = break_byte (byte);
      for (i = 0; i < 8; i++) {
	imghandler[k] = (unsigned char)modify_lsb (imghandler[k], nbyte.bit[i]);
	k+=((imgnfo.st_size)/(filenfo.st_size*8));
      }
    }


  fprintf(stderr,"Done!\n");
  if (close (fd) < 0)
    {
      perror ("insert_file close()");
      exit (EXIT_FAILURE);
    }
  if (unmap_bmp () < 0)
    {
      perror ("insert_file unmap_bmp()");
      exit (EXIT_FAILURE);
    }
  if(write_header(imgpath,nfo) < 0) {
	  perror("insert_file write_header()");
	  exit(EXIT_FAILURE);
  }
  return;
}
