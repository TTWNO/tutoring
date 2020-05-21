#pragma once
#include <iostream>
#include <string.h>

class Person
{
private:
    std::string fullName;
    int age;
public:
    std::string getFullName();
    int getAge();
    void setFullName(std::string);
    void setAge(int);
    Person();
};