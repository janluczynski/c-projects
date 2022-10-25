#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "Card.h"
#include "Hand.h"
#include "Deck.h"
#define DECKSIZE 52
#define NOFCOLORS 4
using namespace std;

void gra(Hand* firstplayersHand, Hand* secondplayersHand, int* p1w, int* p2w, char wariant);

int walka(Card* firstplayersCard, Card* secondplayersCard);

void wojna(Hand* firstplayersHand, Hand* secondplayersHand, Card* gracz1, Card* gracz2, Deck* p1Storage,Deck* p2Storage, int stosP1, int stosP2, char wariant );

int main()
{
	srand(time(NULL));
	
	int p1w = 0, p2w = 0;
	int val = 0, val2 = 0;
	int ruchy = 0;
    cout << "Ile figur liczac od dolu chcesz usunac?" << endl;

	int  pomniejszenieTalii;
	cin >> pomniejszenieTalii;

	char wariant;

	cout << "Ktory wariant gry chcesz przyjąc?" << endl;
	cout << "A: graczowi ktoremu skoncza sie karty przegrywa." << endl;
	cout << "B: graczowi ktoremu skoncza sie karty podczas wojny, drugi gracz doklada karty." << endl;

	cin >> wariant;



		
	for (int i = 0; i < 1; i++) /*ilosc gier*/
	{

		
		Deck* mainDeck = new Deck(false, pomniejszenieTalii);
		Hand* firstplayersHand = new Hand();
		Hand* secondplayersHand = new Hand();
		//cout << endl << endl;
		for (int i = 0; i < (DECKSIZE / 2) - (pomniejszenieTalii * 2); i++)
		{

			firstplayersHand->addCard(mainDeck->popCard());
			secondplayersHand->addCard(mainDeck->popCard());

		}
		cout << "Talia gracza pierwszego:" << endl;
		firstplayersHand->printHand();
		cout << "Talia gracza drugiego:" << endl;
		secondplayersHand->printHand();
		cout << firstplayersHand->valueOfHand() << endl;
		cout << secondplayersHand->valueOfHand() << endl << endl;
		if (firstplayersHand->valueOfHand() > secondplayersHand->valueOfHand())
		{
			val++;
		}
		else if (firstplayersHand->valueOfHand() < secondplayersHand->valueOfHand())
		{
			val2++;
		}
		
		gra(firstplayersHand, secondplayersHand, &p1w, &p2w, wariant);
		//cout << "KONIEC!";
		delete mainDeck;
		delete firstplayersHand;
		delete secondplayersHand;

		
	}
	cout << p1w << " " << p2w << endl;
	cout << val << " " << val2 << endl;
	return 0;
}
void gra(Hand* firstplayersHand, Hand* secondplayersHand, int* p1w, int* p2w, char wariant)
{
	

	Card* gracz1 = firstplayersHand->popCard();
	Card* gracz2 = secondplayersHand->popCard();
	while (gracz1!=nullptr && gracz2!=nullptr)
	{

		if (walka(gracz1, gracz2) == 0)
		{
			
			//cout << endl << endl << "Wygral gracz pierwszy" << endl;
			//gracz1->printCard(); cout << "||"; gracz2->printCard();
			firstplayersHand->addCard(gracz1);
			firstplayersHand->addCard(gracz2);
		}
		else if (walka(gracz1, gracz2) == 1)
		{
			
			//cout << endl<< endl << "Wygral gracz drugi" << endl;
			//gracz1->printCard(); cout << "||"; gracz2->printCard();
			secondplayersHand->addCard(gracz2);
			secondplayersHand->addCard(gracz1);
		}
		else if(walka(gracz1, gracz2)==2) /*wojna*/
		{
			
			//cout << endl<<endl << "Wojna!" << endl;
			//gracz1->printCard(); cout << "||"; gracz2->printCard();
			Deck* tempdeck = new Deck(true,0);
			Deck* tempdeck2 = new Deck(true,0);
			int stos1 = 0;
			int stos2 = 0;
			wojna(firstplayersHand, secondplayersHand, gracz1, gracz2, tempdeck, tempdeck2, stos1,stos2, wariant);
			



		}
		

		 gracz1 = firstplayersHand->popCard();
		 gracz2 = secondplayersHand->popCard();
	}
		
	if (gracz1 == nullptr)
	{
		//cout << endl << "Gracz drugi wygral gre!" << endl;
		(*p2w)++;
		
	}
	else if(gracz2==nullptr)
	{
		//cout << endl << "Gracz pierwszy wygral gre!" << endl;
		(*p1w)++;
		
	}

	return;
}

