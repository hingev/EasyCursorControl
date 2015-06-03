/**
 * @file easy_tcc.h
 * @brief Easy terminal cursor controller.
 *
 * Library is made for **VT100** compatible pseudoterminals.
 */

#ifndef __EASY_TCC__
#define __EASY_TCC__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief Puts the **escape sequence** + @c STR to **stdout**.
 * @param STR string containing the rest of **CSI** code
 */
#define CSI(STR) { printf ("\033[%s", STR); }

/**
 * @brief Used in function definitions.
 */
#define _DEF_FUNC(format_str, ...)		\
  {						\
    char temp[20];				\
    sprintf (temp, format_str, ##__VA_ARGS__);	\
    CSI (temp);					\
  }
    
/**
 * @brief Move cursor up one cell.
 */
#define c_up() { cn_up (1); }
/**
 * @brief Move cursor down one cell.
 */
#define c_down() { cn_down (1); }
/**
 * @brief Move cursor right one cell.
 */
#define c_forward() { cn_forward (1); }
/**
 * @brief Move cursor left one cell.
 */
#define c_backward() { cn_backward (1); }
/**
 * @brief Move cursor to the beginning of the next line.
 */
#define c_nextLine() { cn_nextLine (1); }
/**
 * @brief Move cursor to the beginning of the previous line.
 */
#define c_prevLine() { cn_prevLine (1); }
/**
 * @brief Erase the whole screen.
 */
#define c_eraseScreen() { cn_eraseScreen (ENTIRE_SCREEN); }
/**
 * @brief Erase the line the cursor is in.
 */
#define c_eraseLine() { cn_eraseLine (ENTIRE_LINE); }

/**
 * @brief Used in @a cn_eraseScreen and @a cn_eraseLine
 * to erase from cursor to the end of the line.
 */
#define CURSOR_TO_END 0
/**
 * @brief Used in @a cn_eraseScreen and @a cn_eraseLine
 * to erase from cursor to the beginning of the line.
 */
#define CURSOR_TO_BEGINNING 1
/**
 * @brief Used in @a cn_eraseScreen
 * to erase the whole screen.
 */
#define ENTIRE_SCREEN 2
/**
 * @brief Used in @a cn_eraseScreen
 * to erase the whole line.
 */
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
