#pragma once
#include "Creature.h"

Creature::Creature() {
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
	if (h < 1) {
		h = 1;
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


