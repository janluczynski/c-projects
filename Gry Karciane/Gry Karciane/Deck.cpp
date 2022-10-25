#include "Deck.h"
using namespace std;



Deck::Deck(bool isWar, int wariant)
{
	if(!isWar)
		shuffleDeck(wariant);
	else
	{

	}
}

void Deck::addCard(char figure, char color, int power)
{
	
	if (firstCard == nullptr)
	{
		firstCard = new Card(figure, color, power);
		
	}
	else if (lastCard == nullptr)
	{
		lastCard = new Card(figure, color, power);
		firstCard->nextCard = lastCard;
	}
	else
	{
		Card* temp = new Card(figure, color, power);
		
		lastCard->nextCard = temp;
		temp = lastCard;
		lastCard = lastCard->nextCard;
	}
	
}

void Deck::printDeck()
{
	Card* temp = firstCard;
	while(temp != nullptr)
	{
		
		temp->printCard();
		
		temp = temp->nextCard;
	}
}

void Deck::shuffleDeck(int wariant)
{
	int temp, licznik = 0;
	
	int taken[52] = {};
	while (licznik != 52-(wariant*4))
	{
		temp = rand() % (52-(wariant*4));
		temp += wariant * 4;
		if (taken[temp] == 0)
		{
			
			licznik++;
			taken[temp] = 1;
			addCard(figures[temp/4], colors[temp%4], power[temp/4]);
			
		}
	}
}

Card* Deck::popCard()
{
	if (firstCard == nullptr)
	{
		return nullptr;
	}
	Card* tmpCard = firstCard;
	firstCard = firstCard->nextCard;

	return tmpCard;
}