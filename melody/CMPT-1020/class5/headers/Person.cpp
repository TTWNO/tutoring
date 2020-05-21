#include "Person.h"

std::string Person::getFullName(){
    return fullName;
}
int Person::getAge(){
    return age;
}

void Person::setFullName(std::string a){
    fullName = a;
}
void Person::setAge(int a){
    age = a;
}

Person::Person(){
    fullName = "A B";
    age = 20;
}