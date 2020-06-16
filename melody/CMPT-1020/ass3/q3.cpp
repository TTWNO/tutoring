#include <iostream>
using namespace std;

class Date {
  int month;
  int date;
  int year;
public:
  const string mth[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  const int days[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  int getMonth(){
    return month;
  }

  int getDate(){  
    return date;
  }

  int getYear(){
    return year;
  }

  void setMonth(int m){
    month=m;
  }

  void setDate(int d){
    date=d;
  }

  void setYear(int y){
    year=y;
  }

  void input(){
    month=0;
    cout<< "month?"<<endl;
    while (month<1 || month>12)
      cin>> month;

    cout<< "date?"<<endl;
    cin>> date;
    if (date<1 || date>days[month-1]){
      cout<< "date does not exist"<<endl;
      input();
    }

    cout<< "year"<<endl;
    cin>> year;
  }

  void output1(){
    cout<< month<<"/"<<date<<"/"<<year<<endl;
  }

  void output2(){
    cout<< mth[month-1]<<" "<<date<<", "<<year;
  }

  void output3(){
    cout<< date<< " "<<mth[month-1]<<" "<<year;
  }

  Date(){
    month=1;
    date=1;
    year=2000;
  }

  Date(int m, int d, int y){
    month=m;
    date=d;
    year=y;
  }

};

int main(){
  int a;
  Date today;
  today.input();
  today.output1();
  cin >> a;
  return 0;
}
