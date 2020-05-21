#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    string model; // instance
    int year; // instance
    static int numCars; // static
public:
    static int getNumCars(); // this method will only be allowed to access and change static variables;
    // ... much like const, which only allows you to *access* and not modify variables: it is a restriction on what can be done within the method.
    
    string getModel()
    {
        return model;
    }
    int getYear()
    {
        return year;
    }
    void setModel(string x)
    {
        model = x;
    }
    void setYear(int x)
    {
        year = x;
    }
    Car();
    Car(string, int);
    ~Car()
    {
        numCars--;
    }
    void output()
    {
        cout << model << " made in " << year << endl;
    }
};
int Car::numCars = 0;

int Car::getNumCars() // the method is already labled as "static int" in the class; in this case there is no need to define it as static again
{
    return numCars;
}

Car::Car()
{
    model = "Toyota Camry";
    year = 2020;
    numCars++;
}
Car::Car(string x, int y)
{
    model = x;
    year = y;
    numCars++;
}

int main()
{
    cout << Car::getNumCars() << endl; // will print 0; you are allowed to do this because it is a static function, no object has to exist to call this method
    Car a, b, c;
    cout << a.getNumCars() << endl; // will print 3
    Car d("Tesla Model X", 2019);
    cout << c.getNumCars() << endl; // will print 4
    cout << a.getNumCars() << endl; // will also print 4
    
    // code block with seperate scope
    {
        Car e, f("Tesla Model S", 2018);
        cout << b.getNumCars() << endl; // will print 6
    }
    cout << a.getNumCars() << endl; // will print 4; e, f get destroyed; destructor contains 'numCars--;' statement.
    cout << Car::getNumCars() << endl; // will also print 4; it does not need an instantiation to grab this varialbe; the method *must* be labeled static
    a.output();
    return 0;
}