#include <iostream>

void print_in_binary(int x)
{

}

int main()
{
    unsigned int x = 63;
    unsigned int y = x & 0b1111;
    std::cout << y << std::endl; // prints 15

    unsigned int n = 0xa2; 
    unsigned int nr = n & 0xf; // get the first four bits
    unsigned int nl = n & 0xf0; // get the second four bits
    std::cout << nl << std::endl; // prints 10
    std::cout << nr << std::endl; // prints 2
}