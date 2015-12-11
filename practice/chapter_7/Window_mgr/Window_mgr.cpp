#include "Window_mgr.h"

void Window_mgr::clear (ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

Window_mgr &Window_mgr::insert_Screen (pos ht, pos wd, char c) {
    Screen s = Screen(ht, wd, c);
    screens.push_back(s);
    return *this;
}

int test_Window_mgr_1 (void) {
    Window_mgr win;
    win.insert_Screen(1, 1, 'a').insert_Screen(2, 2, 'b').insert_Screen(3, 3, 'c');
    win.clear(1);
    return 0;
}

int main (void) {
    test_Window_mgr_1();
}

