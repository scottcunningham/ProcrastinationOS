#pragma once
#ifndef KIO_H

#define VIDPTR ((char*)0xb8000)
#define COLS 24
#define ROWS 80
#define MOD 2
#define SCREEN_SIZE (COLS*ROWS*MOD)
// light grey on black background
#define DEFAULT_COLOUR 0x07

int xpos, ypos;

int clear();

int kputchar(char c, int pos);

int kputchar_colour(char c, int pos, unsigned char fg_colour,
        unsigned char bg_colour);

enum COLOURS
{
    COLOUR_BLACK = 0,
    COLOUR_BLUE = 1,
    COLOUR_GREEN = 2,
    COLOUR_CYAN = 3,
    COLOUR_RED = 4,
    COLOUR_MAGENTA = 5,
    COLOUR_BROWN = 6,
    COLOUR_LIGHT_GREY = 7,
    COLOUR_DARK_GREY = 8,
    COLOUR_LIGHT_BLUE = 9,
    COLOUR_LIGHT_GREEN = 10,
    COLOUR_LIGHT_CYAN = 11,
    COLOUR_LIGHT_RED = 12,
    COLOUR_LIGHT_MAGENTA = 13,
    COLOUR_LIGHT_BROWN = 14,
    COLOUR_WHITE = 15
};

unsigned short make_colour(enum COLOURS fg, enum COLOURS bg);

int kputc(char c);
int kputs(char *s);

#define KIO_H
#endif
