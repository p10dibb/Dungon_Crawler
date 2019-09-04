#pragma once
#include "Weapon.h"

Weapon::Weapon() {
	Item();
	this->Damage = 0;
	this->Defense = 0;
	this->TwoHanded = false;
	this->Speed = 0;
	this->Level = 0;
	this->Range = 0;
}
Weapon::Weapon(int Dam, int Def, bool TH, int Sp, int Lvl, int Rng) {
	Item();
	this->Damage = Dam;
	this->Defense = Def;
	this->TwoHanded = TH;
	this->Speed = Sp;
	this->Level = Lvl;
	this->Range = Rng;
}
int Weapon::getDamage() {
	return this->Damage;
}
void Weapon::setDamage(int d) {
	if (d < 1) {
		d = 1;
	}
	this->Damage = d;
}
int Weapon::getDefense() {
	return this->Defense;

}
void Weapon::setDefense(int d) {
	if (d < 1) {
		d = 1;
	}
	this->Defense = d;
}
bool Weapon::getTwoHanded() {
	return this->TwoHanded;
}
void Weapon::setTwoHanded(bool t) {
	this->TwoHanded = t;
}
int Weapon::getSpeed() {
	return this->Speed;
}
void Weapon::setSpeed(int s) {
	if (s < 1) {
		s = 1;
	}
	this->Speed = s;
}
int Weapon::getLevel() {
	return this->Level;
}
void Weapon::setLevel(int l) {
	if (l < 1) {
		l = 1;
	}
	this->Level = l;
}
int Weapon::getRange() {
	return this->Range;
}
void Weapon::setRange(int r) {
	if (r < 1) {
		r = 1;
	}
	this->Range = r;
};


WeaponTypes Weapon:: getType() {
	return this->Type;
}
void Weapon::setType(WeaponTypes w) {
	this->Type = w;
}
