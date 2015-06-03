
#include "easy_tcc.h"

void cn_up (int n){
  _DEF_FUNC ("%dA", n);
}

void cn_down (int n){
  _DEF_FUNC ("%dB", n);
}

void cn_forward (int n){
  _DEF_FUNC ("%dC", n);
}

void cn_backward (int n){
  _DEF_FUNC ("%dD", n);
}

void cn_nextLine (int n){
  _DEF_FUNC ("%dE", n);
}

void cn_prevLine (int n){
  _DEF_FUNC ("%dF", n);
}

void cn_horiz (int x){
  _DEF_FUNC ("%dG", x);
}

void cn_vert (int y){
  if (y == 1)
    y = 0;
  _DEF_FUNC ("%dH", y);
}

void cn_pos (int x, int y){
  _DEF_FUNC ("%d;%dH", y, x);
}

void cn_eraseScreen (int p) {
  _DEF_FUNC ("%dJ", p);
}

void cn_eraseLine (int p) {
  _DEF_FUNC ("%dK", p);
}
