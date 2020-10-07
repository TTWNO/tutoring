/*	Yanozie Amadike
	DND Character Generator
*/

#include <vector>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;


/*	These are global variables. While not
	terrific style, global variables make
	development of some programs easier.

	The functions you write:

	string ChooseRace();
	string ChooseAlignment();
	string ChooseBehavior();	

	must initialize these vectors appropriately
	and just once.
*/

vector<string> races = {"Human", "Orc", "Elf", "Dwarf", "Professor"};
vector<string> behaviors = {"Good", "Neutral", "Evil"};
vector<string> alignments = {"Lawful", "Neutral", "Chaotic"};

/*	You must write these. The should notice when the
	appropriate vector is empty and if so, should initialize
	the data in the vector using .push_back().
*/

string ChooseRace() {
	int r = rand() % races.size();
	return races[r];
}

string ChooseAlignment() {
	int r = rand() % alignments.size();
	return alignments[r];
}

string ChooseBehavior() {
	int r = rand() % behaviors.size();
	return behaviors[r];
}

/*	You must write these too.
*/

int RangeRand(int min, int max) {
	int s = rand() + min;
	s = s % max;
	return s;
} 

string PickStat() {
	// to_string(123); // "123"

	int r = RangeRand(6, 18); // bynver vetweeb 19 abd 29 ubckysive
	int i;
	string stat = to_string(r);
	if (r == 18)
	{
		i = RangeRand(0, 100);
		stat += " / " + to_string(i);
	}
	return stat;
}

int main() {
	string name;

	while(name != "quit") {

		cout << "Enter character's name - use \"quit\" to exit: " << endl;
		cin >> name;

		cout << name

	}
	return 0;
}
/*	enter name of character
	cin >> name
	while character != quit
	cout << name << "(" << ChooseRace<< ")" << "is " ChooseAlignment << "and " << ChooseBehavior
	cout << "Health: " << RangeRand << endl;
	cout << "Strength: " << PickStat << endl;
	cout << "Dexterity: " << PickStat << endl;
	cout << "Intelligence: " << PickStat << endl;
	cout << "Charisma: " << Pickstat << endl;
	cout "Wisdom: " << PickStat << endl;
	*/

	/*	All your code comes before this.
	*/