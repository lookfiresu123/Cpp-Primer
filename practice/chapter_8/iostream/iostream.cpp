#include <iostream>

bool debug_istream (std::istream &is) {
    std::ios_base::iostate state = is.rdstate();
    // std::cout << state << std::endl;
    if (state == 0)
        std::cout << "well input" << std::endl;
    else if ((state & is.badbit) != 0)
        std::cout << "bad input" << std::endl;
    else if ((state & is.eofbit) != 0)
        std::cout << "eof input" << std::endl;
    else if ((state & is.failbit) != 0)
        std::cout << "fail input" << std::endl;
    return state == 0 ? true : false;
}

int main (void) {
    int temp;
    debug_istream(std::cin);
    while (std::cin >> temp)
        debug_istream(std::cin);
    debug_istream(std::cin);
    std::cin.clear();
    return 0;
}
