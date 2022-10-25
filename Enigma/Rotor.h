#pragma once
#include <iostream>
using namespace std;
class Rotor
{
public:
	Rotor() {};
	void copyRotorData(Rotor& rotor);
	void setRotor(int *tab, int size);
	void spin();
	void setNotch(int n);
	~Rotor();
	int cipher(int x, int direction);
	int reflect(int n);
	void reset();
	bool isOnNotch(int addPos);
	void setRotNum(int x);
	int Size;
	int* values;
	int* notchPos;
private:
	int *connection;
	int* reverseConnection;
	int Rotations;
};

