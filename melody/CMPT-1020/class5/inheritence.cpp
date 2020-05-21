#include <iostream>
#include <string>

using namespace std;
class Person
{
protected: // allows child classes to access these variables
    string firstName;
    string lastName;
    int birthYear;
public:
    string getFirstName()
    {
        return firstName;
    }
    string getLastName()
    {
        return lastName;
    }
    int getBrithYear()
    {
        return birthYear;
    }

    void setLastName(string x)
    {
        lastName = x;
    }
    void setFirstName(string x)
    {
        firstName = x;
    }
    void setBirthYear(int x)
    {
        birthYear = x;
    }
    void input()
    {
		cout << "first name?" << endl;
		cin >> firstName;
		cout << "last name?" << endl;
        cin>> lastName;
		cout << "birth year?" << endl;
		cin >> birthYear;
	}

    void output(){
		cout << "first name: "<< firstName<< endl;
        cout<< "first name";
	}
    
    Person(){
		firstName = " ";
        lastName = " ";
        birthYear = 2000;
	}
    
    Person(string f, string l, int b){
		firstName = f;
        lastName = l;
        birthYear = b;
	}
    ~Person();
};

class Student : public Person
{
private:
    double gpa;
public:
    void setGpa(double g)
    {
        gpa=g;
    }

    double getGpa()
    {
	    return gpa;
    }

	Student()
    {
        gpa = 4;
    }
    ~Student();
    void input()
    {
		cout << "first name?" << endl;
		cin >> firstName;
		cout << "last name?" << endl;
        cin>> lastName;
		cout << "birth year?" << endl;
		cin >> birthYear;
        cout << "GPA?" << endl;
        cin >> gpa;
	}
};


int main()
{
    Person a;
    Student b; // the Person constructor is run first; then the Student cosntructor

    b.input(); // Student inherits input from Person
    b.output(); // it also inherits output

    // when an object is destroyed, it destoryes the *child* (Student) first, and then destructs the parent (Person)
    return 0;
}