int walka(Card* firstplayersCard, Card* secondplayersCard)
{
	if (firstplayersCard->power > secondplayersCard->power)
	{
		return 0;
	}
	if (firstplayersCard->power < secondplayersCard->power)
	{
		return 1;
	}
	if (firstplayersCard->power == secondplayersCard->power)
	{
	return 2;
	}

}
void wojna(Hand* firstplayersHand, Hand* secondplayersHand, Card*gracz1, Card*gracz2, Deck* p1Storage, Deck* p2Storage, int stosP1, int stosP2, char wariant)
{
	
	if (gracz1 == nullptr || gracz2 == nullptr)
		return;
	if (wariant == 'a' || wariant == 'A')
	{
		stosP1++;
		stosP2++;
		p1Storage->addCard(gracz1->figure, gracz1->color, gracz1->power);
		p2Storage->addCard(gracz2->figure, gracz2->color, gracz2->power);
		gracz1 = firstplayersHand->popCard(); //zakryte
		gracz2 = secondplayersHand->popCard();//karty
		if (gracz1 == nullptr || gracz2 == nullptr)
			return;
		stosP1++;
		stosP2++;
		p1Storage->addCard(gracz1->figure, gracz1->color, gracz1->power);
		p2Storage->addCard(gracz2->figure, gracz2->color, gracz2->power);
		gracz1 = firstplayersHand->popCard(); //odkryte
		gracz2 = secondplayersHand->popCard();//karty
		if (gracz1 == nullptr || gracz2 == nullptr)
			return;
		stosP1++;
		stosP2++;
		p1Storage->addCard(gracz1->figure, gracz1->color, gracz1->power);
		p2Storage->addCard(gracz2->figure, gracz2->color, gracz2->power);
	}
	
	if (wariant == 'b' || wariant == 'B')
	{
		p1Storage->addCard(gracz1->figure, gracz1->color, gracz1->power);
		p2Storage->addCard(gracz2->figure, gracz2->color, gracz2->power);
		if (gracz1->nextCard == nullptr) //Pierwszy gracz zaczyna wojne z jedna karta
		{
			gracz1 = secondplayersHand->popCard();
			if (gracz1 == nullptr)
				return;
			p1Storage->addCard(gracz1->figure, gracz1->color, gracz1->power);
			stosP1++;
			gracz1 = secondplayersHand->popCard();
			if (gracz1 == nullptr || gracz2 == nullptr)
				return;
			p1Storage->addCard(gracz1->figure, gracz1->color, gracz1->power);
			stosP1++;
			gracz2 = secondplayersHand->popCard();
			if (gracz1 == nullptr || gracz2 == nullptr)
				return;
			p2Storage->addCard(gracz2->figure, gracz2->color, gracz2->power);
			stosP2++;
			gracz2 = secondplayersHand->popCard();
			if (gracz1 == nullptr || gracz2 == nullptr)
				return;
			p2Storage->addCard(gracz2->figure, gracz2->color, gracz2->power);
			stosP2++;

		}
		else if (gracz2->nextCard == nullptr) //Drugi gracz zaczyna wojne z jedna karta
		{
			gracz2 = firstplayersHand->popCard();
			if (gracz1 == nullptr || gracz2 == nullptr)
				return;
			p2Storage->addCard(gracz2->figure, gracz2->color, gracz2->power);
			stosP2++;
			gracz2 = firstplayersHand->popCard();
			if (gracz1 == nullptr || gracz2 == nullptr)
				return;
			p2Storage->addCard(gracz2->figure, gracz2->color, gracz2->power);
			stosP2++;
			gracz1 = firstplayersHand->popCard();
			if (gracz1 == nullptr || gracz2 == nullptr)
				return;
			p1Storage->addCard(gracz1->figure, gracz1->color, gracz1->power);
			stosP1++;
			gracz1 = firstplayersHand->popCard();
			if (gracz1 == nullptr || gracz2 == nullptr)
				return;
			p1Storage->addCard(gracz1->figure, gracz1->color, gracz1->power);
			stosP1++;
		}
		else
		{
			gracz1 = firstplayersHand->popCard(); //zakrtye
			gracz2 = secondplayersHand->popCard();//karty
			p1Storage->addCard(gracz1->figure, gracz1->color, gracz1->power);
			stosP1++;
			p2Storage->addCard(gracz2->figure, gracz2->color, gracz2->power);
			stosP2++;
			if (gracz1->nextCard == nullptr)
			{
				gracz1 = secondplayersHand->popCard();
				if (gracz1 == nullptr || gracz2 == nullptr)
					return;
				p1Storage->addCard(gracz1->figure, gracz1->color, gracz1->power);
				stosP1++;
				
				gracz2 = secondplayersHand->popCard();
				if (gracz1 == nullptr || gracz2 == nullptr)
					return;
				p2Storage->addCard(gracz2->figure, gracz2->color, gracz2->power);

			}
			else if (gracz2->nextCard == nullptr)
			{
				gracz2 = firstplayersHand->popCard();
				if (gracz1 == nullptr || gracz2 == nullptr)
					return;
				p2Storage->addCard(gracz2->figure, gracz2->color, gracz2->power);
				stosP2++;

				gracz1 = firstplayersHand->popCard();
				if (gracz1 == nullptr || gracz2 == nullptr)
					return;
				p1Storage->addCard(gracz1->figure, gracz1->color, gracz1->power);
			}
		}
	}
	
	
		//cout << endl << "O O||O O" << endl; // wizualizacja zakrytych kart
		//gracz1->printCard(); cout << "||"; gracz2->printCard();
		
		if (walka(gracz1, gracz2) == 0)
		{		
			
			//cout << endl << "Wojne wygral gracz pierwszy";
			for (int i = 0; i < stosP1; i++)
			{
				firstplayersHand->addCard(p1Storage->popCard());
			}
			for (int i = 0; i < stosP2; i++)
			{
				firstplayersHand->addCard(p2Storage->popCard());
			}
			return;
		}
		else if (walka(gracz1, gracz2) == 1)
		{	
			//cout << endl << "Wojne wygral gracz drugi";
			for (int i = 0; i < stosP2; i++)
			{
				secondplayersHand->addCard(p2Storage->popCard());
			}
			for (int i = 0; i < stosP1; i++)
			{
				secondplayersHand->addCard(p1Storage->popCard());
			}				
			return;
		}
		else
		{
			wojna(firstplayersHand, secondplayersHand, gracz1, gracz2, p1Storage, p2Storage, stosP1,stosP2, wariant);
			
		}
	
}