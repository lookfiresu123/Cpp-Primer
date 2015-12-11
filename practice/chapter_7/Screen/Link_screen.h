#ifndef _LINK_SCREEN_H
#define _LINK_SCREEN_H 1

#include "Screen.h"

class Link_screen;

class Link_screen {
    Screen window;
    Link_screen *prev;
    Link_screen *next;
};

#endif
