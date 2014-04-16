#include "kio.h"

int clear() {
    int i;
    for (i = 0; i < SCREEN_SIZE; ++i) {
        VIDPTR[i] = '\0';
        VIDPTR[i+1] = 0x07;
    }
    return 0;
}

int kputchar(char c, int pos) {
    VIDPTR[pos] = c;
    VIDPTR[pos+1] = 0x07;
    return 0;
}

int kputchar_colour(char c, int pos, unsigned char fg_colour,
        unsigned char bg_colour) {
    VIDPTR[pos] = c;
    VIDPTR[pos+1] = fg_colour << 2 + bg_colour;
    return 0;
}

int kputc(char c) {
    int pos = (ypos*COLS) + xpos;
    kputchar(c, pos);
    xpos += 2;
    if (xpos >= COLS) {
        xpos = 0;
        ypos += 1;
    }
    if (ypos >= ROWS) {
        ypos = 0;
        xpos = 0;
    }
}

unsigned short make_colour(enum COLOURS fg, enum COLOURS bg) {
    return fg | bg << 4;
}
