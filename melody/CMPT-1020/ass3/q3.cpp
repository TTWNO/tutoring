#include <iostream>
using namespace std;

class Date {
  int month;
  int date;
  int year;

public:
  const string mth[12] = {"January",   "February", "March",    "April",
                          "May",       "June",     "July",     "August",
                          "September", "October",  "November", "December"};
  int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  int getMonth() { return month; }

  int getDate() { return date; }

  int getYear() { return year; }

  void setMonth(int m) { month = m; }

  void setDate(int d) { date = d; }

  void setYear(int y) { year = y; }

  void input() {
    month = 0;
    cout << "month?" << endl;
    while (month < 1 || month > 12)
      cin >> month;

    cout << "date?" << endl;
    cin >> date;
    if (date < 1 || date > days[month - 1]) {
      cout << "date does not exist" << endl;
      input();
    }

    cout << "year" << endl;
    cin >> year;
  }

  void output1() { cout << month << "/" << date << "/" << year << endl; }

  void output2() { cout << mth[month - 1] << " " << date << ", " << year<<endl; }

  void output3() { cout << date << " " << mth[month - 1] << " " << year<<endl; }

  void increment() {
    Date tmr(month, date, year);
    if (tmr.getYear() % 4 == 0)
      tmr.days[1] = 29;
    tmr.setDate(tmr.getDate() + 1);
    if (tmr.getDate() > days[month]) {
      tmr.setDate(1);
      tmr.setMonth(month + 1);
    }
    if (tmr.getMonth() > 12) {
      tmr.setMonth(1);
      tmr.setYear(getYear() + 1);
    }
cout<< "tomorrow: ";
tmr.output1();
  }

  void decrement() {
    Date yes(month, date, year);
    if (yes.getYear() % 4 == 0)
      yes.days[1] = 29;
    yes.setDate(yes.getDate() - 1);
    if (yes.getDate() <1) {
      yes.setMonth(month - 1);
    }
    if (yes.getMonth() < 1) {
      yes.setMonth(12);
      yes.setYear(getYear() - 1);
    }
    yes.setDate(days[yes.getMonth() - 1]);
  cout<< "yesterday: ";
  yes.output1();
  }

  Date() {
    month = 1;
    date = 1;
    year = 2000;
  }

  Date(int m, int d, int y) {
    month = m;
    date = d;
    year = y;
  }
};

int main() {
  int a;
  Date today;
cout<< "What's the date?"<<endl;
  today.input();
  today.output1();
  today.output2();
    today.output3();
today.increment();
today.decrement();
  cin >> a;
  return 0;
}
