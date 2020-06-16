#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int, string> employees = {
        {101, "Chirs Jones"}, {102, "Jessica Smith"},
        {103, "Amanda Klasson"}
    };
    employees[110] = "Beth Young";
    employees[111] = "Raymond Yun";

    cout << employees[0] << endl; // will crash because nothing is assigned at index 0
    
}