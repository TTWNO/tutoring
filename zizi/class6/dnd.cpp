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
	return to_string(r);
}

int main() {
	/*	Remember to ask the user for a seed value. If
		the seed value is 0, use time(). If the value 
		is not 0, use IT as the seed.

		If you use cin to get the seed value, remember
		to use cin.ignore() before using getline(). See
		the README.md.

		All your code goes below. Remember that your
		program is supposed to ask for character names
		over and over until the user enters 'quit'.
	*/


	/*	All your code comes before this.
	*/
	return 0;
}
