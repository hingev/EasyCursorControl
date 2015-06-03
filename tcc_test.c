
#include <stdio.h>
#include <unistd.h>
#include "easy_tcc.h"

int main (void) {

  puts ("Hello world!");
  c_up ();
  usleep (500000L);
  puts ("Not hello world!");

  usleep (500000L);

  int i = 0;
  cn_vert (1);
  usleep (500000L);
  for (i=1; i<15; ++i) {
    printf ("Vert: %i", i);
    cn_vert (i);
    fflush (stdout);
    usleep (250000L);
  }
  
  return 0;
}
