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
    Screen (pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c) {  }
    ~Screen () {  }
    char get () const {                         // 隐式内联，返回当前光标所指内容（字符）
        return contents[cursor];
    }
    inline char get (pos ht, pos wd) const;     // 显示内联，返回制定位置上的内容（字符）
    Screen &move (pos r, pos c);                // 在类外定义处内联，将当前光标移动到指定位置
    Screen &set (char);                         // 设置当前光标的内容
    Screen &set (pos, pos, char);               // 设置指定位置的内容
    Screen &display (std::ostream &os);         // 输出可变对象*this中的内容
    const Screen &display (std::ostream &os) const;     // 输出常量对象*this中的内容
    friend class Window_mgr;

private:
    pos cursor = 0;     // 当前光标位置
    pos height = 0, width = 0;      // 屏幕的高、宽
    std::string contents;       // 屏幕中的数据
    void do_display (std::ostream &os) const {
        os << contents << std::endl;
    }

};

#endif
