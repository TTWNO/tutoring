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

class ProductionWorker: public Employee{
    int shift;
    double payRate;

public:
    int getShift(){
        return shift;
    }

    double getPayRate(){
        return payRate;
    }

    void setShift(int s){
        shift=s;
    }

    void setPayRate(double p){
        payRate=p;
    }

    void input(){
        Employee::input();
        cout<< "shift?"<<endl;
        cin>> shift;
        if (shift!=1 || shift!=2)
            input();
        cout<< "pay rate?"<<endl;
        cin>>payRate;
        if (payRate<0)
            input();
    }

    void display(){
        cout<< "Employee full name: "<<name<<endl<<"Employee number: "<<number<<endl<<"shift: "<<shift<<endl<<"pay rate: "<<payRate<<endl;
    }

    ProductionWorker(){
        shift=0;
        payRate=0;
    }

    ProductionWorker(int s){
        shift=s;
        payRate=0;
    }

    ProductionWorker(int s, double p){
        shift=s;
        payRate=p;
    }
};

int main()
{
    ProductionWorker e[2];
    for (int i=0; i<3; i++)
    {
        cout<< "Employee "<<+i<<":"<<endl;
        e[i].input();
    }

    for (int i=0; i<3; i++)
    {
        e[i].display();
    }
}