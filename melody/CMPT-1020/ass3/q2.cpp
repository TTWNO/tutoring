// fibonacci

#include <iostream>
using namespace std;

int fibonacci(int x) {
  if (x <= 1)
    return 0;

  if (x == 2)
    return 1;
  return fibonacci(x - 1) + fibonacci(x - 2);
}

int main() {
  for (int i = 1; i <= 20; i++)
    cout << fibonacci(i) << " ";
}