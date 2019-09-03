#include "Creature.h"

Creature::Creature() {
	this->Health = 1;
	this->Level = 1;
	this->XP = 0;
	this->Name;


}

int Creature::getHealth() {
	return this->Health;
}
void Creature::setHealth(int h) {
	this->Health = h;
}

int Creature::getLevel() {
	return this->Level;
}

void Creature::setLevel(int l) {
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


