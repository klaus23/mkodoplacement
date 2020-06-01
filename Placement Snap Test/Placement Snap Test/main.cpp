#include <iostream>
#include "Deck.h"
#include "Player.h"
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;
int main()
{
	
	Deck mainDeck; //creating main deck vector from class deck and the vector for the cards that are being put down
	Deck cardsDown;
	mainDeck.build();
	bool won = false;


	Player player1("Bob");
	Player player2("Jim");

	while (!won && !mainDeck.cardsVector.empty()) { //game continues until all cards are dealt
		cardsDown.cardsVector.push_back(mainDeck.deal(mainDeck));
		string preLastCard = cardsDown.cardsVector.back();     //card drawn by player1
		cout << player1.name << " has drawn " << preLastCard << endl;

		sleep_for(nanoseconds(1000000));
		sleep_until(system_clock::now() + seconds(1)); //gives real time feeling of waiting time for each of them to reveal their card
		cardsDown.cardsVector.push_back(mainDeck.deal(mainDeck));
		string lastCard = cardsDown.cardsVector.back(); //card drawn by player2
		cout << player2.name << " has drawn " << lastCard << endl;
		sleep_for(nanoseconds(1000000));
		sleep_until(system_clock::now() + seconds(1));
		if (mainDeck.cardsVector.empty())
		{
			std::cout << " Draw! " << std::endl; //if all cards are dealt then it's a draw i.e. vector is empty

		}
		if (preLastCard.substr(0, preLastCard.size() - 1) == lastCard.substr(0, lastCard.size() - 1)) {//card drawn by player1(penultimate card) equals last card drawn by player2
			won = true;
			int randomNum = rand() % 100 + 1; //50 50 random that if its below 50 player1 will win and if the number drawn is over 50 player2 will win 
			if (randomNum < 50) {
				std::cout <<"Snap! " << player1.name << " has won!" << std::endl;

			}
			else {
				std::cout <<"Snap! "<< player2.name << " has won!" << std::endl;
			}

		}
	
	}//i would normally put this in a funciton in deck.cpp but with this deck test it functions better and i will just fill the private variables
	//overall i think when you press f5 the game itself should be in turns of each  other drawing and then pauses and i don't know how to implement that with hardcode	
	


	return 0;
}