#include "Humanoid.h"

Humanoid::Humanoid() {
	Creature();
	this->Damage = 0;
	this->Speed = 0;
	this->Defense = 0;
	this->Stamina = 0;

	this->Head =new  Armor(0, 0, Helmet, Light);
	this->Head->setName("Hat");
	this->Torso = new Armor(0, 0, Chest, Light);
	this->Torso->setName("Shirt");
	this->Legs = new Armor(0, 0, Pants, Light);
	this->Legs->setName("Pants");
	this->Hands =new  Armor(0, 0, Gloves, Light);
	this->Hands->setName("Basic");
	this->Feet = new Armor(0, 0, Boots, Light);
	this->Feet->setName("sandals");
}

int Humanoid::getDamage() {
	return this->Damage;
}
void Humanoid::setDamage(int i) {
	if (i < 1) {
		i = 1;
	}
	this->Damage = i;
}
int Humanoid::getSpeed() {
	return this->Speed;
}
void Humanoid::setSpeed(int s) {
	if (s < 1) {
		s = 1;
	}
	this->Speed = s;
}
int Humanoid::getStamina() {
	return this->Stamina;
}
void Humanoid::setStamina(int s) {

	if (s < 1) {
		s = 1;
	}
	this->Stamina = s;
}

int Humanoid::getDefense() {
	return this->Defense;
}
void Humanoid:: setDefense(int d) {
	if (d < 0) {
		this->Defense = d;
	}
}

int Humanoid::Attack() {
	return this->getDamage();
}


int Humanoid::TakeDamage(int attack) {
	int health = this->getHealth();
	int damageTaken = 0;
	if ((attack - (this->getDefense() )) < 0) {
		health = health - 1;
		damageTaken = 1;
	}
	else {
		damageTaken = attack - (this->getDefense());
		health = health - damageTaken;
	}
	if (health < 0) {
		health = 0;
	}
	this->setHealth(health);
	return damageTaken;
}


Armor* Humanoid::getHead() {
	return this->Head;
}
int Humanoid::setHead(Armor* h) {
	if (h->getType() == Helmet && h->getLevel() <= this->getLevel()) {
		this->Head = h;
		return 1;
	}
	return 0;
}
Armor* Humanoid::getTorso() {
	return this->Torso;
}
int Humanoid::setTorso(Armor* c) {
	if (c->getType() == Chest && c->getLevel() <= this->getLevel()) {
		this->Head = c;
		return 1;
	}
	return 0;
}

Armor* Humanoid::getHands() {
	return this->Hands;
}
int Humanoid::setHands(Armor* h) {
	if (h->getType() == Gloves && h->getLevel() <= this->getLevel()) {
		this->Head = h;
		return 1;
	}
	return 0;

}
Armor* Humanoid::getLegs() {
	return this->Legs;
}
int Humanoid::setLegs(Armor* p) {
	if (p->getType() == Pants && p->getLevel() <= this->getLevel()) {
		this->Head = p;
		return 1;
	}
	return 0;
}
Armor* Humanoid::getFeet() {
	return this->Feet;
}
int Humanoid::setFeet(Armor* b) {
	if (b->getType() == Boots && b->getLevel() <= this->getLevel()) {
		this->Head = b;
		return 1;
	}
	return 0;
}



int Humanoid::getStrength() {
	return this->Strength;
}
void Humanoid::setStrength(int s) {
	this->Strength = s;
}