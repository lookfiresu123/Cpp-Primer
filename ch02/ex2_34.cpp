#include <iostream>

int main()
{
    int i = 0, &r = i;
    auto a = r;   // a is an int (r is an alias for i, which has type int)

    const int ci = i, &cr = ci;     // ci is an const int and cr is binded to an const int
    auto b = ci; // b is an int (top-level const in ci is dropped), because modify of b will not change ci (ci is const)
    auto c = cr; // c is an int (cr is an alias for ci whose const is top-level), because modify of c will not change ci and cr (ci and cr is const)
    auto d = &i; // d is an int* (& ofan int objectis int*), although modify of *d will change i, the i is not const and can be changed
    auto e = &ci; // e is const int*(& of a const object is low-level const), because modify of *e will change ci (ci is const)

    const auto f = ci; // deduced type of ci is int; f has type const int
    auto &g = ci; // g is a const int& that is bound to ci, because modify of g will change ci (ci is const)

    a = 42; b = 42; c = 42; *d = 42; e = &c;

    return 0;
}
