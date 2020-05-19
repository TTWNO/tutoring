// arrays-classes.cpp

#include <iostream>
#include <string>
#include <vector> // used for easy mode dynamic memory allocation
using namespace std;
class retailitem {
private:
    string name;
    double price;
public:
    // accesors
    string getName() const {
		return name;
	}
	double getPrice()const{
		return price;
	}
	// mutators
    void setName(string newName){
		name = newName;
	}
	void setPrice(double newPrice){
		price = newPrice;
	}
	// input
	void input(){

}
	// output
	void output(){
		cout << name << " $"<< price<< endl;
	}
	// constructor with name and price
    // to use default values in a prototype:
    //      retailitem(string="milk", double=0.99)
	retailitem(string _name="Milk", double _price=0.99){ // if price not given, set automatically to 0.99
        name = _name;
        price = _price;
        cout << "hello" << endl;
    }
    ~retailitem(){ // destructor == opposite of constructor
        cout << "Bye" << endl;
    }
};

// EASY mode dynamic memory allocation
class Store {
private:
    string name;
    vector<retailitem> items; // automatically destructs itself
    int numItems;
public:
    string getName();
    void setName(string);    
    void addItem(retailitem); // changed for easy mode
    void display(); // changed for easy mode
    Store(); // changed for easy mode
};

Store::Store(){
    numItems = 0;
    items = vector<retailitem>();
}

string Store::getName(){
    return name;
}
void Store::setName(string _name){
    name = _name;
}

void Store::addItem(retailitem ri){
    items.push_back(ri); // append ri to items
}

void Store::display(){
    for (int i = 0; i < items.size(); i++){
        items[i].output();
    }
}

int main(){
    retailitem a, b("Butter", 3.99), c("egg");
    retailitem* x = &a;
    retailitem y[5]; // creates five elements; 5 default constructors

    Store w;

    x->output(); // equiv. to a.output()
    b.output();
    c.output();

    w.setName( "Walmart");
    w.addItem(a);
    w.addItem(b);
    w.addItem(c);
    w.addItem(retailitem("Lawnmower", 199.99));

    // destructor is run 8 times: a, b, c, and for each element of y
    return 0;
}