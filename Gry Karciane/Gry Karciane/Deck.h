#pragma once
#include "Card.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
class Deck
{
public:
	Card* firstCard;
	Card* lastCard;
	void addCard(char figure, char color, int power);
	void shuffleDeck(int wariant);
	
	const char figures[13] = { '2','3','4','5','6','7','8','9','t','j','q','k','a' };
	const char colors[4] = { 'c','h','d','s' };
	int power[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
public:
	Deck(bool isWar, int wariant);
	void printDeck();
	Card* popCard();

};

