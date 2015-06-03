
/* Border test - draw a border around terminal screen */

#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "easy_tcc.h"

int main (void) {

  struct winsize ws;
  ioctl (fileno (stdout), TIOCGWINSZ, &ws);

  short height = ws.ws_row;
  short width  = ws.ws_col;
  int i = 0;

  c_eraseScreen ();
  cn_pos (1, 1);

  for (i=0; i<width; ++i)
    putc ('#', stdout);

  cn_pos (1, height);
  for (i=0; i<width; ++i)
    putc ('#', stdout);

  for (i=1; i<height; ++i) {
    cn_pos (1, i);
    putc ('#', stdout);
    cn_pos (width, i);
    putc ('#', stdout);
  }

  // print text in the middle
  char temp[40];
  strcpy (temp, "Bordered screen.. Yaay!!");
  cn_pos ((width-strlen (temp))/2, height / 2);
  puts (temp);
  
  fflush (stdout);
  scanf ("%s", temp);
  
  return 0;
  
}
