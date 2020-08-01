#include <iostream>
#include <algorithm>
#include <array>
#include "loops.cpp"

void print_arr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}
template <typename T>
void print_arr(T iter, T iter_end)
{

}

int main()
{
    int arr[10] ={1, 2, 3, 4, 10, 9, 8 ,7, 6, 5}; 
    print_arr(arr, 10);
    std::sort(arr, arr+10);
    print_arr(arr, 10);

    std::array<int, 10> arr2 ={1, 2, 3, 4, 10, 9, 8 ,7, 6, 5}; 
    // descending
    std::sort(arr2.begin(), arr2.end());

    // ascending
    std::sort(arr2.rend(), arr2.rbegin());

    for (auto it = arr2.rbegin(); it != arr2.rend(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::array<int, 10>::iterator it;    

    for (auto it = arr2.cbegin(); it != arr2.cend(); it++)
    {
        std::cout << *it << std::endl;
    }

    // must implement the Iterable interface
    std::sort(arr2.begin(), arr2.end(), [](Node a, Node b){
        return a.index > b.index;
    });
}