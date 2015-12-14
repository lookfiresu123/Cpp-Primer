#ifndef _WINDOW_MGR_H
#define _WINDOW_MGR_H 1

#include <vector>
#include "../Screen/Screen.h"

class Window_mgr {

public:
    using ScreenIndex = std::vector<Screen>::size_type;     // 窗口中每个屏幕的编号
    typedef std::string::size_type pos;
    Window_mgr() = default;
    void clear (ScreenIndex);       // 将指定下标的Screen中的内容设置为空白
    Window_mgr &insert_Screen (pos ht, pos wd, char c);
    ScreenIndex addScreen (const Screen &);

private:
    std::vector<Screen> screens;
};

#endif
