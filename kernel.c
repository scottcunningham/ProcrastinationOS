/*
 * kernel.c
 *
 * http://arjunsreedharan.org/post/82710718100/kernel-101-lets-write-a-kernel
 */
#include "kio.h"

void kmain(void) {
    char *str = "hello world this is my really long strong. this is seriously a very long strong. gotta be over 80 chars now hahaha!";
    unsigned int i = 0;
    unsigned int j = 0;
    // clear all

    clear();

    /*
    for (i; i < SCREEN_SIZE; i+=2) {
        kputchar('a', i);
    }
    */
    for (j; j < 20; ++j) {
        while (str[i] != 0) {
            kputc(str[i]);
            ++i;
        }
        i = 0;
    }

    return;
}
