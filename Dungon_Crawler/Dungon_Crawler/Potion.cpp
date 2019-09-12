#include "Potion.h"

Potion::Potion() {
	Item();
	this->Tier = 1;
	this->Type = Water;
	this->BaseBooster = 0;
}
bool Potion::UseHealth(Humanoid *c){

	c->setHealth(c->getHealth() + this->Tier*this->BaseBooster);
	if (c->getHealth() > c->getMaxHealth()) {
		c->setHealth(c->getMaxHealth());
	}

	return true;
}
bool Potion::UseSpeedBooster(Humanoid *h) {
	h->setSpeed(h->getSpeed() + this->Tier*this->Type);
	return true;
}

bool Potion::UseStrengthBooster(Humanoid *p) {
	p->setStrength(p->getStrength() + this->Tier*this->Type);
	return true;
}


bool Potion::Use(Humanoid *c) {

	switch (this->Type)
	{

	case Water: cout << "You drank water it did nothing" << endl; break;
	case Health: this->UseHealth(c); break;
	case Speed:this->UseSpeedBooster(c); break;
	case Strength: this->UseStrengthBooster(c); break;
	default:
		break;
	}
	return true;
}


void Potion::DisplayDetails() {

}

PotionTypes Potion::getType() {
	return this->Type;
}
void Potion::setType(PotionTypes t) {
	this->Type = t;
}
int Potion::getTier() {
	return this->Tier;
}
void Potion::setTier(int t) {
	if (t < 1) {
		t = 1;
	}
	this->Tier = t;
}
int Potion::getBaseBooster() {
	return this->BaseBooster;
}
void Potion::setBaseBooster(int b) {
	this->BaseBooster = b;

}