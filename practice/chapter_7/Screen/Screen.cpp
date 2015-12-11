#include "Screen.h"

/* 获得指定位置的内容（字符） */
char Screen::get (pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

/* 将当前光标移动到制定位置 */
inline Screen &Screen::move (pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

/* 设置当前光标的内容 */
inline Screen &Screen::set (char c) {
    contents[cursor] = c;
    return *this;
}

/* 设置指定位置的内容 */
inline Screen &Screen::set (pos r, pos c, char ch) {
    contents[r * width + c] = ch;
    return *this;
}

// 输出可变对象*this中的内容
inline Screen &Screen::display (std::ostream &os) {
    do_display(os);
    return *this;
}

// 输出常量对象*this中的内容
inline const Screen &Screen::display (std::ostream &os) const {
    do_display(os);
    return *this;
}

#define DO_TEST_SCREEN_1 1

/* 练习7.27 */
int test_screen_1 (void) {
    Screen myScreen(5, 5, 'x');
    myScreen.move(4, 0).set('#').display(std::cout);
    std::cout << "\n";
    myScreen.display(std::cout);
    std::cout << "\n";
    return 0;
}

/*
int main (void) {
#if DO_TEST_SCREEN_1
    test_screen_1();
#endif
    return 0;
}
*/
