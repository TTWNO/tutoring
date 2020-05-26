#include <iostream>
#include <string>
using namespace std;
class retailItem
{
private:
	string name;
	double price;
public:
	string getName();
	double getPrice();
	void setName(string);
	void setPrice(double);
	void input();
	void output();
	retailItem(string ="Milk",double=0.99);
};
string retailItem::getName()
{
	return name;
}
double retailItem::getPrice()
{
	return price;
}
void retailItem::setName(string x)
{
	name = x;
}
void retailItem::setPrice(double x)
{
	price = x;
}
void retailItem::input()
{	cout << "Name? ";
	getline(cin,this->name);
	cout << "Price? ";
	cin >> this->price;
}
void retailItem::output()
{	
	cout << name << " is worth $" << price << endl;
}
retailItem::retailItem(string x, double y)
{	name = x;
	price = y;
}

class Store
{
private:
	string name;
	retailItem *items;
	int numItems;
	int capacity;
public:
	string getName();
	void setName(string);
	Store(int);
	Store(const Store& existing)
	{
		this->name = existing.name;
		this->numItems = existing.numItems;
		this->capacity = existing.capacity;
		this->items = new retailItem[this->capacity];
		for (int i = 0; i < numItems; i++)
			items[i] = existing.items[i];
	}
	void operator=(const Store& existing)
	{
			// delete previosuly allocated array before reallocating;
		//		only needed in the assignment override, not in the copy constructor
		delete[] this->items; 

		this->name = existing.name;
		this->numItems = existing.numItems;
		this->capacity = existing.capacity;
		this->items = new retailItem[this->capacity];
		for (int i = 0; i < numItems; i++)
			items[i] = existing.items[i];
	}
	~Store();
	void addItem(retailItem);
	void display();
	void remove(string);
	void sortPriceAsc();
};
void Store::sortPriceAsc()
{
	for (int k = 1; k < numItems; k++)
	{
		for (int i = 0; i < numItems - k; i++)
		{
			if (items[i].getPrice() > items[i + 1].getPrice())
				swap(items[i], items[i + 1]);
		}
	}
}
void Store::remove(string e)
{
	for (int i = 0; i < numItems; i++)
	{
		if (items[i].getName() == e) {
			numItems--;
			items[i] = items[numItems];
			return;
		}
	}
	cout << "Not found\n";
}
void Store::addItem(retailItem x)
{
	if (numItems < capacity)
	{
		items[numItems] = x;
		numItems++;
	}
	else
		cout << "store is full\n";
}
void Store::display()
{
	for (int i = 0; i < numItems; i++)
		items[i].output();
}
Store::Store(int cap)
{
	numItems = 0;
	capacity = cap;
	items = new retailItem[cap];
}
string Store::getName()
{
	return name;
}
void Store::setName(string x)
{
	name = x;
}
Store::~Store()
{
	delete[]items;
}

int main()
{
	retailItem a("Milk",3.99), b("Butter", 3.99), c("egg",1.99), d("cheese", 5.99);
	Store w(1000), z(1000);
	
	w.setName( "Walmart");
	w.addItem(a);
	w.addItem(b);
	w.addItem(c);
	w.addItem(d);
	w.addItem(c);
	w.display();
	Store x = w;
	z = w;
	cout << "\n\n";
	x.display();
	x.addItem(a);
	x.remove("Butter");
	cout << "\n\n";

	x.display();
	
	cout << "\n\n";
	w.display();
	
	
	return 0;
}