#include "DamageTypes.h"


DamageType::DamageType() {
	this->Type = Basic;
	this->Chance = 100;
	this->Damage = 0;
}

DamageType::DamageType(int damage) {
	this->Type = Basic;
	this->Chance = 100;
	this->setDamage(damage);
}

DamageType::DamageType(Damagetype type, int chance, int damage) {
	this->Type = type;
	this->setchance(chance);
	this->setDamage(damage);
}

Damagetype DamageType::getType() {
	return this->Type;
}
void DamageType::setType(Damagetype t) {
	this->Type = t;

}

int DamageType::getChance() {
	return this->Chance;

}
void DamageType::setchance(int c) {
	if (c > 100) {
		c = 100;
	}
	else if (c < 0) {
		c = 0;
	}

	this->Chance = c;
}

int DamageType::getDamage() {
	return this->Damage;
}
void DamageType::setDamage(int d) {
	if (d < 0) {
		d = 0;
	}
	this->Damage = d;
}


void DamageType::DisplayDetails() {
	cout << "Type: ";
	switch (this->Type)
	{
	case Fire: cout << "Burning"; break;
	case Stabbing: cout << "Stabbing"; break;
	case Blunt: cout << "Blunt"; break;
	case Basic: cout << "Normal"; break;
	default:
		break;

	}
	cout << endl;

	cout << "Chance: " << this->Chance << endl;
	cout << "Damage: " << this->Damage << endl;
}