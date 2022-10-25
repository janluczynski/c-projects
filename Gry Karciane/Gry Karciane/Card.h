#pragma once
#include <iostream>
class Card
{
public:
	char figure;
	char color;
	int power;
	Card* nextCard;
	Card();
	Card(char figure, char color, int power);
	void printCard();
	




};

