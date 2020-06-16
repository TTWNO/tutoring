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

    // .insert(make_pair(x, y)) == [x] = y
    employees.insert(make_pair(110, "Beth Young"));
    employees.insert(make_pair(111, "Raymond Yun"));

    // .at(x) == [x]
    cout << employees.at(110) << endl;

    // can also use "auto element"
    for (pair<int, string> element : employees)
    {
        // element.first = key;
        // element.second = value
        cout << "[" << element.first << "]" << ": " >> element.second << endl;
    }
}