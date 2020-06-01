#include "Deck.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h> 
#include <ctime>
#include "Player.h"

using namespace std;

Deck::Deck()
{
}

std::vector<std::string>Deck::build()
{
	

	for (int i = 2; i <= 14; i++)
	{
		for (int y = 1; y <= 4; y++)
		{
			switch (y) {
			case 1:
				type = "C";
				break;
			case 2:
				type = "S";
				break;
			case 3:
				type = "H";
				break;
			case 4:
				type = "D";
				break;
			}
			switch (i) {
			case 11:
				card = "A";
				cardsVector.push_back(card + type);
				break;
			case 12:
				card = "J";
				cardsVector.push_back(card + type);
				break;
			case 13:
				card = "Q";
				cardsVector.push_back(card + type);
				break;
			case 14:
				card = "K";
				cardsVector.push_back(card + type);
				break;
			default:
				card = std::to_string(i);
				cardsVector.push_back(card + type);
				break;
			}
		}
	}
	return cardsVector;



}

string Deck::deal( Deck &deck)
{
	srand(time(NULL));
	std::string card = "";
	int choose =  rand() % deck.cardsVector.size(); //deals a random card from the vector/deck
	card = deck.cardsVector[choose];
	deck.cardsVector.erase(deck.cardsVector.begin() + choose); //then the card gets erased from the vector
	return card;
}

void Deck::AddCard(std::string card)
{
	Deck::cardsVector.push_back(card);
}

void Deck::SplitCards(Deck& player1, Deck& player2) {
	while (!Deck::cardsVector.empty()) { // give cards until deck is empty
		switch (turn) {
		case false:
			player1.AddCard(player1.deal(*this)); //deals half of the deck to player1
			turn = !turn;
			break;
		case true:
			player2.AddCard(player2.deal(*this)); //deals half of the deck to player2
			turn = !turn;
			break;
		}
	}
}


