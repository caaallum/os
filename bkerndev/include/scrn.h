#ifndef __SCRN_H__
#define __SCRN_H__

#include <util.h>

enum {
    COLOUR_BLACK = 0,
    COLOUR_BLUE,
    COLOUR_GREEN,
    COLOUR_CYAN,
    COLOUR_RED,
    COLOUR_MAGENTA,
    COLOUR_BROWN,
    COLOUR_LIGHT_GREY,
    COLOUR_DARK_GREY,
    COLOUR_LIGHT_BLUE,
    COLOUR_LIGHT_GREEN,
    COLOUR_LIGHT_CYAN,
    COLOUR_LIGHT_RED,
    COLOUR_LIGHT_MAGENTA,
    COLOUR_LIGHT_BROWN,
    COLOUR_WHITE
};

extern void cls();

extern void print_char(unsigned char c);

extern void print(unsigned char *str);

extern __attribute__((format (printf, 1, 2))) int printf(const char *format, ...);

extern void set_text_colour(uint8_t foreground, uint8_t background);

extern void init_video();

#endif//!__SCRN_H__
