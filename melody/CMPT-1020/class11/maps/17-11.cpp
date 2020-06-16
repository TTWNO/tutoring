#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    // Create a map containing employee IDs and names.
    map<int, string> employees = {
        {101, "Chris Jones"}, {102, "Jessica Smith"},
        {103, "Amanda Stevens"}, {104, "Will Osborn"}
    };

    // create an iterator
    map<int, string>::iterator iter;

    // Use the iterator to dispaly each element in the map.
    for (iter = employees.begin(); iter != employees.end(); iter++)
    {
        // -> = access element of pointer
        cout << "ID: " << iter->first
             << "\tName: " << iter->second << endl;
    }

    return 0;
}