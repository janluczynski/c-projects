#include "Rotor.h"

void Rotor::setRotor(int *tab, int size)
{
	this->Size = size;
	this->connection = new int[Size];
	this->reverseConnection = new int[Size];
	this->values = new int[Size];
	this->notchPos = new int[Size];
	this->Rotations = 0;
	int temp = 0;
	for (int i = 0; i < Size; i++)
	{
		temp = 0;
		values[i] = tab[i];
		for (int j = 0; j < Size; j++)
		{
			if (tab[j] == i + 1)
			{
				temp = j;
				break;
			}
		}
		reverseConnection[i] = i - temp;
		connection[i - reverseConnection[i]] = -reverseConnection[i];
	}
}
void Rotor::reset()
{
	for (int i = 0; i < Size; i++)
	{
		int temp = 0;
		for (int j = 0; j < Size; j++)
		{
			if (values[j] == i + 1)
			{
				temp = j;
				break;
			}
		}
		reverseConnection[i] = i - temp;
		connection[i - reverseConnection[i]] = -reverseConnection[i];
	}
	Rotations = 0;
}
void Rotor::spin()
{
	Rotations++;
	int temp = connection[0];
	int temp2 = reverseConnection[0];
	for (int i = 0; i < Size-1; i++)
	{
		connection[i] = connection[i + 1];
		reverseConnection[i] = reverseConnection[i + 1];
	}
	connection[Size-1] = temp;
	reverseConnection[Size - 1] = temp2;
}
void Rotor::setNotch(int n)
{
	notchPos[n-1] = 1;
}
bool Rotor::isOnNotch(int addPos)
{
	return notchPos[((Rotations +addPos) % Size)] == 1 ? true : false;
}
void Rotor::setRotNum(int x)
{
	Rotations = x;
}
int Rotor::cipher(int x, int direction)
{
	switch(direction)
	{
	case 1:
		if (x - connection[x - 1] <= 0)
		{
			x = x - connection[x - 1] + Size;
		}
		else if (x - connection[x - 1] > Size)
		{
			x = x - connection[x - 1] - Size;
		}
		else
		x -= connection[x-1];
		break;
	case 2:
		if (x - reverseConnection[x - 1] <= 0)
		{
			x = x- reverseConnection[x - 1] + Size;
		}
		else if (x - reverseConnection[x - 1] > Size)
		{
			x = x- reverseConnection[x - 1] - Size;
		}
		else
		x -= reverseConnection[x - 1];
		break;
	}
	return x;
}
int Rotor::reflect(int n)
{
	return values[n-1];
}

void Rotor::copyRotorData(Rotor& rotor)
{
	setRotor(rotor.values, rotor.Size);
	for (int i = 0; i < Size; i++)
	{
		this->notchPos[i] = rotor.notchPos[i];
	}
}

Rotor::~Rotor()
{
	delete connection;
	delete values;
	delete reverseConnection;
}