#include <iostream>

void shit();

int main()
{
    int favorite_number;
    std::cout << "Please enter your favorite number between 1-100" << std::endl;
    std::cin >> favorite_number;
    std::cout << "Wow, " << favorite_number << " Is my favorite number too" << std::endl;
    shit();
    return 0;
}