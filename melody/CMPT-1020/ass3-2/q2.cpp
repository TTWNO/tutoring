#include <iostream>
using namespace std;

void num(int a, int b, int c, int i){
  c=a+b;
  cout<< " "<<c;
  a=b;
  b=c;
  i++;
  while (i<20)
    num(int a, int b, int c);
}

int main(){
  int a=0, b=1, c, i=0;
  cout<< a<<" "<<b;
  num(int a, int b, int c);
  return0;
}
