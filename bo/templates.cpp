#include <iostream>
#include <tuple>
//using namespace std;
std::tuple<int,int> _swap(int, int);

int main()
{
    int a=1,b=2;
    std::cout << "Before Swap: a = " << a << " b = "<<b<<std::endl;

    auto sol_tup = _swap(a,b);
    std::cout << "After Swap: a = " << std::get<0>(sol_tup) << " b = "<< std::get<1>(sol_tup)<<std::endl;

    return 0;
}

std::tuple<int,int> _swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    
    return std::make_tuple(a,b);
}