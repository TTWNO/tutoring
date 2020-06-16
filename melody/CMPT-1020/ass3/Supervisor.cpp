#include <iostream>

using namespace std;

class Employee{
protected:
    string name;
    int number;
public:
    string getName(){
        return name;
    }

    int getNumber(){
        return number;
    }

    void setName(string n){
        name=n;
    }

    void setNumber(int num){
        number=num;
    }

    virtual void input(){
        cout<< "Employee full name?"<<endl;
        cin>> name;
        cout<< "Employee number"<<endl;
        cin>> number;
    }
    
    Employee(){
        name=" ";
        number=0;
    }

    Employee(string n){
        name=n;
        number=0;
    }

    Employee(string n, int num){
        name=n;
        number=num;
    }
};

class ShiftSupervisor: public Employee{
    double salary;
    double boness;

public:
    double getSalary(){
        return salary;
    }

    double getBoness(){
        return boness;
    }

    void setSalary(double s){
        salary=s;
    }

    void setBoness(double b){
        boness=b;
    }

    void input(){
        Employee::input();
        cout<< "salary?"<<endl;
        cin>> salary;
        if (salary<0)
            input();
        cout<< "boness?"<<endl;
        cin>>boness;
        if (boness<0)
            input();
    }

    void display(){
        cout<< "Employee full name: "<<name<<endl<<"Employee number: "<<number<<endl<<"salary: "<<salary<<endl<<"boness: "<<boness<<endl;
    }

    ShiftSupervisor (){
        salary=0;
        boness=0;
    }

    ShiftSupervisor (double s){
        salary=s;
        boness=0;
    }

    ShiftSupervisor (double s, double b){
        salary=s;
        boness=b;
    }
};

int main(){
    ShiftSupervisor s[2];
    for (int i=0; i<3; i++){
        cout<< "shift supervisor "<<+i<<":"<<endl;
        s[i].input();
    }

    for (int i=0; i<3; i++)
        s[i].display();
}
