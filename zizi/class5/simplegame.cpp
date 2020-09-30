/*	cout << "Enter seed (0 uses the time of day): ";
	cin >> seed;
	if (seed) {
		srand(seed);
	} else {
		srand(unsigned(time(nullptr)));
	}

    generate random number between 1 and 100 that user has to guess and store it somewhere.

    ask user to enter their guess. if guess is higher thatn random number generated, say "lower".
    if user guess is lower than random number generated, say "higher".and
    this continues as long as user guess does not equal random number generated
 
	rand = generate ranodm number
	while (user not guessed corecty)
		get input
		if less than rand:
			
 
 */
#include <iostream>
#include <ctime>

using namespace std;

int main() {
	// More goes here.
	unsigned seed;
	int counter = 0;
	int guess = 0;
	int randomnum;

	cout << "Enter seed (0 uses the time of day): ";
	cin >> seed;
	if (seed) {
		srand(seed);
	} else {
		srand(unsigned(time(nullptr)));
	}

	randomnum = (rand() % 99) + 1;

	while (guess != randomnum) {
	  cout << "Please enter your guess: " << endl;
	  cin >> guess;
	  counter++;

        if (guess < randomnum) {
            cout << "Higher" << endl;
        } else if  (guess > randomnum) {
            cout << "Lower" << endl;
        } else { 
			cout << "Correct! You needed " << counter << " tries to get it!";

        } // end if 
	} // end while
} // end main
