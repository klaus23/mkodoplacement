#pragma once
#include <vector>
#include <iostream>
#include "Player.h"

class Player;
class Deck
{
private:
	bool turn = false;
	std::string type;
	std::string card;
public:
	Deck();
	std::vector<std::string> cardsVector;
	std::vector<std::string> cardsDown;
	std::vector<std::string>build();
	std::string deal(Deck &cards);
	void AddCard(std::string card);
	void SplitCards(Deck& player1, Deck& player2);
};
