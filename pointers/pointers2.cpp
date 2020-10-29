#include <iostream>

void add1(int& x){
  x++;
}
void add1_alt(int& x){
  x += 1;
}

void add_arbitrary(int& x, int add){
  x += add;
}

int main(){
  int i = 0;

  std::cout << "I = " << i << std::endl;
  add1(i);
  std::cout << "I = " << i << std::endl;
  add1_alt(i);
  std::cout << "I = " << i << std::endl;
  add_arbitrary(i, 15);
  std::cout << "I = " << i << std::endl;
  return 0;
}
