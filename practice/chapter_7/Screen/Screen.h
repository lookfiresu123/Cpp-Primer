#ifndef _SCREEN_H
#define _SCREEN_H 1

#include <iostream>
#include <string>

using namespace std;

/* 类Screen表示显示器中的一个窗口 */
class Screen {

public:
    typedef std::string::size_type pos;     // using pos = std::string::size_type;
    Screen () = default;
    Screen (pos ht, pos wd, pos cnt) : height(ht), width(wd), contents(cnt, ' ') {  }
    Screen (pos ht, pos wd, char c) : height(ht), width(wd), contents(1, c) {  }
    char get () const {                         // 隐式内联
        return contents[cursor];
    }
    inline char get (pos ht, pos wd) const;     // 显示内联
    Screen &move (pos r, pos c);                // 在类外定义处内联
private:
    pos cursor = 0;     // 当前光标位置
    pos height = 0, width = 0;      // 屏幕的高、宽
    std::string contents;       // 屏幕中的数据

};

#endif
