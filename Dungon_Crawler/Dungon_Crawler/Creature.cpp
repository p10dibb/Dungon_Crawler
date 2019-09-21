#pragma once

#include "Creature.h"

Creature::Creature() {
	//sets x=1
	this->position[0] = 1;
	//sets y=1
	this->position[1] = 1;

	this->Damage = 0;
	this->Speed = 0;
	this->Defense = 0;
	this->Stamina = 0;

	this->MaxHealth = 100;
	this->Health = 100;
	this->Level = 1;
	this->XP = 0;
	this->Name;


}
int Creature::getMaxHealth() {
	return this->MaxHealth;
}
void Creature::setMaxHealth(int m) {
	if (m < 1) {
		m = 0;
	}
	this->MaxHealth = m;
}


int Creature::getHealth() {
	return this->Health;
}
void Creature::setHealth(int h) {
	if (h < 0) {
		h = 0;
	}
	this->Health = h;
}

int Creature::getLevel() {
	return this->Level;
}

void Creature::setLevel(int l) {
	if (l < 1) {
		l = 1;
	}
	this->Level = l;
}


int Creature::getXP() {
	return this->XP;
}
void Creature::setXP(int x) {
	this->XP = x;
}
string Creature::getName() {
	return this->Name;
}
void  Creature::setName(string n) {
	this->Name = n;
}

void Creature::Display() {
	cout << "Name: \t" << this->Name << endl << "Level: \t" << Level << endl << "XP: \t" << this->XP << endl << "Health: \t" << this->Health << endl << "MaxHealth: \t" << this->MaxHealth << endl;

}


int Creature::getDamage() {
	return this->Damage;
}
void Creature::setDamage(int i) {
	if (i < 1) {
		i = 1;
	}
	this->Damage = i;
}
int Creature::getSpeed() {
	return this->Speed;
}
void  Creature::setSpeed(int s) {
	if (s < 1) {
		s = 1;
	}
	this->Speed = s;
}
int  Creature::getStamina() {
	return this->Stamina;
}
void  Creature::setStamina(int s) {

	if (s < 1) {
		s = 1;
	}
	this->Stamina = s;
}

int  Creature::getDefense() {
	return this->Defense;
}
void  Creature::setDefense(int d) {
	if (d < 0) {
		this->Defense = d;
	}
}


int  Creature::getStrength() {
	return this->Strength;
}
void  Creature::setStrength(int s) {
	this->Strength = s;
}



array<int, 2> Creature::getPosition() {
	return this->position;
}
bool Creature::setPosition(array<int, 2> pos) {
	this->position = pos;
	return true;
}
//0=left,1=up,2=right, 3=down
int Creature::move(char  map[][10],int direction) {
	
	return 0;

}