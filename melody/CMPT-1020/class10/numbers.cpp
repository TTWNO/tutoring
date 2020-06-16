#include <iostream>
#include <string>
using namespace std;


double* nums(){
    double a[10];
    cout<< "10 numbers?";
    for (int i=0; i<10; i++){
        cout<< "number"<<+i<<":"<<endl;
        cin>> a[i];
    }
    return a;
}

double oneNum(){
    double n;
    cout<< "one number?"<<endl;
    cin>> n;
    return n;
}

int find(double a[], double n){

}