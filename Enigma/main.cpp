#include <iostream>
#include "Rotor.h"
using namespace std;
const int Right = 1;
const int Left = 2;

int main()
{
	int NoLetters;
	int NoRotors;
	int NoReflectors;
	int NoNotches;
	int Notch;
	int Letter;
	int NoTasks;
	int usingRotors;
	int rotate;
	int Reflector;
	bool didFirstSpin = false;
	bool canThirdSpin = false;

	scanf_s("%i", &NoLetters);
	scanf_s("%d", &NoRotors);

	Rotor* Rotors = new Rotor[NoRotors];
	for (int i = 0; i < NoRotors; i++)
	{
		int* tab = new int[NoLetters];
		for (int j = 0; j < NoLetters; j++)
		{
			cin >> tab[j];
		}

		Rotors[i].setRotor(tab, NoLetters);
		delete[] tab;
		scanf_s("%d", &NoNotches);
		if (NoNotches > 0)
		{
			for (int j = 0; j < NoNotches; j++)
			{
				scanf_s("%d", &Notch);
				Rotors[i].setNotch(Notch);
			}
		}
	}

	scanf_s("%i", &NoReflectors);
	Rotor* Reflectors = new Rotor[NoReflectors];
	for (int i = 0; i < NoReflectors; i++)
	{
		int* tab = new int[NoLetters];
		for (int j = 0; j < NoLetters; j++)
		{
			cin >> tab[j];
		}
		Reflectors[i].setRotor(tab, NoLetters);
		delete[] tab;
	}
	scanf_s("%i", &NoTasks);
	for (int i = 0; i < NoTasks; i++)
	{
		scanf_s("%i", &usingRotors);
		Rotor* Rot = new Rotor[usingRotors];
		for (int j = 0; j < usingRotors; j++)
		{
			int x;
			cin >> x;
			Rot[j].copyRotorData(Rotors[x]);
			scanf_s("%d", &rotate);
			for (int k = 0; k < rotate - 1; k++)
			{
				Rot[j].spin();
			}
			Rot[j].setRotNum(rotate-1);
		}
		scanf_s("%d", &Reflector);

		while ((scanf_s("%d", &Letter)))
		{
			if (Letter == 0)
			{
				for (int j = 0; j < usingRotors; j++)
				{
					didFirstSpin = false;
					canThirdSpin = false;
					Rot[j].reset();
				}
				cout << endl;
				break;
			}
			Rot[0].spin();
			if (didFirstSpin)
			{
				if (usingRotors >= 2)
				{
					if (usingRotors >= 3 && canThirdSpin)
					{
						Rot[2].spin();
						Rot[1].spin();
						if (Rot[1].isOnNotch(1))
						{
							canThirdSpin = true;
						}
						else
						{
							canThirdSpin = false;
						}
					}
					if (Rot[0].isOnNotch(0))
					{
						Rot[1].spin();
						if (Rot[1].isOnNotch(1))
						{
							canThirdSpin = true;
						}
					}
					
				}
			}
			didFirstSpin = true;
			for (int j = 0; j < usingRotors; j++)
			{
				Letter = Rot[j].cipher(Letter, Right);
			}
			Letter = Reflectors[Reflector].reflect(Letter);
			for (int j = usingRotors - 1; j >= 0; j--)
			{
				Letter = Rot[j].cipher(Letter, Left);
			}
			printf("%d ", Letter);
		}
		delete[] Rot;

	}
		delete[] Rotors;
		delete[] Reflectors;
		return 0;
}