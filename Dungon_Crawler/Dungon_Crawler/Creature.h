#pragma once


#include <iostream>
#include <string>

using namespace::std;




class Creature {

private:
	int MaxHealth;
	int Health;
	int Level;
	int XP;
	string Name;

public:
	Creature();
	int getMaxHealth();
	void setMaxHealth(int m);
	int getHealth();
	void setHealth(int h);
	int getLevel();
	void setLevel(int l);
	int getXP();
	void setXP(int x);
	string getName();
	void setName(string n);
	void Display();



};


