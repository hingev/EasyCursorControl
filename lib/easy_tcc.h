
/* Easy terminal cursor controllerb */
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
#define c_eraseScreen() { cn_eraseScreen (ENTIRE_SCREEN); }
#define c_eraseLine() { cn_eraseLine (ENTIRE_LINE); }

#define CURSOR_TO_END 0
#define CURSOR_TO_BEGINNING 1
#define ENTIRE_SCREEN 2
#define ENTIRE_LINE 2

void cn_up (int n);
void cn_down (int n);
void cn_forward (int n);
void cn_backward (int n);
void cn_nextLine (int n);
void cn_prevLine (int n);
void cn_horiz (int x);
void cn_vert (int y);
void cn_pos (int x, int y);
void cn_eraseScreen (int p);
void cn_eraseLine (int p);

#endif
