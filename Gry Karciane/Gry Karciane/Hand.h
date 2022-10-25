#pragma once
#include "Card.h"
class Hand
{
private:
	Card* firstCard;

	
public:
	Hand();
	//secondHand();
	void addCard(Card* card);
	void printHand();
	Card* popCard();
	int valueOfHand();
};

