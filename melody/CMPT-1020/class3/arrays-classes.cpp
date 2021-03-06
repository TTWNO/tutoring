// arrays-classes.cpp

#include <iostream>
#include <string>
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

// HARD mode dynamic memory allocation
class Store {
private:
    string name;
    
    retailitem *items;
    int capacity;

    int numItems;
public:
    string getName();
    void setName(string);    
    void addItem(retailitem);
    void display();
    void remove(string e){
        for (int i = 0; i < numItems; i++){
            if (items[i].getName() == e){
                numItems--;
                items[i] = items[numItems]; // use the last item to fill in the hole of the removed item
                return; // if item found, quit function
            }
        }
    }
    void sortPriceAsc(){
        for (int k = 1; k < numItems; k++){
            for (int i = 0; i < numItems; i++){
                if (items[i].getPrice() > items[i + 1].getPrice()){
                    swap(items[i], items[i+1]);
                }
            }
        }
    }
    Store(int);
    // copy constructor
    Store(const Store& existing)
    {
        this->name = existing.name;
        this->numItems = existing.numItems;
        this->capacity = existing.capacity;
        this->items = new retailitem[this->capacity];
        // copy individual items
        for (int i = 0; i < this->capacity; i++){
            this->items[i] = existing.items[i];
        }
    }
    ~Store();
};

Store::Store(int _capacity){
    numItems = 0;
    capacity = _capacity;
    items = new retailitem[capacity];
}
Store::~Store(){
    delete[] items;
}

string Store::getName(){
    return name;
}
void Store::setName(string _name){
    name = _name;
}

void Store::addItem(retailitem ri){
    if ( numItems < capacity){
        items[numItems++] = ri; // use numItems, then increment after statement is executed
    } else {
        cout << "store is full" << endl;
    }
}

void Store::display(){
	for (int i = 0; i < numItems; i++){
        items[i].output();
    }
}

int main(){
    retailitem a, b("Butter", 3.99), c("egg", 1.99), d("cheese", 5.99);
    retailitem* x = &a;
    retailitem y[5]; // creates five elements; 5 default constructors

    Store w(1000), g(1000);

    x->output(); // equiv. to a.output()
    b.output();
    c.output();

    // adding and removing items
    w.setName( "Walmart");
    w.addItem(a);
    w.addItem(b);
    w.addItem(c);
    w.addItem(d);
    w.addItem(c);
    cout << "Before: " << endl;
    w.display();
    w.remove("Butter");
    cout << endl << endl << "After: " << endl; // endls for padding
    w.display();
    w.addItem(retailitem("Lawnmower", 199.99));

    // copying 
    g = w; // copies all information, including the array from w. This is possible because of the copy constructor 
    g.display(); // same as w.display() at this time

    g.addItem(retailitem("Winchester .22", 249.99));
    g.display(); // now will include a new Winchester; w will not contain the Winchester

    // destructor is run 8 times: a, b, c, and for each element of y
    return 0;
}
