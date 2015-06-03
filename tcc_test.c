
#include <stdio.h>
#include <unistd.h>
#include "easy_tcc.h"

int main (void) {

  puts ("Hello world!");
  c_up ();
  usleep (500000L);
  puts ("Not hello world!");
  usleep (500000L);
  printf ("Bleh!");
  fflush (stdout);
  usleep (250000L);
  cn_eraseLine (CURSOR_TO_BEGINNING);
  fflush (stdout);
  usleep (500000L);  
  c_eraseScreen ();
  int i = 0;
  cn_vert (1);
  
  for (i=1; i<15; ++i) {
    printf ("Vert: %i", i);
    cn_vert (i);
    fflush (stdout);
    usleep (100000L);
  }

  c_eraseScreen ();
  cn_vert (0);
  for (i=0; i<30; ++i) {
    putc ((i%10)+'0', stdout);
  }
  fflush (stdout);

  for (i=0; i<30; ++i) {
    cn_horiz (i);
    putc ('-', stdout);
    fflush (stdout);
    usleep (100000L);
  }

  for (i=0; i<30; ++i) {
    cn_pos (i, 1);
    putc ((i%10)+'0', stdout);
    fflush (stdout);
    usleep (100000L);
  }

  puts ("");
  return 0;
}
