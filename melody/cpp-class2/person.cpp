#include <iostream>

using namespace std;

class Person {
    string firstName;
    string lastName;
    int birthYear;
    string city;
    public:
    //accessors
string getFirstName();
string getLastName();
int getBirthYear();
string getCity();
//mutators
void setFirstName(string);
void setLastName(string);
void setBirthYear(int);
void setCity(string);
//input function
void input();
//output function
void output();
//default constructor (no arguments -- Tait)
Person();
//one argument constructor, takes in one string: first name
Person(string);
//two argument constructor, takes in two strings: first and last name
Person(string, string);
//four argument contstructor, takes in three strings and an int: firstName, lastName, city, birthYear
Person(string, string, string, int);
};

void Person::setFirstName(string _FirstName){
	firstName = _FirstName;
}
void Person::setLastName(string _setLastName){
	lastName = _setLastName;
}
void Person::setCity(string _setCity){
	city= _setCity;
}
void Person::setBirthYear(int _setBirthYear){
	birthYear= _setBirthYear;
}
string Person::getFirstName(){
	return firstName;
}
string Person::getLastName(){
	return lastName;
}
string Person::getCity(){
	return city;
}
int Person::getBirthYear(){
	return birthYear;
}
void Person::output()
{
	cout << firstName << " " << lastName << " from " << city << " was born in " << birthYear << endl;;
}
void Person::input(){
	cout << "first name?" << endl;
	getline(cin, firstName);
	cout << "last name?" << endl;
	getline(cin, lastName);
	cout << "city?" << endl;
	getline(cin, city);
	cout << "birth year?" << endl;;
	cin >> birthYear;
}

int main(){

    Person p0("Donald", "Trump", "Washington", 1952);
    Person constructorPerson("Firstname", "Lastname", "city", 2093);

    // Examples of usage once complete:
    // setters
    Person p1;
    p1.setFirstName("Melody");
    p1.setLastName("Shih");
    p1.setCity("Vancouver");
    p1.setBirthYear(2001); // Maybe correct?

    // two string setters
    Person p2("Tait", "Hoyem");

    // four argument setters
    Person p3("Tait", "Hoyem", "Calgary", 2000);
    // getters
    p3.getLastName(); // returns "Hoyem"
    p3.getCity(); // returns "Calgary"
    p3.getBirthYear(); // returns 2000
    p3.getFirstName(); // returns "Tait"

    // output function
    p3.output(); // prints "Tait Hoyem is from Calgary and was born in 2000"

    // input function
    p3.input(); // prompts the user for every variable in the class, then fills it in

    // input and output all in an array
    const int SIZE = 5;
    Person folks[SIZE];



    /*
    Setter format
    void Class::setSomeVariable(varType _someVariable){
        someVariable = _someVariable;
    }
    */
}