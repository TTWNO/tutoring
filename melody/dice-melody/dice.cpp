#include <ctime>
#include <iostream>
using namespace std;
class Game {
  int bet;
  int money;
  int numDice;
  int role;

public:
  int getBet() { return bet; }

  int getMoney() { return money; }

  int getNumDice() { return numDice; }

  int getRole() {
    int role = (rand() % (6 - 1 + 1)) + 1;
    return role;
  }

  void setBet(int b) { bet = b; }

  void setMoney(int m) { money = m; }

  void setNumDice(int n) { numDice = n; }

  void inputStart() {
    cout << "money?" << endl;
    cin >> money;
    if (money <= 0)
      inputStart();
    cout << "how many dice" << endl;
    cin >> numDice;
    while (numDice < 1) {
      cout << "how many dice" << endl;
      cin >> numDice;
    }
  }

  void inputBet() {
    cout << "how much bet you rich ass?" << endl;
    cin >> bet;
    if (bet < 0 || bet > money)
      inputBet();
  }

  Game() {
    bet = 0;
    money = 0;
    numDice = 0;
    role = 0;
    unsigned int seed = time(0);
    srand(seed);
  }

  Game(int b, int m, int n, int r) {
    bet = b;
    money = m;
    numDice = n;
    role = r;
    unsigned int seed = time(0);
    srand(seed);
  }
};

int main() {
  int total = 0;
  Game p;
  cout << "Wellcome to the boring dice game!" << endl << "Let's play!" << endl;
  p.inputStart();
  while (p.getMoney() > 0) {
    p.inputBet();
    for (int i = 0; i < p.getNumDice(); i++) {
      cout << p.getRole() << " " << endl;
      total += p.getRole();
    }
    cout << "total=" << total;
    if (total > p.getNumDice() * 3)
      p.setMoney(p.getMoney() + p.getBet());
    else
      p.setMoney(p.getMoney() - p.getBet());
    total = 0;
    cout << "money left: " << p.getMoney();
  }
  return 0;
}
