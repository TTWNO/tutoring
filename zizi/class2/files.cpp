#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ofstream file("tuna.txt", std::ios::app);
    file << "I like tuna!" << std::endl;
    file.close();

    std::ifstream file2("tuna.txt", std::ifstream::in);
    std::string line;
    while(getline(file2, line))
    {
        std::cout << line;
    }
    file2.close();
    return 0;
}