/*! \file easy_tcc.c */

#include "easy_tcc.h"

/**
 * @brief Move the cursor up with given number of cells.
 * @param n integer - the amount of cells
 */
void cn_up (int n){
  _DEF_FUNC ("%dA", n);
}

/**
 * @brief Move the cursor down with given number of cells.
 * @param n integer - the amount of cells
 */
void cn_down (int n){
  _DEF_FUNC ("%dB", n);
}

/**
 * @brief Move the cursor to the right with given number of cells.
 * @param n integer - the amount of cells
 */
void cn_forward (int n){
  _DEF_FUNC ("%dC", n);
}

/**
 * @brief Move the cursor to the left with given number of cells.
 * @param n integer - the amount of cells
 */
void cn_backward (int n){
  _DEF_FUNC ("%dD", n);
}

/**
 * @brief Move the cursor to the beginning of the next @b n-th line.
 * @param n integer for selecting the @b n-th line
 */
void cn_nextLine (int n){
  _DEF_FUNC ("%dE", n);
}

/**
 * @brief Move the cursor to the beginning of the previous @b n-th line.
 * @param n integer for selecting the @b n-th line
 */
void cn_prevLine (int n){
  _DEF_FUNC ("%dF", n);
}

/**
 * @brief Move the cursor horizontally to the @b x-th cell.
 * @param x the horizontal coordinate.
 *
 * Coordinates are counted from @b 1 (the most left part) to @b W (the most right part),
 * where @b W is the width of the terminal window
 */
void cn_horiz (int x){
  _DEF_FUNC ("%dG", x);
}

/**
 * @brief Move the cursor vertically to the @b y-th cell.
 * @param y the vertical coordinate
 *
 * Coordinates are counted from @b 1 (the upper part) to @b H (the lowest part),
 * where H is the height of the terminal window
 */
void cn_vert (int y){
  _DEF_FUNC ("%dH", y);
}

/**
 * @brief Move the cursor to given @b x and @b y coordinates.
 * @param x the horizontal coordinate
 * @param y the vertical coordinate  
 */
void cn_pos (int x, int y){
  _DEF_FUNC ("%d;%dH", y, x);
}

/**
 * @brief Erase the screen.
 * @param p if @a CURSOR_TO_END, then erase from cursor to end,
 * if @a CURSOR_TO_BEGINNING, then erase from beginning to the cursor location,
 * and if @a ENTIRE_SCREEN, then erase the whole screen
 *
 * For erasing the entire screen, @a c_eraseScreen macro can be used
 */
void cn_eraseScreen (int p) {
  _DEF_FUNC ("%dJ", p);
}

/**
 * @brief Erase the screen.
 * @param p if @a CURSOR_TO_END, then erase from cursor to end,
 * if @a CURSOR_TO_BEGINNING, then erase from beginning to the cursor location,
 * and if @a ENTIRE_LINE, then erase the whole line
 *
 * For erasing the whole line, @a c_eraseLine macro can be used
 */
void cn_eraseLine (int p) {
  _DEF_FUNC ("%dK", p);
}
