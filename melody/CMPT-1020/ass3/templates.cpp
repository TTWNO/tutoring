    #include <iostream>
    using namespace std;

    template <typename T>
    T total(T a[], int size) {
    T sum = 0;
    for (int i = 0; i < size; i++)
        sum += a[i];
    return sum;
    }

    int main() {
    int x[] = {1, 3, 5};
    double y[] = {1.2, 3.4, 5.6};
    cout<< total(x, 3)<<" "<<total(y, 3);
    return 0;
    }