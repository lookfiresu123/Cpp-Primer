#ifndef _LINK_SCREEN_H
#define _LINK_SCREEN_H 1

#include "Screen.h"

class Link_screen {

public:
    Link_screen *prev;
    Link_screen *next;
    // friend Screen player (Screen);
    // friend Screen &Screen::display (std::ostream &os);
    // friend class Screen;

private:
    Screen window;

};

//Screen player (Screen);

#endif
