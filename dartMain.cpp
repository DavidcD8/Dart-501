#include <iostream>
using namespace std;

/*David Diaz
3/1/2022
*/



class Player {

	//members
private: string name;
private: int playerScore = 501;
public:  bool bustScore = false;
private: int previousScore = playerScore; //this variable will set score back in case of a Bust.

	   //variables
	     short dart;
	     char dartType;
	     int dartDouble;
	     int dartTreble;
	     int bullsEye = 50;
	     int innerRing = 25;
		 bool winner = false;
	   //this constructor will get the names for players from the main Class.





public: Player(string playerName) {
	name = playerName;

}


	  //function responsible to throw the dart
	  char throwDart() {

		  // This ask for the type of dart			
		  cout << name + "'s score is " << playerScore << ".\n";
		  cout << " "<< endl;
		  cout << name + " Throw a dart: " + "\n" + "S: Single" + "\n" + "D: Double " + "\n" + "T: Treble " + "\n" + "B: BullsEye " + "\n" + "I: Inner Ring " + "\n" + "O: Off Board ";
		  cin >> dartType;

		  switch (dartType) {

		  case 's':

			  // this simulates a single dart
			  cout << " Enter a Number 1 to 20 ";
			  cin >> dart;
			  playerScore -= dart;

			  if (playerScore == 1 || playerScore == 0) {
				  bustScore = true;
				  playerScore = previousScore;
				  cout << "Bust ";
			  }

			  cout << " Single dart " << " your score is " << playerScore << "\n";
			  break;

		  case 'd':

			  // this simulates a Double 
			  cout << " Enter a Number 1 to 20 ";
			  cin >> dartDouble;
			  dartDouble *= 2;
			  playerScore -= dartDouble;

			  if (playerScore == 1) {
				  bustScore = true;
				  playerScore = previousScore;
				  cout << "Bust ";
			  }


			  cout << " Double dart " << " your score is  " << playerScore << "\n";
			  if (playerScore == 0) {
				  winner = true;
			  }
			  break;




		  case 't':
			  // this simulates a Treble 
			  cout << " Enter a Number 1 to 20 ";
			  cin >> dartTreble;
			  dartTreble *= 3;
			  playerScore -= dartTreble;

			  if (playerScore == 1) {
				  bustScore = true;
				  playerScore = previousScore;
				  cout << "Bust ";
			  }


			  cout << " Treble dart " << " your score is  " << playerScore << "\n";
			  break;




		  case 'b':
			  // this simulates a 50 points dart
			  previousScore = playerScore;
			  playerScore -= bullsEye;

			  if (playerScore == 1) {
				  bustScore = true;
				  playerScore = previousScore;
				  cout << (" Bust ");
			  }

			  if (playerScore == 0) {
				  winner = true;
				  cout << name << " your score is " << playerScore << " You win!";
			  }

			  cout << " Bullseye " << " - " << bullsEye << " your score is  " << playerScore << "\n";
			  break;



		  case 'i':

			  // this simulates a 25 points dart
			  playerScore -= innerRing;
			  if (playerScore == 1) {
				  bustScore = true;
				  playerScore = previousScore;
				  cout << " Bust ";
			  }
			  cout << " innerRing " << " -" << innerRing << " your score is " << playerScore << "\n";
			  break;




			  // this simulates a 25 points dart
			  playerScore -= innerRing;

			  if (playerScore == 1) {
				  bustScore = true;
				  playerScore = previousScore;
				  cout << " Bust ";
			  }

			  cout << " innerRing " << " -" << innerRing << " your score is " << playerScore << "\n";
			  break;

			  //simulate a missed dart
		  case 'o':
			  cout << "Dart Missed " << endl;
			  break;


		  }









		  return winner;
	  }








};

int main() {
	bool winner = false;
	bool bustScore = false;

	// This object holds the name of players
	Player player1("Player 1");
	Player	player2("Player 2");




	while (!winner) {
		for (short darts = 0; darts < 3; darts++) {	 //This for loop will run 3 times for player 1
			winner = player1.throwDart();
			if (player1.bustScore == true)
				break;

			else if (winner == true)
				break;

		}

		if (!winner)
			for (short darts = 0; darts < 3; darts++) {  //This for loop will run 3 times for player 2
				winner = player2.throwDart();
				if (player2.bustScore == true)
					break;


				else if (winner == true)
					break;

			}

	}


};