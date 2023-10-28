#include <iostream>

extern int x;

int main(int argc, char const *argv[])
{
    // this will make a linker error, because no such x exists..
    std::cout << x << std::endl;
    return 0;
}
