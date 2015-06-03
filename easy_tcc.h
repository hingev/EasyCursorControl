
/* Easy terminal cursor controller */
#ifndef __EASY_TCC__
#define __EASY_TCC__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CSI(STR) { printf ("\033[%s", STR); }

#define _DEF_FUNC(format_str, ...)		\
  {						\
    char temp[20];				\
    sprintf (temp, format_str, ##__VA_ARGS__);	\
    CSI (temp);					\
  }
    

#define c_up() { cn_up (1); }
#define c_down() { cn_down (1); }
#define c_forward() { cn_forward (1); }
#define c_backward() { cn_backward (1); }
#define c_nextLine() { cn_nextLine (1); }
#define c_prevLine() { cn_prevLine (1); }

void cn_up (int n);
void cn_down (int n);
void cn_forward (int n);
void cn_backward (int n);
void cn_nextLine (int n);
void cn_prevLine (int n);
void cn_horiz (int x);
void cn_vert (int y);
void cn_pos (int x, int y);

#endif
