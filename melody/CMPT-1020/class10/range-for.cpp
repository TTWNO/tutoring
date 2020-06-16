#include <iostream>
using namespace std;

int example()
{
    int x[5] = {6, 7, 5, 7, 3};
    for (int i = 0; i < 5; i++)
    {
        cout << x[i] << endl;
    }
    // y gets set to x on every loop
    for (int y : x)
    {
        cout << y << endl;
    }

    return 0;
}

int main(){
    int a[5], t=0;
    for (int& x: a){
        cin >> x;
    }

    for (int x: a){
        t += x;
        cout << t;
    }
    return 0;
}