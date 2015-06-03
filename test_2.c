
#include <stdio.h>
#include <unistd.h>
#include "easy_tcc.h"

int main (void) {
  int x, y;
  cn_vert (1);
  while (1) {
    c_eraseScreen ();
    printf ("Enter vertical line number: ");
    scanf ("%d", &y);
    cn_vert (y);
    c_eraseScreen ();
    printf ("Enter horizontal column number: ");
    scanf ("%d", &x);
    cn_pos (x, y);
    c_eraseScreen ();
    putc ('#', stdout);
    fflush (stdout);
    usleep (500000L);
  }
  return 0;
}
