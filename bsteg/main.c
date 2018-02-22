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
void
help (char *prog)
{
  fprintf (stderr,
	   "-g -> Get file from a BMP\n-i ->Insert a file into a bmp\n");
  fprintf (stderr, "Example:\n$ %s -i file.bmp file.ext\n", prog);
  fprintf (stderr, "$ %s -g file.bmp output.ext\ntoorandom@gmail.com\n",
	   prog);
  exit (EXIT_FAILURE);
}

int
main (int argc, char **argv)
{
  if (argc < 4)
    help (argv[0]);
  if ((strcmp (argv[1], "-g") == 0))
    {
      printf ("Output to %s\n", argv[3]);
      get_file (argv[2], argv[3]);
    }
  if ((strcmp (argv[1], "-i") == 0))
    {
      printf ("Inserting %s into %s\n", argv[3], argv[2]);
      insert_file (argv[2], argv[3]);
    }
  return 0;
}
