#include "Card.h"


Card::Card()
{
	figure = '0';
	color = '0';
	power = 0;
	this->nextCard = nullptr;
}
Card::Card(char figure, char color, int power)
{
	this->figure = figure;
	this->color = color;
	this->power = power;
	this->nextCard = nullptr;
}
void Card::printCard()
{
	std::cout<< figure << " " << color;// << " " << power;
}
