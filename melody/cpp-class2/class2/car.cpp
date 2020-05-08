
/* START OF CAR 
	NOT DONE!!!!
*/
#include <iostream>

using namespace std;
// test test 
// brand, colour, year, model, price


class Car{
	string brand, colour, model;
	int year;
	double price;

public:
	string setModel();
	string setColour();
	string getModel() const;
	string getColour() const;
	void input();
};
// returnType Class::methodName()
void Car::input(){
	cout << "model?";
    //For string: getline(cin, variableToFill) 

}
Car::Car()
{
    brand = "BMW";
    model = "FunModel";
    year = 2012;
    price = 69992.99;
    colour = "Purple";
}

