#pragma once

#include <array>
#include <iostream>
#include <string>
#include <conio.h>

using namespace::std;




class Creature {

private:
	int Damage;
	int Defense;
	int Speed;
	int Stamina;
	int Strength;

	int MaxHealth;
	int Health;
	int Level;
	int XP;
	string Name;

	//x,y position
	array<int, 2> position; 

public:
	Creature();

	int getDamage();
	void setDamage(int i);
	int getDefense();
	void setDefense(int d);
	int getSpeed();
	void setSpeed(int s);
	int getStamina();
	void setStamina(int s);
	int getStrength();
	void setStrength(int s);

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

	array<int, 2> getPosition();
	bool setPosition(array<int,2> pos);

	int move(char map[][10], int direction);





};


