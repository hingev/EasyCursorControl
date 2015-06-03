
/* Border test - draw a border around terminal screen */

#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "easy_tcc.h"

double sqrt (double num) {
  int steps = 1000;
  double result = 1;
  if (num == 0) {
    result = 0;
    steps = 0;
  }
  while (steps --) {
    result = 0.5 * (result + (double)num / result);
  }

  return result;
}

int main (void) {

  struct winsize ws;
  ioctl (fileno (stdout), TIOCGWINSZ, &ws);

  short height = ws.ws_row;
  short width  = ws.ws_col;
  int i = 0;

  c_eraseScreen ();
  cn_pos (1, 1);

  // draw a circle, R=height/2
  double x, y, R = height/2.0;
  for (x=-R; x <= R; x+=0.001) {
    y = sqrt (R*R - x*x);
    cn_pos ((int)(width/2.0 + x), (int)(height/2.0 + y));
    putc ('0', stdout);
    cn_pos ((int)(width/2.0 + x), (int)(height/2.0 - y));
    putc ('0', stdout);    
  }

  for (i=10; i<15; ++i) {
    cn_pos (width/2 - i, height/2 - 10);
    putc ('#', stdout);
    cn_pos (width/2 + i, height/2 - 10);
    putc ('#', stdout);
  }

  for (i=9; i<16; ++i) {
    cn_pos (width/2 - i, height/2 - 9);
    putc ('#', stdout);
    cn_pos (width/2 + i, height/2 - 9);
    putc ('#', stdout);
  }

  for (i=0; i<6; ++i) {
    cn_pos (width/2 - i, height/2 + 10);
    putc ('-', stdout);
    cn_pos (width/2 + i, height/2 + 10);
    putc ('-', stdout);
  }  

  char temp[40];
  fflush (stdout);
  scanf ("%s", temp);
  c_eraseScreen ();
  
  return 0;
  
}
