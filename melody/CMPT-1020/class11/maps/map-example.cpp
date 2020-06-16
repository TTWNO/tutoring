#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    // maps allow you to use anything as your "key" to access any type of "value"
    map<string, string> phoneBook;
    phoneBook["Chris"] = "604-111-1111";
    cout << phoneBook["Chris"] << endl;

    phoneBook["Jack"] = "604-222-1111";
    cout << phoneBook["Jack"] << endl;
    // overwrite phoneBook["Jack"] with new string
    phoneBook["Jack"] = "604-333-1111";
    cout << phoneBook["Jack"] << endl;
    cout << phoneBook.size() << endl; // 2



    return 0;
}