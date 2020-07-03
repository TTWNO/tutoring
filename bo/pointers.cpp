#include <iostream>

class Person
{
    // bad practice to make everything punlic.
    // Not a probelm for this excersise though.
    public:
      std::string name;
      int age;
};

// declare all functions first
void swap(int*, int*);
void swapn(int&, int&);
void set_name(Person*, std::string);
void set_name(Person&, std::string);

// standard main function definition
int main(void)
{
    int a = 2, b = 5;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    swapn(a, b);
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    Person t;
    Person o;
    t.name = "Tait";
    t.age = 22;
    o.name = "Bo";
    o.age = -1;

    std::cout << t.name << std::endl;
    set_name(&t, "Tait H.");
    std::cout << t.name << std::endl;
}


// implement functions later
void set_name(Person *p, std::string new_name)
{
    (*p).name = new_name;
}
void set_namen(Person &p, std::string new_name)
{
    p.name = new_name;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y; // copies the value of y into the value of x (using asterisk notation)
    *y = temp;
}

void swapn(int &x, int &y)
{
    int temp = x;
    x = y; 
    y = temp;
}
