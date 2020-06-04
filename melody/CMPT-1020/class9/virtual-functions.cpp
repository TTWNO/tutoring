#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "Hello" << endl;
    }
    virtual void eat()
    {
        cout << "Animal eats generaic food" << endl;
    }
};

class Cat : public Animal
{
public:
    Cat()
    {
        cout << "Hola" << endl;
    }
    void eat()
    {
        cout << "Cat eats rats" << endl;
    }
};

// without eat being a virtual function, xyz->eat will always run the Animal version of the function; never the Cat version.
// This is even when a Cat is passed into this function (which is allowed because Cat is a subtype of Animal)
void func(Animal *xyz)
{
    xyz->eat();
}

int main()
{
    Cat* c = new Cat;
    func(c); // if Animal::eat() is a virtual function: will print "Cats eat rats";
             //     if Animals::eat() is not a virtual function, this will print "Animal eats generic food" 
    return 0;
}