#include "Hand.h"

Hand::Hand()
{
	firstCard = nullptr;
}
void Hand::addCard(Card* card)
{
	if (firstCard == nullptr)
	{
		firstCard = new Card(card->figure, card->color,  card->power);
	}

	else
	{
		Card* tmpCard = firstCard;
		while (tmpCard->nextCard != nullptr)
		{
			tmpCard = tmpCard->nextCard;
		}
		tmpCard->nextCard = new Card(card->figure, card->color, card->power);
	}

	
}
void Hand::printHand()
{
	Card* tmpCard = firstCard;
	while (tmpCard != nullptr)
	{
		tmpCard->printCard();
		std::cout << "\n";
		tmpCard = tmpCard->nextCard;
	}
}

Card* Hand::popCard()
{
	if (firstCard == nullptr)
	{
		return nullptr;
	}
	Card* tmpCard = firstCard;
	firstCard = firstCard->nextCard;
	tmpCard->nextCard = nullptr;
	return tmpCard;
}

int Hand::valueOfHand()
{
	Card* tmp = firstCard;
	int temp = tmp->power;
	while (tmp->nextCard != nullptr)
	{
		
		tmp = tmp->nextCard;
		if (tmp->power < 0)
		{
			int i = 0;
		}
		temp += tmp->power;
	}
	return  temp;
}

